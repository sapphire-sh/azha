#ifndef __PARAMETERS_GEO_H__
#define __PARAMETERS_GEO_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Geo {
				class IdParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					const std::string &url() const {
						std::stringstream ss;
						ss << "https://api.twitter.com/1.1/geo/id/";
						ss << parameters.at("place_id");
						ss << ".json";
						static const std::string _url = ss.str();
						return _url;
					}
					
					PARAMETER_STRING(IdParameters, place_id);
				};
				
				class ReverseGeocodeParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/geo/reverse_geocode.json");
					
					PARAMETER_DOUBLE(ReverseGeocodeParameters, lat);
					PARAMETER_DOUBLE(ReverseGeocodeParameters, lng);
					PARAMETER_STRING(ReverseGeocodeParameters, accuracy);
					PARAMETER_STRING(ReverseGeocodeParameters, granularity);
					PARAMETER_UINT64(ReverseGeocodeParameters, max_results);
					// not sure
					PARAMETER_STRING(ReverseGeocodeParameters, callback);
				};
				
				class SearchParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/geo/search.json");
					
					PARAMETER_DOUBLE(SearchParameters, lat);
					PARAMETER_DOUBLE(SearchParameters, lng);
					PARAMETER_STRING(SearchParameters, query);
					PARAMETER_STRING(SearchParameters, ip);
					PARAMETER_STRING(SearchParameters, accuracy);
					PARAMETER_STRING(SearchParameters, granularity);
					PARAMETER_UINT64(SearchParameters, max_results);
					PARAMETER_STRING(SearchParameters, contained_within);
					SearchParameters& attribute_street_address(const std::string &_attribute_street_address) {
						parameters["attribute:street_address"] = _attribute_street_address;
						return *this;
					}
					const std::string& attribute_street_address() {
						return parameters["attribute:street_address"];
					}
					// not sure
					PARAMETER_STRING(SearchParameters, callback);
				};
			}
		}
		
		namespace POST {
			namespace Geo {
				class PlaceParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/geo/place.json");
					
					PARAMETER_STRING(PlaceParameters, name);
					PARAMETER_STRING(PlaceParameters, contained_within);
					PARAMETER_STRING(PlaceParameters, token);
					PARAMETER_DOUBLE(PlaceParameters, lat);
					PARAMETER_DOUBLE(PlaceParameters, lng);
					PlaceParameters& attribute_street_address(const std::string &_attribute_street_address) {
						parameters["attribute:street_address"] = _attribute_street_address;
						return *this;
					}
					const std::string& attribute_street_address() {
						return parameters["attribute:street_address"];
					}
					// not sure
					PARAMETER_STRING(PlaceParameters, callback);
				};
			}
		}
	}
}

#endif // __PARAMETERS_GEO_H__
