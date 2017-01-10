#ifndef __PARAMETERS_OAUTH_H__
#define __PARAMETERS_OAUTH_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace OAuth {
			class RequestTokenParameters : public ITwitterParameters {
			public:
				const RequestMethod &request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string &url() const {
					static const std::string _url = "https://api.twitter.com/oauth/request_token";
					return _url;
				}
				
				RequestTokenParameters& oauth_callback(const std::string &_oauth_callback) {
					parameters["oauth_callback"] = _oauth_callback;
					return *this;
				}
				RequestTokenParameters& x_auth_access_type(const std::string &_x_auth_access_type) {
					parameters["x_auth_access_type"] = _x_auth_access_type;
					return *this;
				}
				
				const std::string& oauth_callback() {
					return parameters["oauth_callback"];
				}
				const std::string& x_auth_access_type() {
					return parameters["x_auth_access_type"];
				}
			};
			
			class AccessTokenParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "https://api.twitter.com/oauth/access_token";
					return _url;
				}
				
				AccessTokenParameters& x_auth_password(const std::string &_x_auth_password) {
					parameters["x_auth_password"] = _x_auth_password;
					return *this;
				}
				AccessTokenParameters& x_auth_username(const std::string &_x_auth_username) {
					parameters["x_auth_username"] = _x_auth_username;
					return *this;
				}
				AccessTokenParameters& x_auth_mode(const std::string &_x_auth_mode) {
					parameters["x_auth_mode"] = _x_auth_mode;
					return *this;
				}
				AccessTokenParameters& oauth_verifier(const std::string &_oauth_verifier) {
					parameters["oauth_verifier"] = _oauth_verifier;
					return *this;
				}
				
				const std::string& x_auth_password() {
					return parameters["x_auth_password"];
				}
				const std::string& x_auth_username() {
					return parameters["x_auth_username"];
				}
				const std::string& x_auth_mode() {
					return parameters["x_auth_mode"];
				}
				const std::string& oauth_verifier() {
					return parameters["oauth_verifier"];
				}
			};
		}
	}
}

#endif // __PARAMETERS_OAUTH_H__
