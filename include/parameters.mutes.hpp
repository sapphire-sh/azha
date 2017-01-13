#ifndef __PARAMETERS_MUTES_H__
#define __PARAMETERS_MUTES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
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
		
		namespace POST {
			namespace Mutes {
				namespace Users {
					class CreateParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/mutes/users/create.json");
						
						PARAMETER_STRING(CreateParameters, screen_name);
						PARAMETER_UINT64(CreateParameters, user_id);
					};
					
					class DestroyParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/mutes/users/destroy.json");
						
						PARAMETER_STRING(DestroyParameters, screen_name);
						PARAMETER_UINT64(DestroyParameters, user_id);
					};
				}
			}
		}
	}
}

#endif // __PARAMETERS_MUTES_H__
