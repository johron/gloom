#include "scenario_view.h"
#include "room_view.h"

namespace gloom {
	scenario_view::scenario_view(scenario& scenario) {
		QObject::connect(&scenario, &scenario::added_room, this, &scenario_view::add_room_view);
		QObject::connect(&scenario, &scenario::removed_room, this, &scenario_view::remove_room_view);

		for (const auto& room : scenario.get_rooms()) {
			add_room_view(room);
		}
	}

	void scenario_view::add_room_view(const room& room) { 
		const auto view = new room_view(room.get_resource());
		QGraphicsScene::addItem(view);
	}

	void scenario_view::remove_room_view(const room& room) { 
		if (auto child = QGraphicsScene::findChild<room_view*>(room.get_resource())) {
			child->deleteLater();
		} else {
			qWarning() << "unable to remove room view" << room.get_resource();
		}
	}

}