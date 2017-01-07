#ifndef __AZHA_H__
#define __AZHA_H__

#include "OAuth.hpp"

namespace azha {
	class TwitterClient {
	public:
		TwitterClient(std::string _consumer_key, std::string _consumer_secret);
		TwitterClient(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret);
		
		void sendRequest(Parameters::RequestType requestType,\
						 Parameters::ITwitterParameters &parameters,\
						 const std::function<void(const int code, const std::string &ret)>& callback);
		
		void GET(Parameters::ITwitterParameters &parameters,\
				 const std::function<void(const int code, const std::string &ret)>& callback);
		
		void POST(Parameters::ITwitterParameters &parameters,\
				  const std::function<void(const int code, const std::string &ret)>& callback);
	private:
		OAuth* oauth;
	};
}

#endif //__AZHA_H__
