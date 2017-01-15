#ifndef __PARAMETERS_PROJECTS_H__
#define __PARAMETERS_PROJECTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Projects {
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://curator.twitter.com/broadcast/1/projects")

					PARAMETER(uint64_t, limit)
					PARAMETER(std::string, format)
					PARAMETER(std::string, auth)
				};
			}
		}
	}
}

#endif // __PARAMETERS_PROJECTS_H__
