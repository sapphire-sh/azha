#ifndef __PARAMETERS_PROJECTS_H__
#define __PARAMETERS_PROJECTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Projects {
				class ListParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://curator.twitter.com/broadcast/1/projects");
					
					PARAMETER_UINT64(ListParameters, limit);
					PARAMETER_STRING(ListParameters, format);
					PARAMETER_STRING(ListParameters, auth);
				};
			}
		}
	}
}

#endif // __PARAMETERS_PROJECTS_H__
