#ifndef __PARAMETERS_GEO_H__
#define __PARAMETERS_GEO_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Geo {
			class IdParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				const std::string &url() const {
					std::stringstream ss;
					ss << "https://api.twitter.com/1.1/geo/id/";
					ss << parameters.at("place_id");
					ss << ".json";
					static const std::string _url = ss.str();
					return _url;
				}
				
				PARAMETER_STRING(IdParameter, place_id);
			};
			
			class ReverseGeocodeParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/geo/reverse_geocode.json");
				
				PARAMETER_DOUBLE(ReverseGeocodeParameter, lat);
				PARAMETER_DOUBLE(ReverseGeocodeParameter, lng);
				PARAMETER_STRING(ReverseGeocodeParameter, accuracy);
				PARAMETER_STRING(ReverseGeocodeParameter, granularity);
				PARAMETER_UINT64(ReverseGeocodeParameter, max_results);
				// not sure
				PARAMETER_STRING(ReverseGeocodeParameter, callback);
			};
			
			class SearchParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/geo/search.json");
				
				PARAMETER_DOUBLE(SearchParameter, lat);
				PARAMETER_DOUBLE(SearchParameter, lng);
				PARAMETER_STRING(SearchParameter, query);
				PARAMETER_STRING(SearchParameter, ip);
				PARAMETER_STRING(SearchParameter, accuracy);
				PARAMETER_STRING(SearchParameter, granularity);
				PARAMETER_UINT64(SearchParameter, max_results);
				PARAMETER_STRING(SearchParameter, contained_within);
				SearchParameter& attribute_street_address(const std::string &_attribute_street_address) {
					parameters["attribute:street_address"] = _attribute_street_address;
					return *this;
				}
				const std::string& attribute_street_address() {
					return parameters["attribute:street_address"];
				}
				// not sure
				PARAMETER_STRING(SearchParameter, callback);
			};
		}
	}
}

#endif // __PARAMETERS_GEO_H__
