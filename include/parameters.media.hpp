#ifndef __PARAMETERS_APPLICATION_H__
#define __PARAMETERS_APPLICATION_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace POST {
			namespace Media {
				class UploadParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://upload.twitter.com/1.1/media/upload.json");
					
					PARAMETER_STRING(UploadParameters, media);
					PARAMETER_STRING(UploadParameters, media_data);
					PARAMETER_STRING(UploadParameters, additional_owners);
				};
			}
		}
	}
}

#endif // __PARAMETERS_APPLICATION_H__
