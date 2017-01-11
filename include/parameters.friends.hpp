#ifndef __PARAMETERS_FRIENDs_H__
#define __PARAMETERS_FRIENDs_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Friends {
			class IdsParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friends/ids.json");
				
				PARAMETER_UINT64(IdsParameters, user_id);
				PARAMETER_STRING(IdsParameters, screen_name);
				PARAMETER_UINT64(IdsParameters, cursor);
				PARAMETER_BOOL(IdsParameters, stringify_ids);
				PARAMETER_UINT64(IdsParameters, count);
			};
			
			class ListParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friends/list.json");
				
				PARAMETER_UINT64(ListParameters, user_id);
				PARAMETER_STRING(ListParameters, screen_name);
				PARAMETER_UINT64(ListParameters, cursor);
				PARAMETER_UINT64(ListParameters, count);
				PARAMETER_BOOL(ListParameters, skip_status);
				PARAMETER_BOOL(ListParameters, include_user_entities);
			};
		}
	}
}

#endif // __PARAMETERS_FRIENDs_H__
