#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <functional>

#include "TwitterParameters.hpp"

namespace azha {
	namespace Request {
		enum class RequestType {
			GET,
			POST
		};
		
		void sendRequest(RequestType requestType,\
						 const std::string &endpoint,\
						 const Parameters::ITwitterParameters &parameters,\
						 const std::function<void(const int code, const std::string &ret)>);
	}
}

#endif // __REQUEST_H__
