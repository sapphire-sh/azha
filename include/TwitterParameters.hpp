#ifndef __TWITTER_PARAMETERS__
#define __TWITTER_PARAMETERS__

#include <map>
#include <unordered_map>
#include <string>
#include <sstream>

#include <curl/curl.h>

namespace azha {
	namespace Parameters {
		enum class RequestType {
			GET,
			POST
		};
		
		class ITwitterParameters {
		public:
			RequestType request_type;
			std::string url;
			
			std::string parameter_string(std::unordered_map<std::string, std::string>& parameters) {
				CURL* curl = curl_easy_init();
				
				std::map<std::string, std::string> p;
				
				for(auto iter = parameters.begin(); iter != parameters.end(); ++iter) {
					auto f = iter->first.find_last_of("_");
					std::string k = iter->first.substr(f + 1);
					if(k != "signature" && k != "secret") {
						p[iter->first] = iter->second;
					}
				}
				for(auto iter = queries.begin(); iter != queries.end(); ++iter) {
					p[iter->first] = iter->second;
				}
				
				std::stringstream ss;
				
				for(auto iter = p.begin(); iter != p.end(); ++iter) {
					ss << iter->first << "=" << curl_easy_escape(curl, iter->second.c_str(), iter->second.size()) << "&";
				}
				
				std::string parameter_string = ss.str();
				parameter_string.pop_back();
				
				return parameter_string;
			};
		protected:
			std::unordered_map<std::string, std::string> queries;
		};
		
		namespace Statuses {
			class MentionsTimelineParameters : public ITwitterParameters {
			public:
				MentionsTimelineParameters() {
					request_type = RequestType::GET;
				}
				
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
					request_type = RequestType::POST;
					url = "https://api.twitter.com/1.1/statuses/update.json";
					
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
