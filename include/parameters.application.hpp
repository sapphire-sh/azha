#ifndef __PARAMETERS_APPLICATION_H__
#define __PARAMETERS_APPLICATION_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Application {
			class RateLimitStatus : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/application/rate_limit_status.json");

				PARAMETER_STRING(RateLimitStatus, resources);
			};
		}
	}
}

#endif // __PARAMETERS_APPLICATION_H__
