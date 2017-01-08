#include <sstream>

#include <curl/curl.h>

#include "TwitterParameters.hpp"

namespace azha {
	namespace Parameters {
		std::string ITwitterParameters::parameter_string(std::unordered_map<std::string, std::string>& parameters) {
			CURL* curl = curl_easy_init();
			
			std::map<std::string, std::string> p;
			
			for(auto iter = parameters.begin(); iter != parameters.end(); ++iter) {
				auto f = iter->first.find_last_of("_");
				std::string k = iter->first.substr(f + 1);
				if(k != "signature" && k != "secret") {
					p[iter->first] = iter->second;
				}
			}
			for(auto iter = queries.begin(); iter != queries.end(); ++iter) {
				p[iter->first] = iter->second;
			}
			
			std::stringstream ss;
			
			for(auto iter = p.begin(); iter != p.end(); ++iter) {
				ss << iter->first << "=" << curl_easy_escape(curl, iter->second.c_str(), iter->second.size()) << "&";
			}
			
			std::string parameter_string = ss.str();
			parameter_string.pop_back();
			
			return parameter_string;
		};
	}
}
