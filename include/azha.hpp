#include "client.hpp"

namespace azha {
	typedef std::function<void(const int code, const std::string ret)> CallbackFunc;
	typedef std::unordered_map<std::string, std::string> RequestParams;
	
	class azha {
	public:
		azha(std::string _consumer_key, std::string _consumer_secret) {
			_client = new Client(_consumer_key, _consumer_secret);
		}
		
		~azha() {
			delete _client;
		}
		
		Client * const client() {
			return _client;
		}
	private:
		Client *_client;
	};
}
