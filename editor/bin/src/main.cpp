#include <QApplication>
#include <QMainWindow>

int main(int argc, char** argv) {
	QApplication application(argc, argv);

	QMainWindow window;
	window.show();

	return application.exec();
}