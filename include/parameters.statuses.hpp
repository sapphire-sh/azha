#ifndef __PARAMETERS_STATUSES_H__
#define __PARAMETERS_STATUSES_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Statuses {
			class MentionsTimelineParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("");
				
				PARAMETER_UINT64(MentionsTimelineParameters, count);
				PARAMETER_UINT64(MentionsTimelineParameters, since_id);
				PARAMETER_UINT64(MentionsTimelineParameters, max_id);
				PARAMETER_BOOL(MentionsTimelineParameters, trim_user);
				PARAMETER_BOOL(MentionsTimelineParameters, contributor_details);
				PARAMETER_BOOL(MentionsTimelineParameters, include_entities);
			};
			
			class UpdateParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::POST);
				URL("https://api.twitter.com/1.1/statuses/update.json");
				
				PARAMETER_STRING(UpdateParameters, status);
				PARAMETER_UINT64(UpdateParameters, in_reply_to_status_id);
				PARAMETER_BOOL(UpdateParameters, possibly_sensitive);
				PARAMETER_DOUBLE(UpdateParameters, lat);
				PARAMETER_DOUBLE(UpdateParameters, lng);
				PARAMETER_STRING(UpdateParameters, place_id);
				PARAMETER_BOOL(UpdateParameters, display_coordinates);
				PARAMETER_BOOL(UpdateParameters, trim_user);
				PARAMETER_UINT64(UpdateParameters, media_ids);
			};
		}
	}
}

#endif // __PARAMETERS_STATUSES_H__
