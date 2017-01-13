#ifndef __PARAMETERS_LISTS_H__
#define __PARAMETERS_LISTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Lists {
				class ListParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/list.json");
					
					PARAMETER_UINT64(ListParameters, user_id);
					PARAMETER_STRING(ListParameters, screen_name);
					PARAMETER_BOOL(ListParameters, reverse);
				};
				
				class MembersParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/members.json");
					
					PARAMETER_UINT64(MembersParameters, list_id);
					// not sure
					PARAMETER_STRING(MembersParameters, slug);
					PARAMETER_STRING(MembersParameters, owner_screen_name);
					PARAMETER_UINT64(MembersParameters, owner_id);
					PARAMETER_UINT64(MembersParameters, count);
					PARAMETER_UINT64(MembersParameters, cursor);
					PARAMETER_BOOL(MembersParameters, include_entities);
					PARAMETER_BOOL(MembersParameters, skip_status);
				};
				
				namespace Members {
					class ShowParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::GET);
						URL("https://api.twitter.com/1.1/lists/members/show.json");
						
						PARAMETER_UINT64(ShowParameters, list_id);
						// not sure
						PARAMETER_STRING(ShowParameters, slug);
						PARAMETER_STRING(ShowParameters, owner_screen_name);
						PARAMETER_UINT64(ShowParameters, owner_id);
						PARAMETER_UINT64(ShowParameters, count);
						PARAMETER_UINT64(ShowParameters, cursor);
						PARAMETER_BOOL(ShowParameters, include_entities);
						PARAMETER_BOOL(ShowParameters, skip_status);
					};
				}
				
				class MembershipsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/memberships.json");
					
					PARAMETER_UINT64(MembershipsParameters, user_id);
					PARAMETER_STRING(MembershipsParameters, screen_name);
					PARAMETER_UINT64(MembershipsParameters, count);
					PARAMETER_UINT64(MembershipsParameters, cursor);
					PARAMETER_BOOL(MembershipsParameters, filter_to_owned_lists);
				};
				
				class OwnershipsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/ownerships.json");
					
					PARAMETER_UINT64(OwnershipsParameters, user_id);
					PARAMETER_STRING(OwnershipsParameters, screen_name);
					PARAMETER_UINT64(OwnershipsParameters, count);
					PARAMETER_UINT64(OwnershipsParameters, cursor);
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/show.json");
					
					PARAMETER_UINT64(ShowParameters, list_id);
					// not sure
					PARAMETER_STRING(ShowParameters, slug);
					PARAMETER_STRING(ShowParameters, owner_screen_name);
					PARAMETER_UINT64(ShowParameters, owner_id);
				};
				
				class StatusesParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/statuses.json");
					
					PARAMETER_UINT64(StatusesParameters, list_id);
					// not sure
					PARAMETER_STRING(StatusesParameters, slug);
					PARAMETER_STRING(StatusesParameters, owner_screen_name);
					PARAMETER_UINT64(StatusesParameters, owner_id);
					PARAMETER_UINT64(StatusesParameters, since_id);
					PARAMETER_UINT64(StatusesParameters, max_id);
					PARAMETER_UINT64(StatusesParameters, count);
					PARAMETER_BOOL(StatusesParameters, include_entities);
					PARAMETER_BOOL(StatusesParameters, include_rts);
				};
				
				class SubscribersParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/subscribers.json");
					
					PARAMETER_UINT64(SubscribersParameters, list_id);
					// not sure
					PARAMETER_STRING(SubscribersParameters, slug);
					PARAMETER_STRING(SubscribersParameters, owner_screen_name);
					PARAMETER_UINT64(SubscribersParameters, owner_id);
					PARAMETER_UINT64(SubscribersParameters, count);
					PARAMETER_UINT64(SubscribersParameters, cursor);
					PARAMETER_BOOL(SubscribersParameters, include_entities);
					PARAMETER_BOOL(SubscribersParameters, skip_status);
				};
				
				namespace Subscribers {
					class ShowParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::GET);
						URL("https://api.twitter.com/1.1/lists/subscribers/show.json");
						
						PARAMETER_STRING(ShowParameters, owner_screen_name);
						PARAMETER_UINT64(ShowParameters, owner_id);
						PARAMETER_UINT64(ShowParameters, list_id);
						// not sure
						PARAMETER_STRING(ShowParameters, slug);
						PARAMETER_UINT64(ShowParameters, user_id);
						PARAMETER_STRING(ShowParameters, screen_name);
						PARAMETER_BOOL(ShowParameters, include_entities);
						PARAMETER_BOOL(ShowParameters, skip_status);
					};
				}
				
				class SubscriptionsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/subscriptions.json");
					
					PARAMETER_UINT64(SubscriptionsParameters, user_id);
					PARAMETER_STRING(SubscriptionsParameters, screen_name);
					PARAMETER_UINT64(SubscriptionsParameters, count);
					PARAMETER_UINT64(SubscriptionsParameters, cursor);
				};
			}
		}
		
		namespace POST {
			namespace Lists {
				class CreateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/lists/create.json");
					
					PARAMETER_STRING(CreateParameters, name);
					PARAMETER_STRING(CreateParameters, mode);
					PARAMETER_STRING(CreateParameters, description);
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/lists/destroy.json");
					
					PARAMETER_STRING(DestroyParameters, owner_screen_name);
					PARAMETER_UINT64(DestroyParameters, owner_id);
					PARAMETER_UINT64(DestroyParameters, list_id);
					PARAMETER_STRING(DestroyParameters, slug);
				};
				
				namespace Members {
					class CreateParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/members/create.json");
						
						PARAMETER_UINT64(CreateParameters, list_id);
						PARAMETER_STRING(CreateParameters, slug);
						PARAMETER_UINT64(CreateParameters, user_id);
						PARAMETER_STRING(CreateParameters, screen_name);
						PARAMETER_STRING(CreateParameters, owner_screen_name);
						PARAMETER_UINT64(CreateParameters, owner_id);
					};
					
					class CreateAllParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/members/create_all.json");
						
						PARAMETER_UINT64(CreateAllParameters, list_id);
						PARAMETER_STRING(CreateAllParameters, slug);
						PARAMETER_UINT64(CreateAllParameters, user_id);
						PARAMETER_STRING(CreateAllParameters, screen_name);
						PARAMETER_STRING(CreateAllParameters, owner_screen_name);
						PARAMETER_UINT64(CreateAllParameters, owner_id);
					};
					
					class DestroyParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/members/destroy.json");
						
						PARAMETER_UINT64(DestroyParameters, list_id);
						PARAMETER_STRING(DestroyParameters, slug);
						PARAMETER_UINT64(DestroyParameters, user_id);
						PARAMETER_STRING(DestroyParameters, screen_name);
						PARAMETER_STRING(DestroyParameters, owner_screen_name);
						PARAMETER_UINT64(DestroyParameters, owner_id);
					};
					
					class DestroyAllParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/members/destroy.json");
						
						PARAMETER_UINT64(DestroyAllParameters, list_id);
						PARAMETER_STRING(DestroyAllParameters, slug);
						PARAMETER_UINT64(DestroyAllParameters, user_id);
						PARAMETER_STRING(DestroyAllParameters, screen_name);
						PARAMETER_STRING(DestroyAllParameters, owner_screen_name);
						PARAMETER_UINT64(DestroyAllParameters, owner_id);
					};
				}
				
				namespace Subscribers {
					class CreateParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/subscribers/create.json");
						
						PARAMETER_STRING(CreateParameters, owner_screen_name);
						PARAMETER_UINT64(CreateParameters, owner_id);
						PARAMETER_UINT64(CreateParameters, list_id);
						PARAMETER_STRING(CreateParameters, slug);
					};
					
					class DestroyParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/subscribers/destroy.json");
						
						PARAMETER_UINT64(DestroyParameters, list_id);
						PARAMETER_STRING(DestroyParameters, slug);
						PARAMETER_STRING(DestroyParameters, owner_screen_name);
						PARAMETER_UINT64(DestroyParameters, owner_id);
					};
					
					class UpdateParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/lists/update.json");
						
						PARAMETER_UINT64(UpdateParameters, list_id);
						PARAMETER_STRING(UpdateParameters, slug);
						PARAMETER_STRING(UpdateParameters, name);
						PARAMETER_STRING(UpdateParameters, mode);
						PARAMETER_STRING(UpdateParameters, description);
						PARAMETER_STRING(UpdateParameters, owner_screen_name);
						PARAMETER_UINT64(UpdateParameters, owner_id);
					};
				}
			}
		}
	}
}

#endif // __PARAMETERS_LISTS_H__
