#pragma once
#include "../scenario/scenario.h"

namespace gloom {
	class editor {
	public:
		editor();
		~editor() = default;

		void new_scenario();
		void load_scenario(const QString& filename);
		void save_scenario(const QString& filename);

		const scenario& get_scenario() const;
		scenario& get_scenario();

		void apply(QUndoCommand* command);
		void undo();
		void redo();

		QUndoStack& get_undo_stack();
		QSettings& get_settings();

	private:
		std::unique_ptr<scenario> m_scenario;

		QSettings m_settings;
		QUndoStack m_undo_stack;
	};
}