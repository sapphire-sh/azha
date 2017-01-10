#ifndef __PARAMETERS_FRIENDSHIPS_H__
#define __PARAMETERS_FRIENDSHIPS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Friendships {
			class IncomingParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/incoming.json");
				
				PARAMETER_UINT64(IncomingParameter, cursor);
				PARAMETER_BOOL(IncomingParameter, stringify_ids);
			};
			
			class LookupParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/lookup.json");
				
				PARAMETER_STRING(LookupParameter, screen_name);
				PARAMETER_STRING(LookupParameter, user_id);
			};
			
			namespace NoRetweets {
				class IdsParameter : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/friendships/lookup.json");
					
					PARAMETER_BOOL(IdsParameter, stringify_ids);
				};
			}
			
			class OutgoingParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/outgoing.json");
				
				PARAMETER_UINT64(OutgoingParameter, cursor);
				PARAMETER_BOOL(OutgoingParameter, stringify_ids);
			};
			
			class ShowParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/show.json");
				
				PARAMETER_UINT64(ShowParameter, source_id);
				PARAMETER_STRING(ShowParameter, source_screen_name);
				PARAMETER_UINT64(ShowParameter, target_id);
				PARAMETER_STRING(ShowParameter, target_screen_name);
			};
		}
	}
}

#endif // __PARAMETERS_FRIENDSHIPS_H__
