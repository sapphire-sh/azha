#ifndef __PARAMETERS_FRIENDSHIPS_H__
#define __PARAMETERS_FRIENDSHIPS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
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
		
		namespace POST {
			namespace Friendships {
				class CreateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/friendships/create.json");
					
					PARAMETER_STRING(CreateParameters, screen_name);
					PARAMETER_UINT64(CreateParameters, user_id);
					PARAMETER_BOOL(CreateParameters, follow);
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/friendships/destroy.json");
					
					PARAMETER_STRING(DestroyParameters, screen_name);
					PARAMETER_UINT64(DestroyParameters, user_id);
				};
				
				class UpdateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/friendships/update.json");
					
					PARAMETER_STRING(UpdateParameters, screen_name);
					PARAMETER_UINT64(UpdateParameters, user_id);
					PARAMETER_BOOL(UpdateParameters, device);
					PARAMETER_BOOL(UpdateParameters, retweets);
				};
			}
		}
	}
}

#endif // __PARAMETERS_FRIENDSHIPS_H__
