#ifndef __PARAMETERS_APPLICATION_H__
#define __PARAMETERS_APPLICATION_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Application {
				class RateLimitStatusParameters : public ITwitterParameters {
				public:
					INIT(RateLimitStatusParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/application/rate_limit_status.json")

					PARAMETER(std::string, resources)
				};
			}
		}
	}
}

#endif // __PARAMETERS_APPLICATION_H__
