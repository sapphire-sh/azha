#ifndef __PARAMETERS_BLOCKS_H__
#define __PARAMETERS_BLOCKS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace Blocks {
			class Ids : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/ids.json");
				
				PARAMETER_BOOL(Ids, stringify_ids);
				PARAMETER_UINT64(Ids, cursor);
			};
			
			class List : public ITwitterParameters {
				METHOD(RequestMethod::GET);
				URL("https://api.twitter.com/1.1/blocks/list.json");
				
				PARAMETER_BOOL(Ids, include_entities);
				PARAMETER_BOOL(Ids, skip_status);
				PARAMETER_UINT64(Ids, cursor);
			};
		}
	}
}

#endif // __PARAMETERS_BLOCKS_H__
