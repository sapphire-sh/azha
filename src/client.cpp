#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <future>

#include <curl/curl.h>

#include "client.hpp"

namespace azha {
	Client::Client()
	  : _oauth(new OAuth()) {
		curl_global_init(CURL_GLOBAL_ALL);
	}

	Client::~Client() {
		curl_global_cleanup();
	}
	
	void Client::consumer_key(const std::string &_consumer_key, const std::string &_consumer_secret) {
		_oauth->oauth_consumer_key(_consumer_key);
		_oauth->oauth_consumer_secret(_consumer_secret);
	}
	
	void Client::access_token(const std::string &_access_token, const std::string &_access_token_secret) {
		_oauth->oauth_token(_access_token);
		_oauth->oauth_token_secret(_access_token_secret);
	}
	
	std::future<Client::ResultType> Client::request(const parameters::ITwitterParameters &parameters) {
		return request(parameters.request_method(), parameters.url(), parameters.parameters);
	}
	
	std::future<Client::ResultType> Client::request(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) {
		return std::async(std::launch::async, &Client::request_internal, this, method, url, parameters);
	}

	Client::ResultType Client::request_internal(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters) const
	{
		CURL* curl;
		CURLcode res;

		struct MemoryStruct data;

		data.memory = reinterpret_cast<char*>(malloc(1));
		data.size = 0;
		
		curl = curl_easy_init();
		
		if(curl) {
			std::stringstream ss;
			
			ss << "Authorization: " << _oauth->header_string(method, url, parameters);
			
			struct curl_slist *chunk = nullptr;
			chunk = curl_slist_append(chunk, ss.str().c_str());
			
			res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			
			std::string parameter_string;
			if(method == parameters::RequestMethod::POST) {
				parameter_string = Client::parameter_string(parameters);
				std::cout << parameter_string << "\n";
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameter_string.c_str());
			}
			
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&data);
			
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK) {
				ss.str("curl_easy_perform() failed: ");
				ss << curl_easy_strerror(res);
				throw new RequestFailedException(ss.str());
			}
			else {
				std::string response(data.memory);
				std::cout << response << "\n";
				
				char *content_type;
				curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

				if(std::string(content_type) == "text/html;charset=utf-8") {
					return parse_query_string(response);
				}
				else {
					return parameters::RequestParams();
				}
			}
			
			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
			
			free(data.memory);
		}
		else {
			throw new RequestFailedException("curl init failed");
		}
	}

	std::unordered_map<std::string, std::string> &&Client::parse_query_string(const std::string &query_string) {
		std::string key, value;
		std::stringstream ss;
		ss << query_string;
		std::unordered_map<std::string, std::string> result;

		while(getline(ss, key, '=') && getline(ss, value, '&')) {
			result[key] = value;
		}

		return std::move(result);
	}

	std::string Client::parameter_string(const parameters::RequestParams &parameters) {
		auto curl = curl_easy_init();

		std::unordered_map<std::string, std::string> p;

		for(const auto& iter : parameters) {
			p[iter.first] = iter.second;
		}

		std::stringstream ss;

		for(const auto& iter : p) {
			ss << iter.first << "=" << curl_easy_escape(curl, iter.second.c_str(), static_cast<int>(iter.second.size())) << "&";
		}

		auto parameter_string = ss.str();
		parameter_string.pop_back();

		return parameter_string;
	}
	
	size_t Client::write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
		auto realsize = size * nmemb;
		auto mem = static_cast<struct MemoryStruct *>(userp);

		mem->memory = reinterpret_cast<char *>(realloc(mem->memory, mem->size + realsize + 1));
		if(mem->memory == nullptr) {
			printf("not enough memory (realloc returned NULL)\n");
			return 0;
		}

		memcpy(&(mem->memory[mem->size]), contents, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;

		return realsize;
	}
}
