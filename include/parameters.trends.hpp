#ifndef __PARAMETERS_TRENDS_H__
#define __PARAMETERS_TRENDS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Trends {
				class AvailableParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/trends/available.json");
				};
				
				class ClosestParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/trends/closest.json");
					
					PARAMETER_DOUBLE(ClosestParameters, lat);
					PARAMETER_DOUBLE(ClosestParameters, lng);
				};
				
				class PlaceParameters : public ITwitterParameters {
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/trends/place.json");
					
					PARAMETER_UINT64(PlaceParameters, id);
					PARAMETER_STRING(PlaceParameters, exclude);
				};
			}
		}
	}
}

#endif // __PARAMETERS_TRENDS_H__
