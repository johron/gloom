#pragma once
#include "../../resources/resource_collection.h"


namespace gloom {
	namespace commands {
		class place_room : public QUndoCommand {
		public:
			place_room(const resource& resource, scenario& scenario)
				: m_resource(resource)
				, m_scenario(scenario) { }

			virtual void redo() override {
				m_scenario.add_room(room(m_resource));
			}

			virtual void undo() override {
				m_scenario.remove_room(m_resource);
			}

		private:
			resource m_resource;
			scenario m_scenario;
		};
	}
}