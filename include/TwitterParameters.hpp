#ifndef __TWITTER_PARAMETERS__
#define __TWITTER_PARAMETERS__

#include <unordered_map>
#include <string>
#include <sstream>

namespace azha {
	namespace Parameters {
		class ITwitterParameters {
		public:
			virtual ~ITwitterParameters();
			std::string composeQueryString() {
				std::stringstream ss;
				ss << "?";
				
				for(auto iter = queries.begin(); iter != queries.end(); ++iter) {
					ss << iter->first << "=" << iter->second << "&";
				}
				
				std::string queryString = ss.str();
				queryString.pop_back();
				
				return queryString;
			};
		protected:
			std::unordered_map<std::string, std::string> queries;
		};
		
		namespace Statuses {
			class MentionsTimelineParameters : public ITwitterParameters {
			public:
				MentionsTimelineParameters& count(const uint64_t _count) {
					queries["count"] = std::to_string(_count);
					return *this;
				}
				MentionsTimelineParameters& since_id(const uint64_t _since_id) {
					queries["since_id"] = std::to_string(_since_id);
					return *this;
				}
				MentionsTimelineParameters& max_id(const uint64_t _max_id) {
					queries["max_id"] = std::to_string(_max_id);
					return *this;
				}
				MentionsTimelineParameters& trim_user(const bool _trim_user) {
					queries["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& contributor_details(const bool _contributor_details) {
					queries["contributor_details"] = _contributor_details ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& include_entities(const bool _include_entities) {
					queries["include_entities"] = _include_entities ? "true" : "false";
					return *this;
				}
				
				const uint64_t count() {
					return std::stoull(queries["count"]);
				}
				const uint64_t since_id() {
					return std::stoull(queries["since_id"]);
				}
				const uint64_t max_id() {
					return std::stoull(queries["max_id"]);
				}
				const bool trim_user() {
					return (queries["trim_user"] == "true");
				}
				const bool contributor_details() {
					return (queries["contributor_details"] == "true");
				}
				const bool include_entities() {
					return (queries["include_entities"] == "true");
				}
			};
			
			class UpdateParameters : public ITwitterParameters {
			public:
				UpdateParameters(const std::string& _status) {
					status(_status);
				}
				
				UpdateParameters& status(const std::string& _status) {
					queries["status"] = _status;
					return *this;
				}
				UpdateParameters& in_reply_to_status_id(const uint64_t _in_reply_to_status_id) {
					queries["in_reply_to_status_id"] = std::to_string(_in_reply_to_status_id);
					return *this;
				}
				UpdateParameters& possibly_sensitive(const bool _possibly_sensitive) {
					queries["possibly_sensitive"] = _possibly_sensitive ? "true" : "false";
					return *this;
				}
				UpdateParameters& lat(const double _lat) {
					queries["lat"] = std::to_string(_lat);
					return *this;
				}
				UpdateParameters& lng(const double _lng) {
					queries["long"] = std::to_string(_lng);
					return *this;
				}
				UpdateParameters& place_id(const std::string& _place_id) {
					queries["place_id"] = _place_id;
					return *this;
				}
				UpdateParameters& display_coordinates(const bool _display_coordinates) {
					queries["display_coordinates"] = _display_coordinates ? "true" : "false";
					return *this;
				}
				UpdateParameters& trim_user(const bool _trim_user) {
					queries["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				UpdateParameters& media_ids(const uint64_t _media_ids) {
					queries["media_ids"] = std::to_string(_media_ids);
					return *this;
				}
				
				const std::string& status() {
					return queries["status"];
				}
				const uint64_t in_reply_to_status_id() {
					return std::stoull(queries["in_reply_to_status_id"]);
				}
				const bool possibly_sensitive() {
					return (queries["possibly_sensitive"] == "true");
				}
				const double lat() {
					return std::stod(queries["lat"]);
				}
				const double lng() {
					return std::stod(queries["lng"]);
				}
				const std::string& place_id() {
					return queries["place_id"];
				}
				const bool display_coordinates() {
					return (queries["display_coordinates"] == "true");
				}
				const bool trim_user() {
					return (queries["trim_user"] == "true");
				}
				const uint64_t media_ids() {
					return std::stoull(queries["media_ids"]);
				}
			};
		}
	}
}

#endif // __TWITTER_PARAMETERS__
