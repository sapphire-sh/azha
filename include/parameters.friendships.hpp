#ifndef __PARAMETERS_FRIENDSHIPS_H__
#define __PARAMETERS_FRIENDSHIPS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Friendships {
				class IncomingParameters : public ITwitterParameters {
					INIT(IncomingParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/incoming.json")
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, stringify_ids)
				};
				
				class LookupParameters : public ITwitterParameters {
					INIT(LookupParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/lookup.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(std::string, user_id)
				};
				
				namespace NoRetweets {
					class IdsParameters : public ITwitterParameters {
					INIT(IdsParameters)
						METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/lookup.json")
					PARAMETER(bool, stringify_ids)
					};
				}
				
				class OutgoingParameters : public ITwitterParameters {
					INIT(OutgoingParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/outgoing.json")
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, stringify_ids)
				};
				
				class ShowParameters : public ITwitterParameters {
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/show.json")
					PARAMETER(uint64_t, source_id)
					PARAMETER(std::string, source_screen_name)
					PARAMETER(uint64_t, target_id)
					PARAMETER(std::string, target_screen_name)
				};
			}
		}
		
		namespace POST {
			namespace Friendships {
				class CreateParameters : public ITwitterParameters {
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/friendships/create.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, follow)
				};
				
				class DestroyParameters : public ITwitterParameters {
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/friendships/destroy.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
				};
				
				class UpdateParameters : public ITwitterParameters {
					INIT(UpdateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/friendships/update.json")
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, device)
					PARAMETER(bool, retweets)
				};
			}
		}
	}
}

#endif // __PARAMETERS_FRIENDSHIPS_H__
