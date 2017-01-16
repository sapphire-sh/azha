#ifndef __RESPONSE_OAUTH_H__
#define __RESPONSE_OAUTH_H__

#include "response.interface.hpp"

namespace azha {
	namespace response {
		class OAuth : public ITwitterResponse {
		public:
			std::unique_ptr<std::string> oauth_token;
			std::unique_ptr<std::string> oauth_token_secret;
			std::unique_ptr<bool> oauth_callback_confirmed;
			std::unique_ptr<uint64_t> user_id;
			std::unique_ptr<std::string> screen_name;
		};
	}
}

#endif // __RESPONSE_OAUTH_H__
