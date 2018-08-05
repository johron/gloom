#pragma once
#include "../../resources/resource_collection.h"
#include "../scenario.h"


namespace gloom {
	namespace commands {
		class place_room : public QUndoCommand {
		public:
			place_room(const resource& resource, scenario& scenario)
				: QUndoCommand("place room") 
				, m_room_data(room(resource).serialize())
				, m_scenario(scenario) { }

			virtual void redo() override {
// 				auto created_room = std::make_unique<room>();
// 				if (created_room->deserialize(m_room_data)) {
// 					m_scenario.add_room(std::move(created_room));
// 				}
			}

			virtual void undo() override {
				const auto resource = m_room_data["room_data"].toObject()["resource"].toString();
				m_room_data = m_scenario.get_room(resource).serialize();
				m_scenario.remove_room(resource);
			}

		private:
			QJsonObject m_room_data;
			scenario& m_scenario;
		};

		class remove_room : public QUndoCommand {
		public:
			remove_room(const room& room, scenario& scenario)
				: QUndoCommand("remove room")
				, m_room_data(room.serialize())
				, m_scenario(scenario) { }

			virtual void redo() override {
				m_scenario.remove_room(m_room_data["room_data"].toObject()["resource"].toString());
			}

			virtual void undo() override {
// 				auto created_room = std::make_unique<room>();
// 				if (created_room->deserialize(m_room_data)) {
// 					m_scenario.add_room(std::move(created_room));
// 				} 
			}

		private:
			QJsonObject m_room_data;
			scenario& m_scenario;
		};
	}
}