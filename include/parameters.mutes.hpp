#ifndef __PARAMETERS_MUTES_H__
#define __PARAMETERS_MUTES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Mutes {
				namespace Users {
					class IdsParameters : public ITwitterParameters {
					INIT(IdsParameters)
						METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/mutes/users/ids.json")
					PARAMETER(uint64_t, cursor)
					};
					
					class ListParameters : public ITwitterParameters {
					INIT(ListParameters)
						METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/mutes/users/list.json")
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
					};
				}
			}
		}
		
		namespace POST {
			namespace Mutes {
				namespace Users {
					class CreateParameters : public ITwitterParameters {
					INIT(CreateParameters)
						METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/mutes/users/create.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					};
					
					class DestroyParameters : public ITwitterParameters {
					INIT(DestroyParameters)
						METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/mutes/users/destroy.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					};
				}
			}
		}
	}
}

#endif // __PARAMETERS_MUTES_H__
