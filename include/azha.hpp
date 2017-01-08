#ifndef __AZHA_H__
#define __AZHA_H__

#include "OAuth.hpp"

namespace azha {
	class TwitterClient {
	public:
		struct MemoryStruct {
			char *memory;
			size_t size;
		};
		
		TwitterClient(std::string _consumer_key, std::string _consumer_secret);
		TwitterClient(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret);
		
		void request_token(const std::function<void(const int code, const std::string &ret)>& callback);
		
		void access_token(const std::function<void(const int code, const std::string &ret)>& callback);
		
		void request(Parameters::ITwitterParameters &parameters, const std::function<void(const int code, const std::string &ret)>& callback);
	private:
		OAuth* _oauth;
		
		static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
	};
}

#endif //__AZHA_H__
