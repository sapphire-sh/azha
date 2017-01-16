#ifndef __RESPONSE_ERRORS_H__
#define __RESPONSE_ERRORS_H__

#include "response.interface.hpp"

namespace azha {
	namespace response {
		class Error : public ITwitterResponse {
		public:
			Error(const rapidjson::Value &value) {
				code = std::unique_ptr<uint64_t>(new uint64_t(value["code"].GetUint64()));
				message = std::unique_ptr<std::string>(new std::string(value["message"].GetString()));
			}
			std::unique_ptr<uint64_t> code;
			std::unique_ptr<std::string> message;
		};
		
		class Errors : public ITwitterResponse {
		public:
			Errors(const rapidjson::Value &value) {
				errors = std::unique_ptr<std::vector<Error>>(new std::vector<Error>());
				errors.get()->push_back(Error(value["errors"]));
			}
			std::unique_ptr<std::vector<Error>> errors;
		};
	}
}


#endif // __RESPONSE_ERRORS_H__
