#include <iostream>
#include <sstream>
#include <cstdlib>

#include <curl/curl.h>

#include "client.hpp"
#include "parameters.hpp"

namespace azha {
	Client::Client(std::string _consumer_key, std::string _consumer_secret) : Client(_consumer_key, _consumer_secret, "", "") {}
	Client::Client(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret) {
		_oauth = new OAuth(_consumer_key, _consumer_secret, _access_token, _access_token_secret);
	}
	
	void Client::request_token(const CallbackFunc &callback) {
		parameters::OAuth::RequestTokenParameters parameters;
		request(parameters, callback);
	}
	
	void Client::access_token(const CallbackFunc &callback) {
		
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
				callback(-1, "");
			}
			else {
				std::string response(data.memory);
				callback(200, response);
			}
			
			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
			
			free(data.memory);
			
			curl_global_cleanup();
		}
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
