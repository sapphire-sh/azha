#include <iostream>
#include <sstream>
#include <cstdlib>

#include <curl/curl.h>

#include "azha.hpp"

namespace azha {
	TwitterClient::TwitterClient(std::string _consumer_key, std::string _consumer_secret) : TwitterClient(_consumer_key, _consumer_secret, "", "") {}
	TwitterClient::TwitterClient(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret) {
		_oauth = new OAuth(_consumer_key, _consumer_secret, _access_token, _access_token_secret);
	}
	
	void TwitterClient::request_token(const std::function<void(const int code, const std::string &ret)>& callback) {
		Parameters::OAuth::RequestTokenParameters p;
		request(p, callback);
	}
	
	void TwitterClient::access_token(const std::function<void(const int code, const std::string &ret)>& callback) {
		
	}
	
	void TwitterClient::request(Parameters::ITwitterParameters &parameters, const std::function<void (const int, const std::string &)>& callback) {
		CURL* curl;
		CURLcode res;
		
		struct MemoryStruct data;
		
		data.memory = (char*)malloc(1);
		data.size = 0;
		
		curl_global_init(CURL_GLOBAL_ALL);
		
		curl = curl_easy_init();
		
		if(curl) {
			std::stringstream ss;
			
			ss << "Authorization: " << _oauth->header_string(parameters);
			
			struct curl_slist *chunk = nullptr;
			chunk = curl_slist_append(chunk, ss.str().c_str());
			
			res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			
			curl_easy_setopt(curl, CURLOPT_URL, parameters.url().c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			
			if(parameters.request_type() == Parameters::RequestType::POST) {
				std::unordered_map<std::string, std::string> p;
				std::string parameter_string = parameters.parameter_string(p);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameter_string.c_str());
			}
			
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
			
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK) {
				std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
			}
			else {
				printf("%lu bytes retrieved\n", (long)data.size);
			}
			
			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
			
			free(data.memory);
			
			curl_global_cleanup();
		}
	}
	
	size_t TwitterClient::write_callback(void *contents, size_t size, size_t nmemb, void *userp)
	{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
		
  mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
	  /* out of memory! */
	  printf("not enough memory (realloc returned NULL)\n");
	  return 0;
  }
		
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
		
  return realsize;
	}
}
