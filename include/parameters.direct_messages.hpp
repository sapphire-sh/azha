#ifndef __PARAMETERS_DIRECT_MESSAGES_H__
#define __PARAMETERS_DIRECT_MESSAGES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace DirectMessages {
				class ReceivedParameters : public ITwitterParameters {
					INIT(ReceivedParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/direct_messages.json")
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(uint64_t, count)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
				
				class SentParameters : public ITwitterParameters {
					INIT(SentParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/direct_messages/sent.json")
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, page)
					PARAMETER(bool, include_entities)
				};
				
				class ShowParameters : public ITwitterParameters {
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/direct_messages/show.json")
					PARAMETER(uint64_t, id)
				};
			}
		}
		
		namespace POST {
			namespace DirectMessages {
				class DestroyParameters : public ITwitterParameters {
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/direct_messages/destroy.json")
					PARAMETER(uint64_t, id)
					PARAMETER(bool, include_entities)
				};
				
				class NewParameters : public ITwitterParameters {
					INIT(NewParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/direct_messages/new.json")
					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(std::string, text)
				};
			}
		}
	}
}

#endif // __PARAMETERS_DIRECT_MESSAGES_H__
