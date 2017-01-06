#include <iostream>
#include <curl/curl.h>

#include "Request.hpp"

void azha::Request::sendRequest(RequestType requestType, const std::string &endpoint, const Parameters::ITwitterParameters &parameters, const std::function<void (const int, const std::string &)>) {
	CURL* curl;
	CURLcode res;
	
	curl = curl_easy_init();
	
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
		
		res = curl_easy_perform(curl);
		
		if(res != CURLE_OK) {
			std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
		}
		
		curl_easy_cleanup(curl);
	}
}
