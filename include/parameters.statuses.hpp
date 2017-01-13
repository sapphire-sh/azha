#ifndef __PARAMETERS_STATUSES_H__
#define __PARAMETERS_STATUSES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Statuses {
				class HomeTimelineParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/home_timeline.json");
					
					PARAMETER_UINT64(HomeTimelineParameters, count);
					PARAMETER_UINT64(HomeTimelineParameters, since_id);
					PARAMETER_UINT64(HomeTimelineParameters, max_id);
					PARAMETER_BOOL(HomeTimelineParameters, trim_user);
					PARAMETER_BOOL(HomeTimelineParameters, contributor_details);
					PARAMETER_BOOL(HomeTimelineParameters, include_entities);
				};
				
				class LookupParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/lookup.json");
					
					PARAMETER_STRING(LookupParameters, id);
				};
				
				class MentionsTimelineParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/mentions_timeline.json");
					
					PARAMETER_UINT64(MentionsTimelineParameters, count);
					PARAMETER_UINT64(MentionsTimelineParameters, since_id);
					PARAMETER_UINT64(MentionsTimelineParameters, max_id);
					PARAMETER_BOOL(MentionsTimelineParameters, trim_user);
					PARAMETER_BOOL(MentionsTimelineParameters, contributor_details);
					PARAMETER_BOOL(MentionsTimelineParameters, include_entities);
				};
				
				class OembedParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://publish.twitter.com/oembed");
					
					PARAMETER_STRING(OembedParameters, url);
					PARAMETER_UINT64(OembedParameters, maxwidth);
					PARAMETER_BOOL(OembedParameters, hide_media);
					PARAMETER_BOOL(OembedParameters, hide_thread);
					PARAMETER_BOOL(OembedParameters, omit_script);
					PARAMETER_STRING(OembedParameters, aligh);
					PARAMETER_STRING(OembedParameters, related);
					PARAMETER_STRING(OembedParameters, lang);
					PARAMETER_STRING(OembedParameters, theme);
					PARAMETER_STRING(OembedParameters, link_color);
					PARAMETER_STRING(OembedParameters, widget_type);
				};
				
				namespace Retweeters {
					class IdsParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::GET);
						URL("https://api.twitter.com/1.1/statuses/retweeters/ids.json");
						
						PARAMETER_UINT64(IdsParameters, id);
						PARAMETER_UINT64(IdsParameters, cursor);
						PARAMETER_BOOL(IdsParameters, stringify_ids);
					};
				}
				
				namespace Retweets {
					class ListParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::GET);
						const std::string &url() const {
							std::stringstream ss;
							ss << "https://api.twitter.com/1.1/statuses/retweets/";
							ss << parameters.at("id");
							ss << ".json";
							static const std::string _url = ss.str();
							return _url;
						}
						
						PARAMETER_UINT64(ListParameters, id);
						PARAMETER_UINT64(ListParameters, count);
						PARAMETER_BOOL(ListParameters, trim_user);
					};
				}
				
				class RetweetsOfMeParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/retweets_of_me.json");
					
					PARAMETER_UINT64(RetweetsOfMeParameters, count);
					PARAMETER_UINT64(RetweetsOfMeParameters, since_id);
					PARAMETER_UINT64(RetweetsOfMeParameters, max_id);
					PARAMETER_BOOL(RetweetsOfMeParameters, trim_user);
					PARAMETER_BOOL(RetweetsOfMeParameters, include_entities);
					PARAMETER_BOOL(RetweetsOfMeParameters, include_user_entities);
				};
				
				class ShowParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/show.json");
					
					PARAMETER_UINT64(ShowParameters, id);
					PARAMETER_BOOL(ShowParameters, trim_user);
					PARAMETER_BOOL(ShowParameters, include_my_retweet);
					PARAMETER_BOOL(ShowParameters, include_entities);
				};
				
				class UserTimelineParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/statuses/user_timeline.json");
					
					PARAMETER_UINT64(UserTimelineParameters, user_id);
					PARAMETER_STRING(UserTimelineParameters, screen_name);
					PARAMETER_UINT64(UserTimelineParameters, since_id);
					PARAMETER_UINT64(UserTimelineParameters, count);
					PARAMETER_UINT64(UserTimelineParameters, max_id);
					PARAMETER_BOOL(UserTimelineParameters, trim_user);
					PARAMETER_BOOL(UserTimelineParameters, exclude_replies);
					PARAMETER_BOOL(UserTimelineParameters, contributor_details);
					PARAMETER_BOOL(UserTimelineParameters, include_rts);
				};
			}
		}
		
		namespace POST {
			namespace Statuses {
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/destroy/";
						ss << parameters.at("id");
						ss << ".json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_UINT64(DestroyParameters, id);
					PARAMETER_BOOL(DestroyParameters, trim_user);
				};
				
				class RetweetParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/retweet/";
						ss << parameters.at("id");
						ss << ".json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_UINT64(RetweetParameters, id);
					PARAMETER_BOOL(RetweetParameters, trim_user);
				};
				
				class UnretweetParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/statuses/unretweet/";
						ss << parameters.at("id");
						ss << ".json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_UINT64(UnretweetParameters, id);
					PARAMETER_BOOL(UnretweetParameters, trim_user);
				};
				
				class UpdateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/statuses/update.json");
					
					PARAMETER_STRING(UpdateParameters, status);
					PARAMETER_UINT64(UpdateParameters, in_reply_to_status_id);
					PARAMETER_BOOL(UpdateParameters, possibly_sensitive);
					PARAMETER_DOUBLE(UpdateParameters, lat);
					PARAMETER_DOUBLE(UpdateParameters, lng);
					PARAMETER_STRING(UpdateParameters, place_id);
					PARAMETER_BOOL(UpdateParameters, display_coordinates);
					PARAMETER_BOOL(UpdateParameters, trim_user);
					PARAMETER_STRING(UpdateParameters, media_ids);
				};
			}
		}
	}
}

#endif // __PARAMETERS_STATUSES_H__
