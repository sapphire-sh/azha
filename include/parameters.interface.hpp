#ifndef __PARAMETERS_INTERFACE_H__
#define __PARAMETERS_INTERFACE_H__

#include <unordered_map>
#include <type_traits>
#include <string>
#include <cstdio>

#define METHOD(x)\
	const RequestMethod &request_method() const {\
		static const RequestMethod _request_method = x;\
		return _request_method;\
	}

#define URL(x)\
	const std::string &request_url() const {\
		static const std::string _url = x;\
		return _url;\
	}

#if WIN32
#define POSITIONAL_SPRINTF(buffer, size, format, ...) _sprintf_p(buffer, size, format, __VA_ARGS__)
#else
#define POSITIONAL_SPRINTF(buffer, size, format, ...) sprintf(buffer, format, __VA_ARGS__)
#endif

#define URL_FORMAT(gen)\
private:\
	mutable std::string _url;\
public:\
	const std::string &request_url() const override {\
		if (_url.length() == 0) {\
			std::ostringstream os;\
			os << gen;\
			_url.assign(os.str());\
		}\
		return _url;\
	}

template<typename param_type>
using param_arg_type = typename std::conditional<std::is_arithmetic<param_type>::value, param_type, typename std::add_lvalue_reference<typename std::add_const<param_type>::type>::type>::type;

template<typename param_type>
using param_return_type = typename std::conditional<std::is_arithmetic<param_type>::value, param_type, typename std::add_lvalue_reference<typename std::add_const<param_type>::type>::type>::type;

template<typename ret>
param_return_type<ret> from_string(const std::string &val) = delete;

template<>
inline double from_string<double>(const std::string &val) {
	return std::stod(val);
}

template<>
inline bool from_string<bool>(const std::string &val) {
	return val.compare("true") == 0;
}

template<>
inline uint64_t from_string<uint64_t>(const std::string &val) {
	return std::stoull(val);
}

template<>
inline const std::string &from_string<std::string>(const std::string &val) {
	return val;
}

namespace std
{
	inline std::string to_string(bool value) {
		static const std::string t("true"), f("false");
		return value ? t : f;
	}

	inline std::string to_string(const std::string &val)
	{
		return val;
	}
}

#define INIT(param_type_name)\
	using this_ref_type = param_type_name&;\
	virtual ~param_type_name() {}

#define PARAMETER(param_type, param_name)\
  PARAMETER_ALIAS(param_type, param_name, param_name)

#define PARAMETER_ALIAS(param_type, param_name, param_alias)\
	this_ref_type param_name(param_arg_type<param_type> _##param_name) {\
		parameters[#param_alias] = std::move(std::to_string(_##param_name));\
		return *this;\
	}\
	bool is_set_##param_name() const {\
		return parameters.find(#param_alias) != parameters.end();\
	}\
	param_return_type<param_type> param_name() const {\
		return from_string<param_type>(parameters.at(#param_alias)); \
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
			virtual ~ITwitterParameters() {}
			virtual const RequestMethod &request_method() const = 0;
			virtual const std::string &request_url() const = 0;

			RequestParams parameters;
		};
	}
}

#endif // __PARAMETERS_INTERFACE_H__
