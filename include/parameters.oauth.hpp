#ifndef __PARAMETERS_OAUTH_H__
#define __PARAMETERS_OAUTH_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace POST {
			namespace OAuth {
				class RequestTokenParameters : public ITwitterParameters {
				public:
					INIT(RequestTokenParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/oauth/request_token")

					PARAMETER(std::string, oauth_callback)
					PARAMETER(std::string, x_auth_access_type)
				};
				
				class AccessTokenParameters : public ITwitterParameters {
				public:
					INIT(AccessTokenParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/oauth/access_token")

					PARAMETER(std::string, x_auth_password)
					PARAMETER(std::string, x_auth_username)
					PARAMETER(std::string, x_auth_mode)
					PARAMETER(std::string, oauth_verifier)
				};
			}
		}
	}
}

#endif // __PARAMETERS_OAUTH_H__
