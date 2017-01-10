#ifndef __PARAMETERS_STATUSES_H__
#define __PARAMETERS_STATUSES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Statuses {
			class MentionsTimelineParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::GET;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "";
					return _url;
				}
				
				MentionsTimelineParameters& count(const uint64_t _count) {
					parameters["count"] = std::to_string(_count);
					return *this;
				}
				MentionsTimelineParameters& since_id(const uint64_t _since_id) {
					parameters["since_id"] = std::to_string(_since_id);
					return *this;
				}
				MentionsTimelineParameters& max_id(const uint64_t _max_id) {
					parameters["max_id"] = std::to_string(_max_id);
					return *this;
				}
				MentionsTimelineParameters& trim_user(const bool _trim_user) {
					parameters["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& contributor_details(const bool _contributor_details) {
					parameters["contributor_details"] = _contributor_details ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& include_entities(const bool _include_entities) {
					parameters["include_entities"] = _include_entities ? "true" : "false";
					return *this;
				}
				
				const uint64_t count() {
					return std::stoull(parameters["count"]);
				}
				const uint64_t since_id() {
					return std::stoull(parameters["since_id"]);
				}
				const uint64_t max_id() {
					return std::stoull(parameters["max_id"]);
				}
				const bool trim_user() {
					return (parameters["trim_user"] == "true");
				}
				const bool contributor_details() {
					return (parameters["contributor_details"] == "true");
				}
				const bool include_entities() {
					return (parameters["include_entities"] == "true");
				}
			};
			
			class UpdateParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "https://api.twitter.com/1.1/statuses/update.json";
					return _url;
				}
				
				UpdateParameters& status(const std::string &_status) {
					parameters["status"] = _status;
					return *this;
				}
				UpdateParameters& in_reply_to_status_id(const uint64_t _in_reply_to_status_id) {
					parameters["in_reply_to_status_id"] = std::to_string(_in_reply_to_status_id);
					return *this;
				}
				UpdateParameters& possibly_sensitive(const bool _possibly_sensitive) {
					parameters["possibly_sensitive"] = _possibly_sensitive ? "true" : "false";
					return *this;
				}
				UpdateParameters& lat(const double _lat) {
					parameters["lat"] = std::to_string(_lat);
					return *this;
				}
				UpdateParameters& lng(const double _lng) {
					parameters["long"] = std::to_string(_lng);
					return *this;
				}
				UpdateParameters& place_id(const std::string &_place_id) {
					parameters["place_id"] = _place_id;
					return *this;
				}
				UpdateParameters& display_coordinates(const bool _display_coordinates) {
					parameters["display_coordinates"] = _display_coordinates ? "true" : "false";
					return *this;
				}
				UpdateParameters& trim_user(const bool _trim_user) {
					parameters["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				UpdateParameters& media_ids(const uint64_t _media_ids) {
					parameters["media_ids"] = std::to_string(_media_ids);
					return *this;
				}
				
				const std::string& status() {
					return parameters["status"];
				}
				const uint64_t in_reply_to_status_id() {
					return std::stoull(parameters["in_reply_to_status_id"]);
				}
				const bool possibly_sensitive() {
					return (parameters["possibly_sensitive"] == "true");
				}
				const double lat() {
					return std::stod(parameters["lat"]);
				}
				const double lng() {
					return std::stod(parameters["lng"]);
				}
				const std::string& place_id() {
					return parameters["place_id"];
				}
				const bool display_coordinates() {
					return (parameters["display_coordinates"] == "true");
				}
				const bool trim_user() {
					return (parameters["trim_user"] == "true");
				}
				const uint64_t media_ids() {
					return std::stoull(parameters["media_ids"]);
				}
			};
		}
	}
}

#endif // __PARAMETERS_STATUSES_H__
