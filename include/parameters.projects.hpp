#ifndef __PARAMETERS_PROJECTS_H__
#define __PARAMETERS_PROJECTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Projects {
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://curator.twitter.com/broadcast/1/projects");
				
				PARAMETER_UINT64(ListParameter, limit);
				PARAMETER_STRING(ListParameter, format);
				PARAMETER_STRING(ListParameter, auth);
			};
		}
	}
}

#endif // __PARAMETERS_PROJECTS_H__
