#ifndef __PARAMETERS_FAVORITES_H__
#define __PARAMETERS_FAVORITES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Favorites {
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/favorites/list.json");

				PARAMETER_UINT64(ListParameter, user_id);
				PARAMETER_STRING(ListParameter, screen_name);
				PARAMETER_UINT64(ListParameter, count);
				PARAMETER_UINT64(ListParameter, since_id);
				PARAMETER_UINT64(ListParameter, max_id);
				PARAMETER_BOOL(ListParameter, include_entities);
			};
		}
	}
}

#endif // __PARAMETERS_FAVORITES_H__
