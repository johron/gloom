#pragma once
#include "../scenario/scenario.h"
#include "../scenario/view/room_view.h"

namespace gloom {
	class editor {
	public:
		editor();
		~editor() = default;

		void new_scenario();
		void load_scenario(const QString& filename);
		void save_scenario(const QString& filename);

		void make_room(const resource& resource);

		const scenario& get_scenario() const;
		scenario& get_scenario();

		void apply(QUndoCommand* command);
		void undo();
		void redo();

		QUndoStack& get_undo_stack();
		QSettings& get_settings();
		QGraphicsScene& get_scene();

	private:
		std::unique_ptr<scenario> m_scenario;
		
		std::unique_ptr<room> m_room;

		QSettings m_settings;
		QUndoStack m_undo_stack;
		QGraphicsScene m_scene;
	};
}