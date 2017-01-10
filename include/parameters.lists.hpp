#ifndef __PARAMETERS_LISTS_H__
#define __PARAMETERS_LISTS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Lists {
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/list.json");
				
				PARAMETER_UINT64(ListParameter, user_id);
				PARAMETER_STRING(ListParameter, screen_name);
				PARAMETER_BOOL(ListParameter, reverse);
			};
			
			class MembersParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/members.json");
				
				PARAMETER_UINT64(MembersParameter, list_id);
				// not sure
				PARAMETER_STRING(MembersParameter, slug);
				PARAMETER_STRING(MembersParameter, owner_screen_name);
				PARAMETER_UINT64(MembersParameter, owner_id);
				PARAMETER_UINT64(MembersParameter, count);
				PARAMETER_UINT64(MembersParameter, cursor);
				PARAMETER_BOOL(MembersParameter, include_entities);
				PARAMETER_BOOL(MembersParameter, skip_status);
			};
			
			namespace Members {
				class ShowParameter : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/members/show.json");
					
					PARAMETER_UINT64(ShowParameter, list_id);
					// not sure
					PARAMETER_STRING(ShowParameter, slug);
					PARAMETER_STRING(ShowParameter, owner_screen_name);
					PARAMETER_UINT64(ShowParameter, owner_id);
					PARAMETER_UINT64(ShowParameter, count);
					PARAMETER_UINT64(ShowParameter, cursor);
					PARAMETER_BOOL(ShowParameter, include_entities);
					PARAMETER_BOOL(ShowParameter, skip_status);
				};
			}
			
			class MembershipsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/memberships.json");
				
				PARAMETER_UINT64(MembershipsParameter, user_id);
				PARAMETER_STRING(MembershipsParameter, screen_name);
				PARAMETER_UINT64(MembershipsParameter, count);
				PARAMETER_UINT64(MembershipsParameter, cursor);
				PARAMETER_BOOL(MembershipsParameter, filter_to_owned_lists);
			};
			
			class OwnershipsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/ownerships.json");
				
				PARAMETER_UINT64(OwnershipsParameter, user_id);
				PARAMETER_STRING(OwnershipsParameter, screen_name);
				PARAMETER_UINT64(OwnershipsParameter, count);
				PARAMETER_UINT64(OwnershipsParameter, cursor);
			};
			
			class ShowParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/show.json");
				
				PARAMETER_UINT64(ShowParameter, list_id);
				// not sure
				PARAMETER_STRING(ShowParameter, slug);
				PARAMETER_STRING(ShowParameter, owner_screen_name);
				PARAMETER_UINT64(ShowParameter, owner_id);
			};
			
			class StatusesParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/statuses.json");
				
				PARAMETER_UINT64(StatusesParameter, list_id);
				// not sure
				PARAMETER_STRING(StatusesParameter, slug);
				PARAMETER_STRING(StatusesParameter, owner_screen_name);
				PARAMETER_UINT64(StatusesParameter, owner_id);
				PARAMETER_UINT64(StatusesParameter, since_id);
				PARAMETER_UINT64(StatusesParameter, max_id);
				PARAMETER_UINT64(StatusesParameter, count);
				PARAMETER_BOOL(StatusesParameter, include_entities);
				PARAMETER_BOOL(StatusesParameter, include_rts);
			};
			
			class SubscribersParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/subscribers.json");
				
				PARAMETER_UINT64(SubscribersParameter, list_id);
				// not sure
				PARAMETER_STRING(SubscribersParameter, slug);
				PARAMETER_STRING(SubscribersParameter, owner_screen_name);
				PARAMETER_UINT64(SubscribersParameter, owner_id);
				PARAMETER_UINT64(SubscribersParameter, count);
				PARAMETER_UINT64(SubscribersParameter, cursor);
				PARAMETER_BOOL(SubscribersParameter, include_entities);
				PARAMETER_BOOL(SubscribersParameter, skip_status);
			};
			
			namespace Subscribers {
				class ShowParameter : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/lists/subscribers/show.json");
					
					PARAMETER_STRING(ShowParameter, owner_screen_name);
					PARAMETER_UINT64(ShowParameter, owner_id);
					PARAMETER_UINT64(ShowParameter, list_id);
					// not sure
					PARAMETER_STRING(ShowParameter, slug);
					PARAMETER_UINT64(ShowParameter, user_id);
					PARAMETER_STRING(ShowParameter, screen_name);
					PARAMETER_BOOL(ShowParameter, include_entities);
					PARAMETER_BOOL(ShowParameter, skip_status);
				};
			}
			
			class SubscriptionsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/lists/subscriptions.json");
				
				PARAMETER_UINT64(SubscriptionsParameter, user_id);
				PARAMETER_STRING(SubscriptionsParameter, screen_name);
				PARAMETER_UINT64(SubscriptionsParameter, count);
				PARAMETER_UINT64(SubscriptionsParameter, cursor);
			};
		}
	}
}

#endif // __PARAMETERS_LISTS_H__
