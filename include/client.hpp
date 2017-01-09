#ifndef __AZHA_H__
#define __AZHA_H__

#include <unordered_map>

#include "oauth.hpp"
#include "parameters.hpp"

namespace azha {
	typedef std::function<void(const int code, const std::unordered_map<std::string, std::string> ret)> CallbackFunc;
	
	class Client {
	public:
		struct MemoryStruct {
			char *memory;
			size_t size;
		};
		
		static Client& instance() {
			static Client _instance;
			return _instance;
		}
		
		void consumer_key(const std::string &_consumer_key, const std::string &_consumer_secret);
		void access_token(const std::string &_access_token, const std::string &_access_token_secret);
		
		~Client() {
			delete _oauth;
		}
		
		void request(const parameters::ITwitterParameters &parameters, const CallbackFunc &callback);
		void request(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters, const CallbackFunc &callback);
	private:
		Client() {
			_oauth = new OAuth();
		}
		
		OAuth *_oauth;
		
		static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
		
		static std::unordered_map<std::string, std::string> parse_query_string(const std::string &query_string);
	};
}

#endif //__AZHA_H__
