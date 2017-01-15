#ifndef __PARAMETERS_GEO_H__
#define __PARAMETERS_GEO_H__

#include <sstream>

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Geo {
				class IdParameters : public ITwitterParameters {
				public:
					INIT(IdParameters)
					METHOD(RequestMethod::GET)
					const std::string &request_url() const override {
						std::ostringstream ss;
						ss << "https://api.twitter.com/1.1/geo/id/";
						ss << parameters.at("place_id");
						ss << ".json";
						const std::string _url = ss.str();
						return _url;
					}

					PARAMETER(std::string, place_id)
				};
				
				class ReverseGeocodeParameters : public ITwitterParameters {
				public:
					INIT(ReverseGeocodeParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/geo/reverse_geocode.json")

					PARAMETER(double, lat)
					PARAMETER(double, lng)
					PARAMETER(std::string, accuracy)
					PARAMETER(std::string, granularity)
					PARAMETER(uint64_t, max_results)
					// not sure PARAMETER(std::string, callback)
				};
				
				class SearchParameters : public ITwitterParameters {
				public:
					INIT(SearchParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/geo/search.json")

					PARAMETER(double, lat)
					PARAMETER(double, lng)
					PARAMETER(std::string, query)
					PARAMETER(std::string, ip)
					PARAMETER(std::string, accuracy)
					PARAMETER(std::string, granularity)
					PARAMETER(uint64_t, max_results)
					PARAMETER(std::string, contained_within)
					PARAMETER_ALIAS(std::string, attribute_street_address, attribute:street_address)
					// not sure PARAMETER(std::string, callback)
				};
			}
		}
		
		namespace POST {
			namespace Geo {
				class PlaceParameters : public ITwitterParameters {
				public:
					INIT(PlaceParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/geo/place.json")

					PARAMETER(std::string, name)
					PARAMETER(std::string, contained_within)
					PARAMETER(std::string, token)
					PARAMETER(double, lat)
					PARAMETER(double, lng)
					PARAMETER_ALIAS(std::string, attribute_street_address, attribute:street_address)
					// not sure PARAMETER(std::string, callback)
				};
			}
		}
	}
}

#endif // __PARAMETERS_GEO_H__
