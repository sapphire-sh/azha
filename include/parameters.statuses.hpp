#ifndef __PARAMETERS_STATUSES_H__
#define __PARAMETERS_STATUSES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Statuses {
				class HomeTimelineParameters : public ITwitterParameters {
				public:
					INIT(HomeTimelineParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/home_timeline.json")

					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, trim_user)
					PARAMETER(bool, contributor_details)
					PARAMETER(bool, include_entities)
				};
				
				class LookupParameters : public ITwitterParameters {
				public:
					INIT(LookupParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/lookup.json")

					PARAMETER(std::string, id)
				};
				
				class MentionsTimelineParameters : public ITwitterParameters {
				public:
					INIT(MentionsTimelineParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/mentions_timeline.json")

					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, trim_user)
					PARAMETER(bool, contributor_details)
					PARAMETER(bool, include_entities)
				};
				
				class OembedParameters : public ITwitterParameters {
				public:
					INIT(OembedParameters)
					METHOD(RequestMethod::GET)
					URL("https://publish.twitter.com/oembed")

					PARAMETER(std::string, url)
					PARAMETER(uint64_t, maxwidth)
					PARAMETER(bool, hide_media)
					PARAMETER(bool, hide_thread)
					PARAMETER(bool, omit_script)
					PARAMETER(std::string, aligh)
					PARAMETER(std::string, related)
					PARAMETER(std::string, lang)
					PARAMETER(std::string, theme)
					PARAMETER(std::string, link_color)
					PARAMETER(std::string, widget_type)
				};
				
				namespace Retweeters {
					class IdsParameters : public ITwitterParameters {
					public:
						INIT(IdsParameters)
						METHOD(RequestMethod::GET)
						URL("https://api.twitter.com/1.1/statuses/retweeters/ids.json")

						PARAMETER(uint64_t, id)
						PARAMETER(uint64_t, cursor)
						PARAMETER(bool, stringify_ids)
					};
				}
				
				namespace Retweets {
					class ListParameters : public ITwitterParameters {
					public:
						INIT(ListParameters)
						METHOD(RequestMethod::GET)
						const std::string &request_url() const override {
							std::stringstream ss;
							ss << "https://api.twitter.com/1.1/statuses/retweets/";
							ss << parameters.at("id");
							ss << ".json";
							const std::string _url = ss.str();
							return _url;
						}

						PARAMETER(uint64_t, id)
						PARAMETER(uint64_t, count)
						PARAMETER(bool, trim_user)
					};
				}

				class RetweetsOfMeParameters : public ITwitterParameters {
				public:
					INIT(RetweetsOfMeParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/retweets_of_me.json")

					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, trim_user)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, include_user_entities)
				};

				class ShowParameters : public ITwitterParameters {
				public:
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/show.json")

					PARAMETER(uint64_t, id)
					PARAMETER(bool, trim_user)
					PARAMETER(bool, include_my_retweet)
					PARAMETER(bool, include_entities)
				};

				class UserTimelineParameters : public ITwitterParameters {
				public:
					INIT(UserTimelineParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/statuses/user_timeline.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, since_id)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, max_id)
					PARAMETER(bool, trim_user)
					PARAMETER(bool, exclude_replies)
					PARAMETER(bool, contributor_details)
					PARAMETER(bool, include_rts)
				};
			}
		}
		
		namespace POST {
			namespace Statuses {
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					const std::string &request_url() const override {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/destroy/";
						ss << parameters.at("id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}

					PARAMETER(uint64_t, id)
					PARAMETER(bool, trim_user)
				};
				
				class RetweetParameters : public ITwitterParameters {
				public:
					INIT(RetweetParameters)
					METHOD(RequestMethod::POST)
					const std::string &request_url() const override {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/retweet/";
						ss << parameters.at("id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}

					PARAMETER(uint64_t, id)
					PARAMETER(bool, trim_user)
				};
				
				class UnretweetParameters : public ITwitterParameters {
				public:
					INIT(UnretweetParameters)
					METHOD(RequestMethod::POST)
					const std::string &request_url() const override {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/unretweet/";
						ss << parameters.at("id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}

					PARAMETER(uint64_t, id)
					PARAMETER(bool, trim_user)
				};
				
				class UpdateParameters : public ITwitterParameters {
				public:
					INIT(UpdateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/statuses/update.json")

					PARAMETER(std::string, status)
					PARAMETER(uint64_t, in_reply_to_status_id)
					PARAMETER(bool, possibly_sensitive)
					PARAMETER(double, lat)
					PARAMETER(double, lng)
					PARAMETER(std::string, place_id)
					PARAMETER(bool, display_coordinates)
					PARAMETER(bool, trim_user)
					PARAMETER(std::string, media_ids)
				};
			}
		}
	}
}

#endif // __PARAMETERS_STATUSES_H__
