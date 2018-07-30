#include "editor.h"

namespace gloom {
	editor::editor() 
		: m_scenario(std::make_unique<scenario>()) { }

	void editor::new_scenario() {
		m_scenario = std::make_unique<scenario>();
	}

	void editor::load_scenario(const QString& filename) {
		QFile file(filename);
		file.open(QFile::ReadOnly);
		const auto json_data = QJsonDocument::fromJson(file.readAll());
		file.close();

		if (!json_data.isEmpty()) {
			new_scenario();
			m_scenario->deserialize(json_data.object());
		} else {
			qCritical() << "failed to read json from file" << filename;
		}
	}

	void editor::save_scenario(const QString& filename) { 
		const auto json_data = QJsonDocument(m_scenario->serialize());
		QFile file(filename);
		file.open(QFile::WriteOnly);
		file.write(json_data.toJson());
		file.close();
	}

	void editor::make_room(const resource& resource) { 
// 		const auto resource = resources::scenario_tiles()[0];
// 		const auto definition = "resources/data/room_definitions/scenario_tile_a.roomdef";

		m_room = std::make_unique<room>(resource);
		m_scene.clear();
		m_scene.addItem(new room_view(*m_room, &m_scene));
	}

	const scenario& editor::get_scenario() const {
		return *m_scenario;
	}

	scenario& editor::get_scenario() {
		return *m_scenario;
	}

	void editor::apply(QUndoCommand * command) { 
		m_undo_stack.push(command);
	}

	void editor::undo() { 
		m_undo_stack.undo();
	}

	void editor::redo() { 
		m_undo_stack.redo();
	}

	QUndoStack& editor::get_undo_stack() {
		return m_undo_stack;
	}

	QSettings& editor::get_settings() {
		return m_settings;
	}

	QGraphicsScene& editor::get_scene() {
		return m_scene;
	}

}