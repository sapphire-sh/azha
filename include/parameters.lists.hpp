#ifndef __PARAMETERS_LISTS_H__
#define __PARAMETERS_LISTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
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
}

#endif // __PARAMETERS_LISTS_H__
