#include "client.hpp"

namespace azha {
	typedef std::unordered_map<std::string, std::string> RequestParams;
	typedef std::function<void(const int code, const RequestParams response)> CallbackFunc;
}
