#ifndef __PARAMETERS_BLOCKS_H__
#define __PARAMETERS_BLOCKS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Blocks {
				class IdsParameters : public ITwitterParameters {
				public:
					INIT(IdsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/blocks/ids.json")
					
					PARAMETER(bool, stringify_ids)
					PARAMETER(uint64_t, cursor)
				};
				
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/blocks/list.json")
					
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
					PARAMETER(uint64_t, cursor)
				};
			}
		}
		
		namespace POST {
			namespace Blocks {
				class CreateParameters : public ITwitterParameters {
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/blocks/create.json")
					
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/blocks/destroy.json")
					
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, user_id)
					PARAMETER(bool, include_entities)
					PARAMETER(bool, skip_status)
				};
			}
		}
	}
}

#endif // __PARAMETERS_BLOCKS_H__
