#ifndef __PARAMETERS_TRENDS_H__
#define __PARAMETERS_TRENDS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Trends {
				class AvailableParameters : public ITwitterParameters {
				public:
					INIT(AvailableParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/trends/available.json")
				};
				
				class ClosestParameters : public ITwitterParameters {
				public:
					INIT(ClosestParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/trends/closest.json")

					PARAMETER(double, lat)
					PARAMETER(double, lng)
				};
				
				class PlaceParameters : public ITwitterParameters {
				public:
					INIT(PlaceParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/trends/place.json")

					PARAMETER(uint64_t, id)
					PARAMETER(std::string, exclude)
				};
			}
		}
	}
}

#endif // __PARAMETERS_TRENDS_H__
