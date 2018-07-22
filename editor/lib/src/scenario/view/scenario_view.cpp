#include "scenario_view.h"
#include "room_view.h"
#include "../commands/place_room.h"

namespace gloom {
	scenario_view::scenario_view(editor& editor, scenario& scenario)
		: m_editor(editor) {
		QObject::connect(&scenario, &scenario::added_room, this, &scenario_view::add_room_view);
		QObject::connect(&scenario, &scenario::removed_room, this, &scenario_view::remove_room_view);

		for (auto& room : scenario.get_rooms()) {
			add_room_view(*room);
		}
	}

	void scenario_view::add_room_view(room& room) { 
		addItem(new room_view(room, this));
	}

	void scenario_view::remove_room_view(const room& room) { 
		if (auto child = findChild<room_view*>(room.get_resource())) {
			child->deleteLater();
		} else {
			qCritical() << "unable to remove room view" << room.get_resource();
		}
	}

	void scenario_view::delete_selected() {
		auto selected = selectedItems();
		if (selected.size() == 1) {
			if (auto view = dynamic_cast<room_view*>(selected.front())) {
				m_editor.apply(new commands::remove_room(view->get_room(), m_editor.get_scenario()));
			}
		}
	}

	void scenario_view::keyReleaseEvent(QKeyEvent* event) { 
		switch (event->key()) {
		case Qt::Key::Key_Delete:
			delete_selected();
			break;
		}
	}

	void scenario_view::wheelEvent(QGraphicsSceneWheelEvent* event) { 
		if (event->modifiers() & Qt::Modifier::ALT) {
			auto selected = selectedItems();
			if (selected.size() == 1) {
				if (auto view = dynamic_cast<room_view*>(selected.front())) {
					const auto rotation_delta = (event->delta() < 0 ? -15 : 15);
					view->setRotation(view->rotation() + rotation_delta);
				}
			}
		}
	}
}