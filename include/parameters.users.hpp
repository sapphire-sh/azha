#ifndef __PARAMETERS_USERS_H__
#define __PARAMETERS_USERS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Users {
				class LookupParameters : public ITwitterParameters {
				public:
					INIT(LookupParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/users/lookup.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, include_entities)
				};
				
				class ProfileBannerParameters : public ITwitterParameters {
				public:
					INIT(ProfileBannerParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/users/profile_banner.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
				};
				
				class SearchParameters : public ITwitterParameters {
				public:
					INIT(SearchParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/users/search.json")

					PARAMETER(std::string, q)
					PARAMETER(uint64_t, page)
					PARAMETER(uint64_t, count)
					PARAMETER(bool, include_entities)
				};
				
				class ShowParameters : public ITwitterParameters {
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/users/show.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(bool, include_entities)
				};
				
				class SuggestionsParameters : public ITwitterParameters {
					INIT(SuggestionsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/users/suggestions.json")

					PARAMETER(std::string, lang)
				};
				
				namespace Suggestions {
					class ListParameters : public ITwitterParameters {
					public:
						INIT(ListParameters)
						METHOD(RequestMethod::GET)
						const std::string &request_url() const override
						{
							std::stringstream ss;
							ss << "https://api.twitter.com/1.1/users/suggestions/";
							ss << parameters.at("slug");
							ss << ".json";
							const auto _url = ss.str();
							return _url;
						}

						PARAMETER(std::string, slug)
						PARAMETER(std::string, lang)
					};
					
					class MembersParameters : public ITwitterParameters {
					public:
						INIT(MembersParameters)
						METHOD(RequestMethod::GET)
						const std::string &request_url() const override
						{
							std::stringstream ss;
							ss << "https://api.twitter.com/1.1/users/suggestions/";
							ss << parameters.at("slug");
							ss << "/members.json";
							const auto _url = ss.str();
							return _url;
						}

						PARAMETER(std::string, slug)
					};
				}
			}
		}
		
		namespace POST {
			namespace Users {
				class ReportSpamParameters : public ITwitterParameters {
					INIT(ReportSpamParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/users/report_spam.json")

					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
				};
			}
		}
	}
}

#endif // __PARAMETERS_USERS_H__
