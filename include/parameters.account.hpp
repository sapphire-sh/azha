#ifndef __PARAMETERS_ACCOUNT_H__
#define __PARAMETERS_ACCOUNT_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Account {
				class SettingsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/account/settings.json");
				};
				
				class VerifyCredentialsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/account/verify_credentials.json");
					
					PARAMETER_BOOL(VerifyCredentialsParameters, include_entities);
					PARAMETER_BOOL(VerifyCredentialsParameters, skip_status);
					PARAMETER_BOOL(VerifyCredentialsParameters, include_email);
				};
			}
		}
		
		namespace POST {
			namespace Account {
				class RemoveProfileBannerParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/remove_profile_banner.json");
				};
				
				class SettingsParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/settings.json");
					
					PARAMETER_BOOL(SettingsParameters, sleep_time_enabled);
					PARAMETER_UINT64(SettingsParameters, start_sleep_time);
					PARAMETER_UINT64(SettingsParameters, end_sleep_time);
					PARAMETER_STRING(SettingsParameters, time_zone);
					PARAMETER_UINT64(SettingsParameters, trend_location_woeid);
					PARAMETER_STRING(SettingsParameters, lang);
				};
				
				class UpdateProfileParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/update_profile.json");
					
					PARAMETER_STRING(UpdateProfileParameters, name);
					PARAMETER_STRING(UpdateProfileParameters, url);
					PARAMETER_STRING(UpdateProfileParameters, location);
					PARAMETER_STRING(UpdateProfileParameters, description);
					PARAMETER_STRING(UpdateProfileParameters, profile_link_color);
					PARAMETER_BOOL(UpdateProfileParameters, include_entities);
					PARAMETER_BOOL(UpdateProfileParameters, skip_status);
				};
				
				class UpdateProfileBackgroundImageParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/update_profile_background_image.json");
					
					PARAMETER_STRING(UpdateProfileBackgroundImageParameters, image);
					PARAMETER_BOOL(UpdateProfileBackgroundImageParameters, tile);
					PARAMETER_BOOL(UpdateProfileBackgroundImageParameters, include_entities);
					PARAMETER_BOOL(UpdateProfileBackgroundImageParameters, skip_status);
					PARAMETER_STRING(UpdateProfileBackgroundImageParameters, media_id);
				};
				
				class UpdateProfileBannerParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/update_profile_banner.json");
					
					PARAMETER_STRING(UpdateProfileBannerParameters, banner);
					PARAMETER_UINT64(UpdateProfileBannerParameters, width);
					PARAMETER_UINT64(UpdateProfileBannerParameters, height);
					PARAMETER_UINT64(UpdateProfileBannerParameters, offset_left);
					PARAMETER_UINT64(UpdateProfileBannerParameters, offset_top);
				};
				
				class UpdateProfileImageParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/account/update_profile_image.json");
					
					PARAMETER_STRING(UpdateProfileImageParameters, image);
					PARAMETER_BOOL(UpdateProfileImageParameters, include_entities);
					PARAMETER_BOOL(UpdateProfileImageParameters, skip_status);
				};
			}
		}
	}
}

#endif // __PARAMETERS_ACCOUNT_H__
