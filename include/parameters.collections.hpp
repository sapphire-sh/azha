#ifndef __PARAMETERS_COLLECTIONS_H__
#define __PARAMETERS_COLLECTIONS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Collections {
			class EntriesParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/entries.json");
				
				PARAMETER_STRING(EntriesParameter, id);
				PARAMETER_UINT64(EntriesParameter, count);
				PARAMETER_UINT64(EntriesParameter, max_position);
				PARAMETER_UINT64(EntriesParameter, min_position);
			};
			
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/list.json");
				
				PARAMETER_UINT64(ListParameter, user_id);
				PARAMETER_STRING(ListParameter, screen_name);
				PARAMETER_UINT64(ListParameter, tweet_id);
				PARAMETER_UINT64(ListParameter, count);
				PARAMETER_STRING(ListParameter, cursor);
			};
			
			class ShowParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/show.json");
				
				PARAMETER_STRING(ShowParameter, id);
			};
		}
	}
}

#endif // __PARAMETERS_COLLECTIONS_H__
