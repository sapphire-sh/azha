#ifndef __PARAMETERS_FAVORITES_H__
#define __PARAMETERS_FAVORITES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Favorites {
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/favorites/list.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, include_entities)
				};
			}
		}
		
		namespace POST {
			namespace Favorites {
				class CreateParameters : public ITwitterParameters {
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/favorites/create.json")

					PARAMETER(uint64_t, id)
					PARAMETER(bool, include_entities)
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/favorites/destroy.json")

					PARAMETER(uint64_t, id)
					PARAMETER(bool, include_entities)
				};
			}
		}
	}
}

#endif // __PARAMETERS_FAVORITES_H__
