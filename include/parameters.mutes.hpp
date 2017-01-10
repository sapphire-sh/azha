#ifndef __PARAMETERS_MUTES_H__
#define __PARAMETERS_MUTES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Mutes {
			namespace Users {
				class IdsParameter : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/mutes/users/ids.json");
					
					PARAMETER_UINT64(IdsParameter, cursor);
				};
				
				class ListParameter : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/mutes/users/list.json");
					
					PARAMETER_UINT64(ListParameter, cursor);
					PARAMETER_BOOL(ListParameter, include_entities);
					PARAMETER_BOOL(ListParameter, skip_status);
				};
			}
		}
	}
}

#endif // __PARAMETERS_MUTES_H__
