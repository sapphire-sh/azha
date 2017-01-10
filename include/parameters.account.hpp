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
			
			class VerifyCredentialsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/account/verify_credentials.json");
				
				PARAMETER_BOOL(VerifyCredentialsParameter, include_entities);
				PARAMETER_BOOL(VerifyCredentialsParameter, skip_status);
				PARAMETER_BOOL(VerifyCredentialsParameter, include_email);
			};
		}
	}
}

#endif // __PARAMETERS_ACCOUNT_H__
