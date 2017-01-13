#ifndef __PARAMETERS_BLOCKS_H__
#define __PARAMETERS_BLOCKS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
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
		
		namespace POST {
			namespace Blocks {
				class CreateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/blocks/create.json");
					
					PARAMETER_STRING(CreateParameters, screen_name);
					PARAMETER_UINT64(CreateParameters, user_id);
					PARAMETER_BOOL(CreateParameters, include_entities);
					PARAMETER_BOOL(CreateParameters, skip_status);
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/blocks/destroy.json");
					
					PARAMETER_STRING(DestroyParameters, screen_name);
					PARAMETER_UINT64(DestroyParameters, user_id);
					PARAMETER_BOOL(DestroyParameters, include_entities);
					PARAMETER_BOOL(DestroyParameters, skip_status);
				};
			}
		}
	}
}

#endif // __PARAMETERS_BLOCKS_H__
