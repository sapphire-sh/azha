#ifndef __PARAMETERS_COLLECTIONS_H__
#define __PARAMETERS_COLLECTIONS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Collections {
				class EntriesParameters : public ITwitterParameters {
				public:
					INIT(EntriesParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/collections/entries.json")
					
					PARAMETER(std::string, id)
					PARAMETER(uint64_t, count)
					PARAMETER(uint64_t, max_position)
					PARAMETER(uint64_t, min_position)
				};

				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/collections/list.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, tweet_id)
					PARAMETER(uint64_t, count)
					PARAMETER(std::string, cursor)
				};

				class ShowParameters : public ITwitterParameters {
				public:
					INIT(ShowParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/collections/show.json")

					PARAMETER(std::string, id)
				};
			}
		}
		
		namespace POST {
			namespace Collections {
				class CreateParameters : public ITwitterParameters {
				public:
					INIT(CreateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/collections/create.json")

					PARAMETER(std::string, name)
					PARAMETER(std::string, description)
					PARAMETER(std::string, url)
					PARAMETER(std::string, timeline_order)
				};

				class DestroyParameters : public ITwitterParameters {
				public:
					INIT(DestroyParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/collections/destroy.json")

					PARAMETER(std::string, id)
				};

				namespace Entries {
					class AddParameters : public ITwitterParameters {
					public:
						INIT(AddParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/collections/entries/add.json")

						PARAMETER(std::string, id)
						PARAMETER(uint64_t, tweet_id)
						PARAMETER(uint64_t, relative_to)
						PARAMETER(bool, above)
					};

					class CurateParameters : public ITwitterParameters {
					public:
						INIT(CurateParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/collections/entries/curate.json")
					};

					class MoveParameters : public ITwitterParameters {
					public:
						INIT(MoveParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/collections/entries/move.json")

						PARAMETER(std::string, id)
						PARAMETER(uint64_t, tweet_id)
						PARAMETER(uint64_t, relative_to)
						PARAMETER(bool, above)
					};

					class RemoveParameters : public ITwitterParameters {
					public:
						INIT(RemoveParameters)
						METHOD(RequestMethod::POST)
						URL("https://api.twitter.com/1.1/collections/entries/remove.json")

						PARAMETER(std::string, id)
						PARAMETER(uint64_t, tweet_id)
					};
				}

				class UpdateParameters : public ITwitterParameters {
				public:
					INIT(UpdateParameters)
					METHOD(RequestMethod::POST)
					URL("https://api.twitter.com/1.1/collections/update.json")

					PARAMETER(std::string, id)
					PARAMETER(std::string, name)
					PARAMETER(std::string, description)
					PARAMETER(std::string, url)
				};
			};
		}
	}
}

#endif // __PARAMETERS_COLLECTIONS_H__
