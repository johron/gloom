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

		restoreGeometry(m_editor.get_settings().value("window/geometry").toByteArray());
		restoreState(m_editor.get_settings().value("window/state").toByteArray());

		QObject::connect(m_ui->action_new_scenario, &QAction::triggered, this, &main_window::new_scenario);
		QObject::connect(m_ui->action_save_scenario, &QAction::triggered, this, &main_window::save_scenario);
		QObject::connect(m_ui->action_load_scenario, &QAction::triggered, this, &main_window::load_scenario);

		m_ui->rooms->layout()->addWidget(new resource_browser(resources::scenario_tiles()));
		m_ui->tokens->layout()->addWidget(new resource_browser(resources::scenario_tokens()));
		m_ui->monsters->layout()->addWidget(new resource_browser(resources::monster_tokens()));

		auto& undo_stack = m_editor.get_undo_stack();
		m_ui->info_content->layout()->addWidget(new QUndoView(&undo_stack));
		auto undo_action = undo_stack.createUndoAction(this, "undo");
		undo_action->setShortcut(QKeySequence::Undo);
		auto redo_action = undo_stack.createRedoAction(this, "redo");
		redo_action->setShortcut(QKeySequence::Redo);
		m_ui->menuEdit->addActions({ undo_action, redo_action });
	}

	main_window::~main_window() { 
		m_editor.get_settings().setValue("window/geometry", saveGeometry());
		m_editor.get_settings().setValue("window/state", saveState());
	}
	
	void main_window::save_scenario() {
		const auto filename = QFileDialog::getSaveFileName(this, "Save scenario", "", "Scenario files (*.scenario)");
		if (!filename.isEmpty()) {
			m_editor.save_scenario(filename);
		}
	}

	void main_window::load_scenario() { 
		// add warning for lost work
		const auto filename = QFileDialog::getOpenFileName(this, "Load scenario", "", "Scenario files (*.scenario)");
		if (!filename.isEmpty()) {
			m_editor.load_scenario(filename);
		}		
	}

	void main_window::new_scenario() { 
		// add warning for lost work
		m_editor.new_scenario();
	}
}
