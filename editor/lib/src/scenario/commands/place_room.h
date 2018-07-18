#pragma once
#include "../../resources/resource_collection.h"


namespace gloom {
	namespace commands {
		class place_room : public QUndoCommand {
		public:
			place_room(const resource& resource)
				: m_resource(resource) { }

		private:
			resource m_resource;
		};
	}
}