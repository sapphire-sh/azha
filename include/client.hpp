#ifndef __AZHA_H__
#define __AZHA_H__

#include <unordered_map>

#include "oauth.hpp"
#include "parameters.hpp"

namespace azha {
	typedef std::function<void(const int code, const std::string ret)> CallbackFunc;
	
	class Client {
	public:
		struct MemoryStruct {
			char *memory;
			size_t size;
		};
		
		Client(std::string _consumer_key, std::string _consumer_secret);
		Client(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret);
		
		~Client() {
			delete _oauth;
		}
		
		void request_token(const CallbackFunc &callback);
		void access_token(const CallbackFunc &callback);
		
		void request(const parameters::ITwitterParameters &parameters, const CallbackFunc &callback);
		void request(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters, const CallbackFunc &callback);
	private:
		OAuth *_oauth;
		
		static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
	};
}

#endif //__AZHA_H__
