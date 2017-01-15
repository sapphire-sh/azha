#ifndef __PARAMETERS_FRIENDSHIPS_H__
#define __PARAMETERS_FRIENDSHIPS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Friendships {
				class IncomingParameters : public ITwitterParameters {
				public:
					INIT(IncomingParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/incoming.json")

					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, stringify_ids)
				};
				
				class LookupParameters : public ITwitterParameters {
				public:
					INIT(LookupParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/lookup.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(std::string, user_id)
				};
				
				namespace NoRetweets {
					class IdsParameters : public ITwitterParameters {
					public:
						INIT(IdsParameters)
						METHOD(RequestMethod::GET)
						URL("https://api.twitter.com/1.1/friendships/lookup.json")

						PARAMETER(bool, stringify_ids)
					};
				}
				
				class OutgoingParameters : public ITwitterParameters {
				public:
					INIT(OutgoingParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/friendships/outgoing.json")

					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, stringify_ids)
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
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
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/friendships/create.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, follow)
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/friendships/destroy.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
				};
				
				class UpdateParameters : public ITwitterParameters {
				public:
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
