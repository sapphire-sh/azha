#include <iostream>
#include <sstream>

#include <curl/curl.h>

#include "azha.hpp"

namespace azha {
	TwitterClient::TwitterClient(std::string _consumer_key, std::string _consumer_secret) : TwitterClient(_consumer_key, _consumer_secret, "", "") {}
	TwitterClient::TwitterClient(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret) {
		oauth = new OAuth(_consumer_key, _consumer_secret, _access_token, _access_token_secret);
	}
	
	void TwitterClient::sendRequest(Parameters::RequestType requestType, Parameters::ITwitterParameters &parameters, const std::function<void (const int, const std::string &)>& callback) {
		CURL* curl;
		CURLcode res;
		
		curl = curl_easy_init();
		
		if(curl) {
			std::stringstream ss;
			
			ss << "Authorization: " << oauth->header_string(parameters);
			
			struct curl_slist *chunk = NULL;
			chunk = curl_slist_append(chunk, ss.str().c_str());
			
			res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			
			curl_easy_setopt(curl, CURLOPT_URL, parameters.url.c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK) {
				std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
			}
			
			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
		}
	}
	
	void TwitterClient::GET(Parameters::ITwitterParameters &parameters, const std::function<void (const int, const std::string &)>& callback) {
		sendRequest(Parameters::RequestType::GET, parameters, callback);
	}
	
	void TwitterClient::POST(Parameters::ITwitterParameters &parameters, const std::function<void (const int, const std::string &)> &callback) {
		sendRequest(Parameters::RequestType::POST, parameters, callback);
	}

}
