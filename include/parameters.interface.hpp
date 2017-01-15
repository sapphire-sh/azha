#ifndef __PARAMETERS_INTERFACE_H__
#define __PARAMETERS_INTERFACE_H__

#include <sstream>
#include <string>
#include <unordered_map>

#define METHOD(x)\
	const RequestMethod &request_method() const {\
		static const RequestMethod _request_method = x;\
		return _request_method;\
	}

#define URL(x)\
	const std::string &url() const {\
		static const std::string _url = x;\
		return _url;\
	}

#define PARAMETER_BOOL(param_type, param_name)\
	param_type& param_name(const bool &_param_name) {\
		parameters[#param_name] = _param_name ? "true" : "false";\
		return *this;\
	}\
	const bool param_name() {\
		return (parameters[#param_name] == "true");\
	}

#define PARAMETER_STRING(param_type, param_name)\
	param_type& param_name(const std::string &_param_name) {\
		parameters[#param_name] = _param_name;\
		return *this;\
	}\
	const std::string& param_name() {\
		return parameters[#param_name];\
	}

#define PARAMETER_UINT64(param_type, param_name)\
	param_type& param_name(const uint64_t &_param_name) {\
		parameters[#param_name] = _param_name;\
		return *this;\
	}\
	const uint64_t param_name() {\
		return std::stoull(parameters[#param_name]);\
	}

#define PARAMETER_DOUBLE(param_type, param_name)\
	param_type& param_name(const double &_param_name) {\
		parameters[#param_name] = _param_name;\
		return *this;\
	}\
	const double param_name() {\
		return std::stod(parameters[#param_name]);\
	}

namespace azha {
	namespace parameters {
		typedef std::unordered_map<std::string, std::string> RequestParams;

		enum class RequestMethod {
			GET,
			POST
		};

		class ITwitterParameters {
		public:
			virtual const RequestMethod &request_method() const = 0;
			virtual const std::string &url() const = 0;

			RequestParams parameters;
		};
	}
}

#endif // __PARAMETERS_INTERFACE_H__
