#ifndef __PARAMETERS_FRIENDSHIPS_H__
#define __PARAMETERS_FRIENDSHIPS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Friendships {
			class IncomingParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/incoming.json");
				
				PARAMETER_UINT64(IncomingParameters, cursor);
				PARAMETER_BOOL(IncomingParameters, stringify_ids);
			};
			
			class LookupParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/lookup.json");
				
				PARAMETER_STRING(LookupParameters, screen_name);
				PARAMETER_STRING(LookupParameters, user_id);
			};
			
			namespace NoRetweets {
				class IdsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/friendships/lookup.json");
					
					PARAMETER_BOOL(IdsParameters, stringify_ids);
				};
			}
			
			class OutgoingParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/outgoing.json");
				
				PARAMETER_UINT64(OutgoingParameters, cursor);
				PARAMETER_BOOL(OutgoingParameters, stringify_ids);
			};
			
			class ShowParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/friendships/show.json");
				
				PARAMETER_UINT64(ShowParameters, source_id);
				PARAMETER_STRING(ShowParameters, source_screen_name);
				PARAMETER_UINT64(ShowParameters, target_id);
				PARAMETER_STRING(ShowParameters, target_screen_name);
			};
		}
	}
}

#endif // __PARAMETERS_FRIENDSHIPS_H__
