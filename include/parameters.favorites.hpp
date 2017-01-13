#ifndef __PARAMETERS_FAVORITES_H__
#define __PARAMETERS_FAVORITES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Favorites {
				class ListParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/favorites/list.json");

					PARAMETER_UINT64(ListParameters, user_id);
					PARAMETER_STRING(ListParameters, screen_name);
					PARAMETER_UINT64(ListParameters, count);
					PARAMETER_UINT64(ListParameters, since_id);
					PARAMETER_UINT64(ListParameters, max_id);
					PARAMETER_BOOL(ListParameters, include_entities);
				};
			}
		}
		
		namespace POST {
			namespace Favorites {
				class CreateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/favorites/create.json");
					
					PARAMETER_UINT64(CreateParameters, id);
					PARAMETER_BOOL(CreateParameters, include_entities);
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/favorites/destroy.json");
					
					PARAMETER_UINT64(DestroyParameters, id);
					PARAMETER_BOOL(DestroyParameters, include_entities);
				};
			}
		}
	}
}

#endif // __PARAMETERS_FAVORITES_H__
