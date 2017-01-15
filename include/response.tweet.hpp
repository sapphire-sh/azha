#ifndef __RESPONSE_TWEETS_H__
#define __RESPONSE_TWEETS_H__

#include "response.interface.hpp"

#include "response.coordinates.hpp"
#include "response.entities.hpp"
#include "response.places.hpp"
#include "response.user.hpp"

namespace azha {
	namespace response {
		class Tweet : public ITwitterResponse {
		public:
			std::unique_ptr<Coordinates> coordinates;
			std::unique_ptr<std::string> created_at;
			// Object current_user_retweet;
			std::unique_ptr<Entities> entities;
			std::unique_ptr<uint64_t> favorite_count;
			std::unique_ptr<bool> favorited;
			std::unique_ptr<std::string> filter_level;
			std::unique_ptr<uint64_t> id;
			std::unique_ptr<std::string> id_str;
			std::unique_ptr<std::string> in_reply_to_screen_name;
			std::unique_ptr<uint64_t> in_reply_to_status_id;
			std::unique_ptr<std::string> in_reply_to_status_id_str;
			std::unique_ptr<uint64_t> in_reply_to_user_id;
			std::unique_ptr<std::string> in_reply_to_user_id_str;
			std::unique_ptr<std::string> lang;
			std::unique_ptr<Places> place;
			std::unique_ptr<bool> possibly_sensitive;
			std::unique_ptr<uint64_t> quoted_status_id;
			std::unique_ptr<std::string> quoted_status_id_str;
			std::unique_ptr<Tweet> quoted_status;
			// Object scopes;
			std::unique_ptr<uint64_t> retweeted_count;
			std::unique_ptr<bool> retweeted;
			std::unique_ptr<Tweet> retweeted_status;
			std::unique_ptr<std::string> source;
			std::unique_ptr<std::string> text;
			std::unique_ptr<bool> truncated;
			std::unique_ptr<User> user;
			std::unique_ptr<bool> withheld_copyright;
			std::unique_ptr<std::vector<std::string>> withheld_in_countries;
			std::unique_ptr<std::string> withheld_scope;
		};
	}
}

#endif // __RESPONSE_TWEETS_H__
