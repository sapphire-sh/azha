#ifndef __PARAMETERS_COLLECTIONS_H__
#define __PARAMETERS_COLLECTIONS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Collections {
				class EntriesParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/collections/entries.json");
					
					PARAMETER_STRING(EntriesParameters, id);
					PARAMETER_UINT64(EntriesParameters, count);
					PARAMETER_UINT64(EntriesParameters, max_position);
					PARAMETER_UINT64(EntriesParameters, min_position);
				};
				
				class ListParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/collections/list.json");
					
					PARAMETER_UINT64(ListParameters, user_id);
					PARAMETER_STRING(ListParameters, screen_name);
					PARAMETER_UINT64(ListParameters, tweet_id);
					PARAMETER_UINT64(ListParameters, count);
					PARAMETER_STRING(ListParameters, cursor);
				};
				
				class ShowParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::GET);
					URL("https://api.twitter.com/1.1/collections/show.json");
					
					PARAMETER_STRING(ShowParameters, id);
				};
			}
		}
		
		namespace POST {
			namespace Collections {
				class CreateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/collections/create.json");
					
					PARAMETER_STRING(CreateParameters, name);
					PARAMETER_STRING(CreateParameters, description);
					PARAMETER_STRING(CreateParameters, url);
					PARAMETER_STRING(CreateParameters, timeline_order);
				};
				
				class DestroyParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/collections/destroy.json");
					
					PARAMETER_STRING(DestroyParameters, id);
				};
				
				namespace Entries {
					class AddParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/collections/entries/add.json");
						
						PARAMETER_STRING(AddParameters, id);
						PARAMETER_UINT64(AddParameters, tweet_id);
						PARAMETER_UINT64(AddParameters, relative_to);
						PARAMETER_BOOL(AddParameters, above);
					};
					
					class CurateParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/collections/entries/curate.json");
					};
					
					class MoveParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/collections/entries/move.json");
						
						PARAMETER_STRING(MoveParameters, id);
						PARAMETER_UINT64(MoveParameters, tweet_id);
						PARAMETER_UINT64(MoveParameters, relative_to);
						PARAMETER_BOOL(MoveParameters, above);
					};
					
					class RemoveParameters : public ITwitterParameters {
					public:
						METHOD(RequestMethod::POST);
						URL("https://api.twitter.com/1.1/collections/entries/remove.json");
						
						PARAMETER_STRING(RemoveParameters, id);
						PARAMETER_UINT64(RemoveParameters, tweet_id);
					};
				}
				
				class UpdateParameters : public ITwitterParameters {
				public:
					METHOD(RequestMethod::POST);
					URL("https://api.twitter.com/1.1/collections/update.json");
					
					PARAMETER_STRING(UpdateParameters, id);
					PARAMETER_STRING(UpdateParameters, name);
					PARAMETER_STRING(UpdateParameters, description);
					PARAMETER_STRING(UpdateParameters, url);
				};
			};
		}
	}
}

#endif // __PARAMETERS_COLLECTIONS_H__
