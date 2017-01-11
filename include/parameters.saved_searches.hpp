#ifndef __PARAMETERS_SAVED_SEARCHES_H__
#define __PARAMETERS_SAVED_SEARCHES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace SavedSearches {
			class ListParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/saved_searches/list.json");
			};
			
			class ShowParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				const std::string &url() const {
					std::stringstream ss;
					ss << "https://api.twitter.com/1.1/saved_searches/show/";
					ss << parameters.at("id");
					ss << ".json";
					static const std::string _url = ss.str();
					return _url;
				}
				
				PARAMETER_UINT64(ShowParameters, id);
			};
		}
	}
}

#endif // __PARAMETERS_SAVED_SEARCHES_H__
