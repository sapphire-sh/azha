#include <iostream>
#include <ctime>
#include <sstream>

#include <curl/curl.h>
#include <openssl/hmac.h>

#include "base64.hpp"
#include "OAuth.hpp"

namespace azha {
	OAuth::OAuth(std::string _consumer_key, std::string _consumer_secret) : OAuth(_consumer_key, _consumer_secret, "", "") {}
	OAuth::OAuth(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret) {
		oauth_consumer_key(_consumer_key);
		oauth_consumer_secret(_consumer_secret);
		if(_access_token != "" && _access_token_secret != "") {
			oauth_token(_access_token);
			oauth_token_secret(_access_token_secret);
		}
		
		oauth_callback("oob");
		oauth_nonce(generate_nonce());
		oauth_signature_method("HMAC-SHA1");
		oauth_timestamp(generate_timestamp());
		oauth_version("1.0");
	}
	
	const std::string OAuth::header_string(Parameters::ITwitterParameters& parameters) {
		oauth_nonce(generate_nonce());
		oauth_timestamp(generate_timestamp());
		oauth_signature(calculate_signature(parameters));
		
		CURL* curl = curl_easy_init();
		
		std::stringstream ss;
		
		ss << "OAuth ";
		
		for(auto iter = this->parameters.begin(); iter != this->parameters.end(); ++iter) {
			auto f = iter->first.find_last_of("_");
			std::string k = iter->first.substr(f + 1);
			if(k != "secret") {
			ss << iter->first << "=\"" << curl_easy_escape(curl, iter->second.c_str(), iter->second.size()) << "\", ";
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
	
	const std::string OAuth::calculate_signature(Parameters::ITwitterParameters& parameters) {
		std::string key_str = signing_key();
		char key[key_str.size() + 1];
		strcpy(key, key_str.c_str());
		
		std::string data_str = signature_base_string(parameters);
		char data[data_str.size() + 1];
		strcpy(data, data_str.c_str());
		
		unsigned char* result;
		unsigned int len = 20;
		
		result = (unsigned char*)malloc(sizeof(char) * len);
		
		HMAC_CTX ctx;
		HMAC_CTX_init(&ctx);
		
		HMAC_Init_ex(&ctx, key, strlen(key), EVP_sha1(), nullptr);
		HMAC_Update(&ctx, (unsigned char*)&data, strlen(data));
		HMAC_Final(&ctx, result, &len);
		HMAC_CTX_cleanup(&ctx);
		
		std::string signature = base64_encode(result, len);
		
		free(result);
		
		return signature;
	}
	
	const std::string OAuth::parameter_string(Parameters::ITwitterParameters& parameters) {
		return parameters.parameter_string(this->parameters);
	}
	
	const std::string OAuth::signature_base_string(Parameters::ITwitterParameters& parameters) {
		CURL* curl = curl_easy_init();
		
		std::stringstream ss;
		
		ss << (parameters.request_type() == Parameters::RequestType::POST ? "POST&" : "GET&");
		std::string url = parameters.url();
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
