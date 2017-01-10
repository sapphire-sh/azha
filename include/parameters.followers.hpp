#ifndef __PARAMETERS_FOLLOWERS_H__
#define __PARAMETERS_FOLLOWERS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Followers {
			class IdsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/followers/ids.json");
				
				PARAMETER_UINT64(IdsParameter, user_id);
				PARAMETER_STRING(IdsParameter, screen_name);
				PARAMETER_UINT64(IdsParameter, cursor);
				PARAMETER_BOOL(IdsParameter, stringify_ids);
				PARAMETER_UINT64(IdsParameter, count);
			};
			
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/followers/list.json");
				
				PARAMETER_UINT64(ListParameter, user_id);
				PARAMETER_STRING(ListParameter, screen_name);
				PARAMETER_UINT64(ListParameter, cursor);
				PARAMETER_UINT64(ListParameter, count);
				PARAMETER_BOOL(ListParameter, skip_status);
				PARAMETER_BOOL(ListParameter, include_user_entities);
			};
		}
	}
}

#endif // __PARAMETERS_FOLLOWERS_H__
