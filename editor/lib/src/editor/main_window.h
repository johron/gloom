#pragma once
#include "../scenario/view/scenario_view.h"
#include "editor.h"

namespace Ui {
	class main_window;
}

namespace gloom {
	class main_window : public QMainWindow {
	public:
		main_window(editor& editor);
		~main_window();

	private:
		void save_scenario();
		void load_scenario();
		void new_scenario();

		editor& m_editor;
		std::unique_ptr<Ui::main_window> m_ui;
		std::unique_ptr<scenario_view> m_scenario_view;
	};
}