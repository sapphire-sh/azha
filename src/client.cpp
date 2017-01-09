#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unordered_map>

#include <curl/curl.h>

#include "client.hpp"
#include "parameters.hpp"

namespace azha {
	void Client::consumer_key(const std::string &_consumer_key, const std::string &_consumer_secret) {
		_oauth->oauth_consumer_key(_consumer_key);
		_oauth->oauth_consumer_secret(_consumer_secret);
	}
	
	void Client::access_token(const std::string &_access_token, const std::string &_access_token_secret) {
		_oauth->oauth_token(_access_token);
		_oauth->oauth_token_secret(_access_token_secret);
	}
	
	void Client::request(const parameters::ITwitterParameters &parameters, const CallbackFunc &callback) {
		request(parameters.request_method(), parameters.url(), parameters.parameters, callback);
	}
	
	void Client::request(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters, const CallbackFunc &callback) {
		CURL* curl;
		CURLcode res;
		
		struct MemoryStruct data;
		
		data.memory = (char*)malloc(1);
		data.size = 0;
		
		curl_global_init(CURL_GLOBAL_ALL);
		
		curl = curl_easy_init();
		
		if(curl) {
			std::stringstream ss;
			
			ss << "Authorization: " << _oauth->header_string(method, url, parameters);
			
			struct curl_slist *chunk = nullptr;
			chunk = curl_slist_append(chunk, ss.str().c_str());
			
			res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			
			if(method == parameters::RequestMethod::POST) {
				std::unordered_map<std::string, std::string> p;
				std::string parameter_string = _oauth->parameter_string(p);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameter_string.c_str());
			}
			
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&data);
			
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK) {
				std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
				callback(-1, parameters::RequestParams());
			}
			else {
				std::string response(data.memory);
				
				char *content_type;
				curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);
				
				if(callback != nullptr) {
					if(std::string(content_type) == "text/html;charset=utf-8") {
						callback(200, parse_query_string(response));
					}
					else {
						callback(200, parameters::RequestParams());
					}
				}
			}
			
			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
			
			free(data.memory);
		}
		else {
			if(callback != nullptr) {
				callback(-1, parameters::RequestParams());
			}
		}
		
		curl_global_cleanup();
	}
	
	std::unordered_map<std::string, std::string> Client::parse_query_string(const std::string &query_string) {
		std::string key, value;
		std::stringstream ss;
		ss << query_string;
		std::unordered_map<std::string, std::string> result;
		
		while(getline(ss, key, '=') && getline(ss, value, '&')) {
			result[key] = value;
		}
		
		return result;
	}
	
	size_t Client::write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
		size_t realsize = size * nmemb;
		struct MemoryStruct *mem = (struct MemoryStruct *)userp;
		
		mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
		if(mem->memory == NULL) {
			printf("not enough memory (realloc returned NULL)\n");
			return 0;
		}
		
		memcpy(&(mem->memory[mem->size]), contents, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
		
		return realsize;
	}
}
