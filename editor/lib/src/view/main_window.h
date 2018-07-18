#pragma once
#include "scenario_view.h"
#include "../model/editor.h"

namespace Ui {
	class main_window;
}

namespace gloom {
	class main_window : public QMainWindow {
	public:
		main_window(editor& editor);
		~main_window();

	private:
		editor& m_editor;
		scenario_view m_scenario_view;
		std::unique_ptr<Ui::main_window> m_ui;
	};
}