#ifndef __PARAMETERS_SAVED_SEARCHES_H__
#define __PARAMETERS_SAVED_SEARCHES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace SavedSearches {
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/saved_searches/list.json")
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					const std::string &request_url() const override {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/saved_searches/show/";
						ss << parameters.at("id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}

					PARAMETER(uint64_t, id)
				};
			}
		}
		
		namespace POST {
			namespace SavedSearches {
				class CreateParameters : public ITwitterParameters {
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/saved_searches/create.json")

					PARAMETER(std::string, query)
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					const std::string &request_url() const override {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/saved_searches/destroy/";
						ss << parameters.at("id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}
				  
				  PARAMETER(uint64_t, id)
				};
			}
		}
	}
}

#endif // __PARAMETERS_SAVED_SEARCHES_H__
