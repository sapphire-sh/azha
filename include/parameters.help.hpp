#ifndef __PARAMETERS_HELP_H__
#define __PARAMETERS_HELP_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Help {
			class ConfigurationParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/help/configuration.json");
			};
			
			class LanguagesParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/help/languages.json");
			};
			
			class PrivacyParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/help/privacy.json");
			};
			
			class TosParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/help/tos.json");
			};
		}
	}
}

#endif // __PARAMETERS_HELP_H__
