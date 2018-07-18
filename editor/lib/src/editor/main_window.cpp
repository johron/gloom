#include "main_window.h"
#include "ui_main_window.h"
#include "../resources/resource_browser.h"
#include "../resources/resource_collection.h"

namespace gloom {
	main_window::main_window(editor& editor)
		: m_editor(editor)
		, m_scenario_view(std::make_unique<scenario_view>(editor.get_scenario()))
		, m_ui(std::make_unique<Ui::main_window>()) {
		m_ui->setupUi(this);
		m_ui->graphicsView->setScene(m_scenario_view.get());

		restoreGeometry(m_editor.m_settings.value("window/geometry").toByteArray());
		restoreState(m_editor.m_settings.value("window/state").toByteArray());

		m_ui->rooms->layout()->addWidget(new resource_browser(resources::scenario_tiles()));
		m_ui->tokens->layout()->addWidget(new resource_browser(resources::scenario_tokens()));
		m_ui->monsters->layout()->addWidget(new resource_browser(resources::monster_tokens()));
	}

	main_window::~main_window() { 
		m_editor.m_settings.setValue("window/geometry", saveGeometry());
		m_editor.m_settings.setValue("window/state", saveState());
	}
}
