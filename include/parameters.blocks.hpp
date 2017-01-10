#ifndef __PARAMETERS_BLOCKS_H__
#define __PARAMETERS_BLOCKS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Blocks {
			class IdsParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/ids.json");
				
				PARAMETER_BOOL(IdsParameter, stringify_ids);
				PARAMETER_UINT64(IdsParameter, cursor);
			};
			
			class ListParameter : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/list.json");
				
				PARAMETER_BOOL(ListParameter, include_entities);
				PARAMETER_BOOL(ListParameter, skip_status);
				PARAMETER_UINT64(ListParameter, cursor);
			};
		}
	}
}

#endif // __PARAMETERS_BLOCKS_H__
