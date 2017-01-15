#ifndef __PARAMETERS_SEARCH_H__
#define __PARAMETERS_SEARCH_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Search {
				class TweetsParameters : public ITwitterParameters {
				public:
					INIT(TweetsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/search/tweets.json")

					PARAMETER(std::string, q)
					PARAMETER(std::string, geocode)
					PARAMETER(std::string, lang)
					PARAMETER(std::string, locale)
					PARAMETER(std::string, result_type)
					PARAMETER(uint64_t, count)
					PARAMETER(std::string, until)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, include_entities)
				};
			}
		}
	}
}

#endif // __PARAMETERS_SEARCH_H__
