#ifndef __AZHA_H__
#define __AZHA_H__

#include <unordered_map>
#include <future>
#include <exception>
#include <memory>

#include "oauth.hpp"
#include "parameters.hpp"

namespace azha {
	class RequestFailedException : public std::exception {
	public:
		RequestFailedException(const std::string &_reason) : reason(_reason) {}
		std::string reason;
		const char* what() const noexcept {
			return reason.c_str();
		}
	};
	
	class Client {
	public:
		using ResultType = std::unordered_map<std::string, std::string>;

		struct MemoryStruct {
			char *memory;
			size_t size;
		};
		
		Client();
		~Client();
		
		void consumer_key(const std::string &_consumer_key, const std::string &_consumer_secret);
		void access_token(const std::string &_access_token, const std::string &_access_token_secret);
		
		std::future<ResultType> request(const parameters::ITwitterParameters &parameters);
		std::future<ResultType> request(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters);
	private:
		std::unique_ptr<OAuth> _oauth;
		
		static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
		
		static const std::unordered_map<std::string, std::string> parse_query_string(const std::string &query_string);
		static const std::string parameter_string(const parameters::RequestParams &parameters);
		ResultType request_internal(const parameters::RequestMethod &method, const std::string &url, const parameters::RequestParams &parameters);
	};
}

#endif //__AZHA_H__
