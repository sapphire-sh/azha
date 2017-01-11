#ifndef __PARAMETERS_COLLECTIONS_H__
#define __PARAMETERS_COLLECTIONS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Collections {
			class EntriesParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/entries.json");
				
				PARAMETER_STRING(EntriesParameters, id);
				PARAMETER_UINT64(EntriesParameters, count);
				PARAMETER_UINT64(EntriesParameters, max_position);
				PARAMETER_UINT64(EntriesParameters, min_position);
			};
			
			class ListParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/list.json");
				
				PARAMETER_UINT64(ListParameters, user_id);
				PARAMETER_STRING(ListParameters, screen_name);
				PARAMETER_UINT64(ListParameters, tweet_id);
				PARAMETER_UINT64(ListParameters, count);
				PARAMETER_STRING(ListParameters, cursor);
			};
			
			class ShowParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/collections/show.json");
				
				PARAMETER_STRING(ShowParameters, id);
			};
		}
	}
}

#endif // __PARAMETERS_COLLECTIONS_H__
