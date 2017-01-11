#ifndef __PARAMETERS_BLOCKS_H__
#define __PARAMETERS_BLOCKS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Blocks {
			class IdsParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/ids.json");
				
				PARAMETER_BOOL(IdsParameters, stringify_ids);
				PARAMETER_UINT64(IdsParameters, cursor);
			};
			
			class ListParameters : public ITwitterParameters {
			public:
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/list.json");
				
				PARAMETER_BOOL(ListParameters, include_entities);
				PARAMETER_BOOL(ListParameters, skip_status);
				PARAMETER_UINT64(ListParameters, cursor);
			};
		}
	}
}

#endif // __PARAMETERS_BLOCKS_H__
