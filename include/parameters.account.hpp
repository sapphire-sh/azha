#ifndef __PARAMETERS_ACCOUNT_H__
#define __PARAMETERS_ACCOUNT_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Account {
				class SettingsParameters : public ITwitterParameters {
				public:
					INIT(SettingsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/account/settings.json")
				};
				
				class VerifyCredentialsParameters : public ITwitterParameters {
				public:
					INIT(VerifyCredentialsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/account/verify_credentials.json")
					
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
					PARAMETER(bool, include_email)
				};
			}
		}
		
		namespace POST {
			namespace Account {
				class RemoveProfileBannerParameters : public ITwitterParameters {
				public:
					INIT(RemoveProfileBannerParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/remove_profile_banner.json")
				};
				
				class SettingsParameters : public ITwitterParameters {
				public:
					INIT(SettingsParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/settings.json")
					
					PARAMETER(bool, sleep_time_enabled)
					PARAMETER(uint64_t, start_sleep_time)
					PARAMETER(uint64_t, end_sleep_time)
					PARAMETER(std::string, time_zone)
					PARAMETER(uint64_t, trend_location_woeid)
					PARAMETER(std::string, lang)
				};
				
				class UpdateProfileParameters : public ITwitterParameters {
				public:
					INIT(UpdateProfileParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/update_profile.json")
					
					PARAMETER(std::string, name)
					PARAMETER(std::string, url)
					PARAMETER(std::string, location)
					PARAMETER(std::string, description)
					PARAMETER(std::string, profile_link_color)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
				
				class UpdateProfileBackgroundImageParameters : public ITwitterParameters {
				public:
					INIT(UpdateProfileBackgroundImageParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/update_profile_background_image.json")
					
					PARAMETER(std::string, image)
					PARAMETER(bool, tile)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
					PARAMETER(std::string, media_id)
				};
				
				class UpdateProfileBannerParameters : public ITwitterParameters {
				public:
					INIT(UpdateProfileBannerParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/update_profile_banner.json")

					PARAMETER(std::string, banner)
					PARAMETER(uint64_t, width)
					PARAMETER(uint64_t, height)
					PARAMETER(uint64_t, offset_left)
					PARAMETER(uint64_t, offset_top)
				};
				
				class UpdateProfileImageParameters : public ITwitterParameters {
				public:
					INIT(UpdateProfileImageParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/account/update_profile_image.json")
					
					PARAMETER(std::string, image)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
			}
		}
	}
}

#endif // __PARAMETERS_ACCOUNT_H__
