#ifndef __PARAMETERS_LISTS_H__
#define __PARAMETERS_LISTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Lists {
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/list.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(bool, reverse)
				};
				
				class MembersParameters : public ITwitterParameters {
				public:
					INIT(MembersParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/members.json")

					PARAMETER(uint64_t, list_id)
					// not sure PARAMETER(std::string, slug)
					PARAMETER(std::string, owner_screen_name)
					PARAMETER(uint64_t, owner_id)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
				
				namespace Members {
					class ShowParameters : public ITwitterParameters {
					public:
						INIT(ShowParameters)
						METHOD(RequestMethod::GET)
						URL("https://api.twitter.com/1.1/lists/members/show.json")

						PARAMETER(uint64_t, list_id)
						// not sure PARAMETER(std::string, slug)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
						PARAMETER(uint64_t, count)
						PARAMETER(uint64_t, cursor)
						PARAMETER(bool, include_entities)
						PARAMETER(bool, skip_status)
					};
				}
				
				class MembershipsParameters : public ITwitterParameters {
				public:
					INIT(MembershipsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/memberships.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, filter_to_owned_lists)
				};
				
				class OwnershipsParameters : public ITwitterParameters {
				public:
					INIT(OwnershipsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/ownerships.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, cursor)
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/show.json")

					PARAMETER(uint64_t, list_id)
					// not sure PARAMETER(std::string, slug)
					PARAMETER(std::string, owner_screen_name)
					PARAMETER(uint64_t, owner_id)
				};
				
				class StatusesParameters : public ITwitterParameters {
				public:
					INIT(StatusesParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/statuses.json")

					PARAMETER(uint64_t, list_id)
					// not sure PARAMETER(std::string, slug)
					PARAMETER(std::string, owner_screen_name)
					PARAMETER(uint64_t, owner_id)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(uint64_t, count)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, include_rts)
				};
				
				class SubscribersParameters : public ITwitterParameters {
				public:
					INIT(SubscribersParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/subscribers.json")

					PARAMETER(uint64_t, list_id)
					// not sure PARAMETER(std::string, slug)
					PARAMETER(std::string, owner_screen_name)
					PARAMETER(uint64_t, owner_id)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
				
				namespace Subscribers {
					class ShowParameters : public ITwitterParameters {
					public:
						INIT(ShowParameters)
						METHOD(RequestMethod::GET)
						URL("https://api.twitter.com/1.1/lists/subscribers/show.json")

						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
						PARAMETER(uint64_t, list_id)
						// not sure PARAMETER(std::string, slug)
						PARAMETER(uint64_t, user_id)
						PARAMETER(std::string, screen_name)
						PARAMETER(bool, include_entities)
						PARAMETER(bool, skip_status)
					};
				}
				
				class SubscriptionsParameters : public ITwitterParameters {
				public:
					INIT(SubscriptionsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/lists/subscriptions.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, cursor)
				};
			}
		}
		
		namespace POST {
			namespace Lists {
				class CreateParameters : public ITwitterParameters {
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/lists/create.json")

					PARAMETER(std::string, name)
					PARAMETER(std::string, mode)
					PARAMETER(std::string, description)
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/lists/destroy.json")

					PARAMETER(std::string, owner_screen_name)
					PARAMETER(uint64_t, owner_id)
					PARAMETER(uint64_t, list_id)
					PARAMETER(std::string, slug)
				};
				
				namespace Members {
					class CreateParameters : public ITwitterParameters {
					public:
						INIT(CreateParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/members/create.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(uint64_t, user_id)
						PARAMETER(std::string, screen_name)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
					
					class CreateAllParameters : public ITwitterParameters {
					public:
						INIT(CreateAllParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/members/create_all.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(uint64_t, user_id)
						PARAMETER(std::string, screen_name)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
					
					class DestroyParameters : public ITwitterParameters {
					public:
						INIT(DestroyParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/members/destroy.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(uint64_t, user_id)
						PARAMETER(std::string, screen_name)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
					
					class DestroyAllParameters : public ITwitterParameters {
					public:
						INIT(DestroyAllParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/members/destroy.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(uint64_t, user_id)
						PARAMETER(std::string, screen_name)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
				}
				
				namespace Subscribers {
					class CreateParameters : public ITwitterParameters {
					public:
						INIT(CreateParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/subscribers/create.json")

						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
					};
					
					class DestroyParameters : public ITwitterParameters {
					public:
						INIT(DestroyParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/subscribers/destroy.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
					
					class UpdateParameters : public ITwitterParameters {
					public:
						INIT(UpdateParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/lists/update.json")

						PARAMETER(uint64_t, list_id)
						PARAMETER(std::string, slug)
						PARAMETER(std::string, name)
						PARAMETER(std::string, mode)
						PARAMETER(std::string, description)
						PARAMETER(std::string, owner_screen_name)
						PARAMETER(uint64_t, owner_id)
					};
				}
			}
		}
	}
}

#endif // __PARAMETERS_LISTS_H__
