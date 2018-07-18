#include <QApplication>
#include <QMainWindow>
#include "src/editor/main_window.h"
#include "src/editor/editor.h"

int main(int argc, char** argv) {
	QApplication application(argc, argv);
	application.setOrganizationName("temp-organization");
	application.setApplicationName("gloom-editor");

	gloom::editor editor;
	gloom::main_window window(editor);
	window.show();

	return application.exec();
}