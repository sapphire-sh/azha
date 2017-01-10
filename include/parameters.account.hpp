#ifndef __PARAMETERS_ACCOUNT_H__
#define __PARAMETERS_ACCOUNT_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Account {
			class SettingsParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/account/settings.json");
			};
			
			class VerifyCredentials : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/account/verify_credentials.json");
				
				PARAMETER_BOOL(VerifyCredentials, include_entities);
				PARAMETER_BOOL(VerifyCredentials, skip_status);
				PARAMETER_BOOL(VerifyCredentials, include_email);
			};
		}
	}
}

#endif // __PARAMETERS_ACCOUNT_H__
