#ifndef __PARAMETERS_MEDIA_H__
#define __PARAMETERS_MEDIA_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace POST {
			namespace Media {
				class UploadParameters : public ITwitterParameters {
				public:
					INIT(UploadParameters)
					METHOD(RequestMethod::POST)
					URL("https://upload.twitter.com/1.1/media/upload.json")

					PARAMETER(std::string, media)
					PARAMETER(std::string, media_data)
					PARAMETER(std::string, additional_owners)
				};
			}
		}
	}
}

#endif // __PARAMETERS_MEDIA_H__
