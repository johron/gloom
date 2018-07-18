#include "main_window.h"
#include "ui_main_window.h"
#include "resource_browser.h"

namespace gloom {
	main_window::main_window(editor & editor)
		: m_editor(editor)
		, m_ui(std::make_unique<Ui::main_window>()) {
		m_ui->setupUi(this);
		m_ui->graphicsView->setScene(&m_scenario_view);

		restoreGeometry(m_editor.m_settings.value("window/geometry").toByteArray());
		restoreState(m_editor.m_settings.value("window/state").toByteArray());

		m_ui->test_area->layout()->addWidget(new resource_browser(resources::scenario_tiles(), this));
	}

	main_window::~main_window() { 
		m_editor.m_settings.setValue("window/geometry", saveGeometry());
		m_editor.m_settings.setValue("window/state", saveState());
	}
}
