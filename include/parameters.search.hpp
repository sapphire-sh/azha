#ifndef __PARAMETERS_SEARCH_H__
#define __PARAMETERS_SEARCH_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Search {
				class TweetsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/search/tweets.json");

					PARAMETER_STRING(TweetsParameters, q);
					PARAMETER_STRING(TweetsParameters, geocode);
					PARAMETER_STRING(TweetsParameters, lang);
					PARAMETER_STRING(TweetsParameters, locale);
					PARAMETER_STRING(TweetsParameters, result_type);
					PARAMETER_UINT64(TweetsParameters, count);
					PARAMETER_STRING(TweetsParameters, until);
					PARAMETER_UINT64(TweetsParameters, since_id);
					PARAMETER_UINT64(TweetsParameters, max_id);
					PARAMETER_BOOL(TweetsParameters, include_entities);
				};
			}
		}
	}
}

#endif // __PARAMETERS_SEARCH_H__
