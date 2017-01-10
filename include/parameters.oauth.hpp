#ifndef __PARAMETERS_OAUTH_H__
#define __PARAMETERS_OAUTH_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace OAuth {
			class RequestTokenParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::POST);
				URL("https://api.twitter.com/oauth/request_token");
				
				PARAMETER_STRING(RequestTokenParameters, oauth_callback);
				PARAMETER_STRING(RequestTokenParameters, x_auth_access_type);
			};
			
			class AccessTokenParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::POST);
				URL("https://api.twitter.com/oauth/access_token");
				
				PARAMETER_STRING(AccessTokenParameters, x_auth_password);
				PARAMETER_STRING(AccessTokenParameters, x_auth_username);
				PARAMETER_STRING(AccessTokenParameters, x_auth_mode);
				PARAMETER_STRING(AccessTokenParameters, oauth_verifier);
			};
		}
	}
}

#endif // __PARAMETERS_OAUTH_H__
