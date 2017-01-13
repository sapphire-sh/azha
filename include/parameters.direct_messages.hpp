#ifndef __PARAMETERS_DIRECT_MESSAGES_H__
#define __PARAMETERS_DIRECT_MESSAGES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace DirectMessages {
				class ReceivedParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/direct_messages.json");
					
					PARAMETER_UINT64(ReceivedParameters, since_id);
					PARAMETER_UINT64(ReceivedParameters, max_id);
					PARAMETER_UINT64(ReceivedParameters, count);
					PARAMETER_BOOL(ReceivedParameters, include_entities);
					PARAMETER_BOOL(ReceivedParameters, skip_status);
				};
				
				class SentParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/direct_messages/sent.json");
					
					PARAMETER_UINT64(SentParameters, since_id);
					PARAMETER_UINT64(SentParameters, max_id);
					PARAMETER_UINT64(SentParameters, count);
					PARAMETER_UINT64(SentParameters, page);
					PARAMETER_BOOL(SentParameters, include_entities);
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/direct_messages/show.json");
					
					PARAMETER_UINT64(ShowParameters, id);
				};
			}
		}
		
		namespace POST {
			namespace DirectMessages {
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/direct_messages/destroy.json");
					
					PARAMETER_UINT64(DestroyParameters, id);
					PARAMETER_BOOL(DestroyParameters, include_entities);
				};
				
				class NewParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/direct_messages/new.json");
					
					PARAMETER_UINT64(NewParameters, user_id);
					PARAMETER_STRING(NewParameters, screen_name);
					PARAMETER_STRING(NewParameters, text);
				};
			}
		}
	}
}

#endif // __PARAMETERS_DIRECT_MESSAGES_H__
