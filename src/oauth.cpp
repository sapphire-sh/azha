#include <ctime>
#include <map>
#include <sstream>

#include <curl/curl.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include "base64.hpp"
#include "oauth.hpp"
#include <memory>

#if OPENSSL_VERSION_NUMBER < 0x10100000L
	#define HMAC_CTX_WRAP HMAC_CTX
	#define HMAC_CTX_WRAP_INIT(ctx) HMAC_CTX_init(&ctx);
	#define HMAC_CTX_WRAP_PTR(ctx) &ctx
	#define HMAC_CTX_WRAP_CLEANUP(ctx) HMAC_CTX_cleanup(&ctx)
#else
	#define HMAC_CTX_WRAP HMAC_CTX *
	#define HMAC_CTX_WRAP_INIT(ctx) ctx = HMAC_CTX_new();
	#define HMAC_CTX_WRAP_PTR(ctx) ctx
	#define HMAC_CTX_WRAP_CLEANUP(ctx) HMAC_CTX_free(ctx)
#endif

namespace azha {
	OAuth::OAuth() {
		oauth_nonce(generate_nonce());
		oauth_signature_method("HMAC-SHA1");
		oauth_timestamp(generate_timestamp());
		oauth_version("1.0");
	}
	
	const std::string OAuth::header_string(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		oauth_nonce(generate_nonce());
		oauth_timestamp(generate_timestamp());
		oauth_signature(calculate_signature(method, url, parameters));
		
		CURL* curl = curl_easy_init();
		
		std::stringstream ss;
		
		ss << "OAuth ";
		
		for(auto&& iter : this->parameters) {
			auto found = iter.first.find_last_of("_");
			std::string token = iter.first.substr(found + 1);
			if(token != "secret") {
			ss << iter.first << "=\"" << curl_easy_escape(curl, iter.second.c_str(), iter.second.size()) << "\", ";
			}
		}
		for(auto&& iter : parameters) {
			auto found = iter.first.find_first_of("_");
			std::string token = iter.first.substr(0, found);
			if(token == "oauth") {
				ss << iter.first << "=\"" << curl_easy_escape(curl, iter.second.c_str(), iter.second.size()) << "\", ";
			}
		}
		
		std::string h_str = ss.str();
		h_str.pop_back();
		h_str.pop_back();
		
		return h_str;
	}
	
	const std::string OAuth::generate_nonce() {
		static const char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		std::stringstream ss;
		
		srand(generate_timestamp());
		for (int i = 0; i < 32; ++i) {
			ss << characters[rand() % (sizeof(characters) - 1)];
		}
		
		return ss.str();
	}
	
	const uint64_t OAuth::generate_timestamp() {
		return std::time(0);
	}
	
	const std::string OAuth::calculate_signature(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		std::string key = signing_key();
		std::string data = signature_base_string(method, url, parameters);
		unsigned char* result;
		unsigned int len = 20;

		result = static_cast<unsigned char*>(malloc(sizeof(char) * len));

		HMAC_CTX_WRAP ctx;
		HMAC_CTX_WRAP_INIT(ctx);

		HMAC_Init_ex(HMAC_CTX_WRAP_PTR(ctx), key.c_str(), static_cast<int>(key.length()), EVP_sha1(), nullptr);
		HMAC_Update(HMAC_CTX_WRAP_PTR(ctx), reinterpret_cast<const unsigned char*>(data.c_str()), static_cast<int>(data.length()));
		HMAC_Final(HMAC_CTX_WRAP_PTR(ctx), result, &len);
		HMAC_CTX_WRAP_CLEANUP(ctx);

		auto signature = base64_encode(result, len);

		free(result);
		
		return signature;
	}
	
	const std::string OAuth::parameter_string(const parameters::RequestParams &parameters) {
		CURL* curl = curl_easy_init();
		
		std::map<std::string, std::string> p;
		
		for(auto&& iter : this->parameters) {
			auto found = iter.first.find_last_of("_");
			std::string k = iter.first.substr(found + 1);
			if(k != "signature" && k != "secret") {
				p[iter.first] = iter.second;
			}
		}
		for(auto&& iter : parameters) {
			p[iter.first] = iter.second;
		}
		
		std::stringstream ss;
		
		for(auto&& iter : p) {
			ss << iter.first << "=" << curl_easy_escape(curl, iter.second.c_str(), iter.second.size()) << "&";
		}
		
		std::string parameter_string = ss.str();
		parameter_string.pop_back();
		
		return parameter_string;
	}
	
	const std::string OAuth::signature_base_string(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		CURL* curl = curl_easy_init();
		
		std::stringstream ss;
		
		ss << (method == parameters::RequestMethod::POST ? "POST&" : "GET&");
		ss << curl_easy_escape(curl, url.c_str(), url.size()) << "&";
		
		std::string p_str = parameter_string(parameters);
		ss << curl_easy_escape(curl, p_str.c_str(), p_str.size());
		
		return ss.str();
	}
	
	const std::string OAuth::signing_key() {
		std::stringstream ss;
		
		ss << oauth_consumer_secret() << "&";
		if(oauth_token_secret() != "") {
			ss << oauth_token_secret();
		}
		
		return ss.str();
	}
}
