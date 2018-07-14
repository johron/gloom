#pragma once
#include <QMainWindow>
#include <QSettings>
#include "../model/editor.h"

namespace gloom {
	class main_window : public QMainWindow {
	public:
		main_window(editor& editor);
		~main_window();

	private:
		editor& m_editor;
	};
}