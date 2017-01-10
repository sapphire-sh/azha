#ifndef __PARAMETERS_DIRECT_MESSAGES_H__
#define __PARAMETERS_DIRECT_MESSAGES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace DirectMessages {
			class ReceivedParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/direct_messages.json");
				
				PARAMETER_UINT64(ReceivedParameters, since_id);
				PARAMETER_UINT64(ReceivedParameters, max_id);
				PARAMETER_UINT64(ReceivedParameters, count);
				PARAMETER_BOOL(ReceivedParameters, include_entities);
				PARAMETER_BOOL(ReceivedParameters, skip_status);
			};
			
			class SentParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/direct_messages/sent.json");
				
				PARAMETER_UINT64(SentParameters, since_id);
				PARAMETER_UINT64(SentParameters, max_id);
				PARAMETER_UINT64(SentParameters, count);
				PARAMETER_UINT64(SentParameters, page);
				PARAMETER_BOOL(SentParameters, include_entities);
			};
			
			class ShowParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/direct_messages/show.json");
				
				PARAMETER_UINT64(ShowParameters, id);
			};
		}
	}
}

#endif // __PARAMETERS_DIRECT_MESSAGES_H__
