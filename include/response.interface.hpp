#ifndef __RESPONSE_INTERFACE_H__
#define __RESPONSE_INTERFACE_H__

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include <rapidjson/document.h>

namespace azha {
	namespace response {
		typedef std::unordered_map<std::string, std::string> ResponseData;

		class ITwitterResponse {
		public:
			ResponseData data;
		};
	}
}

#endif // __RESPONSE_INTERFACE_H__
