#ifndef __PARAMETERS_MUTES_H__
#define __PARAMETERS_MUTES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Mutes {
			namespace Users {
				class IdsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/mutes/users/ids.json");
					
					PARAMETER_UINT64(IdsParameters, cursor);
				};
				
				class ListParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/mutes/users/list.json");
					
					PARAMETER_UINT64(ListParameters, cursor);
					PARAMETER_BOOL(ListParameters, include_entities);
					PARAMETER_BOOL(ListParameters, skip_status);
				};
			}
		}
	}
}

#endif // __PARAMETERS_MUTES_H__
