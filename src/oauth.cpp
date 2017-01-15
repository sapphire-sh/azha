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

	std::string OAuth::header_string(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		oauth_nonce(generate_nonce());
		oauth_timestamp(generate_timestamp());
		oauth_signature(calculate_signature(method, url, parameters));

		auto curl = curl_easy_init();

		std::stringstream ss;

		ss << "OAuth ";

		for(auto&& iter : this->parameters) {
			auto found = iter.first.find_last_of("_");
			auto token = iter.first.substr(found + 1);
			if(token != "secret") {
				ss << iter.first << "=\"" << curl_easy_escape(curl, iter.second.c_str(), static_cast<int>(iter.second.size())) << "\", ";
			}
		}
		for(auto&& iter : parameters) {
			auto found = iter.first.find_first_of("_");
			auto token = iter.first.substr(0, found);
			if(token == "oauth") {
				ss << iter.first << "=\"" << curl_easy_escape(curl, iter.second.c_str(), static_cast<int>(iter.second.size())) << "\", ";
			}
		}

		auto h_str = ss.str();
		h_str.pop_back();
		h_str.pop_back();

		return h_str;
	}

	std::string OAuth::generate_nonce() {
		static const char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

		std::stringstream ss;

		srand(static_cast<unsigned int>(generate_timestamp()));
		for (auto i = 0; i < 32; ++i) {
			ss << characters[rand() % (sizeof(characters) - 1)];
		}

		return ss.str();
	}

	uint64_t OAuth::generate_timestamp() {
		return std::time(nullptr);
	}

	std::string OAuth::calculate_signature(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		auto key = signing_key();
		auto data = signature_base_string(method, url, parameters);

		unsigned char* result;
		unsigned int len = 20;

		result = static_cast<unsigned char*>(malloc(sizeof(char) * len));

		HMAC_CTX ctx;
		HMAC_CTX_init(&ctx);

		HMAC_Init_ex(&ctx, key.c_str(), static_cast<int>(key.length()), EVP_sha1(), nullptr);
		HMAC_Update(&ctx, reinterpret_cast<const unsigned char*>(data.c_str()), static_cast<int>(data.length()));
		HMAC_Final(&ctx, result, &len);
		HMAC_CTX_cleanup(&ctx);

		auto signature = base64_encode(result, len);
		free(result);

		return signature;
	}

	std::string OAuth::parameter_string(const parameters::RequestParams &parameters) {
		CURL* curl = curl_easy_init();

		std::map<std::string, std::string> p;

		for(auto&& iter : this->parameters) {
			auto found = iter.first.find_last_of("_");
			auto k = iter.first.substr(found + 1);
			if(k != "signature" && k != "secret") {
				p[iter.first] = iter.second;
			}
		}
		for(auto&& iter : parameters) {
			p[iter.first] = iter.second;
		}

		std::stringstream ss;

		for(auto&& iter : p) {
			ss << iter.first << "=" << curl_easy_escape(curl, iter.second.c_str(), static_cast<int>(iter.second.size())) << "&";
		}

		auto parameter_string = ss.str();
		parameter_string.pop_back();

		return parameter_string;
	}

	std::string OAuth::signature_base_string(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		auto curl = curl_easy_init();

		std::stringstream ss;

		ss << (method == parameters::RequestMethod::POST ? "POST&" : "GET&");
		ss << curl_easy_escape(curl, url.c_str(), static_cast<int>(url.size())) << "&";

		std::string p_str = parameter_string(parameters);
		ss << curl_easy_escape(curl, p_str.c_str(), static_cast<int>(p_str.size()));

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
