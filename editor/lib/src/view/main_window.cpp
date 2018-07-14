#include "main_window.h"

namespace gloom {
	main_window::main_window(editor & editor) 
		: m_editor(editor) {
		restoreGeometry(m_editor.m_settings.value("window/geometry").toByteArray());
		restoreState(m_editor.m_settings.value("window/state").toByteArray());
	}

	main_window::~main_window() { 
		m_editor.m_settings.setValue("window/geometry", saveGeometry());
		m_editor.m_settings.setValue("window/state", saveState());
	}
}
