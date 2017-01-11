#ifndef __PARAMETERS_USERS_H__
#define __PARAMETERS_USERS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Users {
			class LookupParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/users/lookup.json");

				PARAMETER_STRING(LookupParameters, screen_name);
				PARAMETER_UINT64(LookupParameters, user_id);
				PARAMETER_BOOL(LookupParameters, include_entities);
			};
			
			class ProfileBannerParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/users/profile_banner.json");
				
				PARAMETER_STRING(ProfileBannerParameters, screen_name);
				PARAMETER_UINT64(ProfileBannerParameters, user_id);
			};
			
			class SearchParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/users/search.json");
				
				PARAMETER_STRING(SearchParameters, q);
				PARAMETER_UINT64(SearchParameters, page);
				PARAMETER_UINT64(SearchParameters, count);
				PARAMETER_BOOL(SearchParameters, include_entities);
			};
			
			class ShowParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/users/show.json");
				
				PARAMETER_UINT64(ShowParameters, user_id);
				PARAMETER_STRING(ShowParameters, screen_name);
				PARAMETER_BOOL(ShowParameters, include_entities);
			};
			
			class SuggestionsParameters : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/users/suggestions.json");
				
				PARAMETER_STRING(SuggestionsParameters, lang);
			};
			
			namespace Suggestions {
				class ListParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/users/suggestions/";
						ss << parameters.at("slug");
						ss << ".json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_STRING(ListParameters, slug);
					PARAMETER_STRING(ListParameters, lang);
				};
				
				class MembersParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/users/suggestions/";
						ss << parameters.at("slug");
						ss << "/members.json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_STRING(MembersParameters, slug);
				};
			}
		}
	}
}

#endif // __PARAMETERS_USERS_H__
