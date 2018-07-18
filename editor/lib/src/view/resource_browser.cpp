#include "resource_browser.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

namespace gloom {
	resource_browser::resource_browser(resource_collection&& resources, QWidget* parent)
		: QWidget(parent) { 
		setLayout(new QVBoxLayout());

		const auto dir = QDir::current().absolutePath();

		for (int i=0; i<resources.count(); ++i) {
			auto path = resources.thumbnail(i);
			auto button = new QPushButton(QPixmap(path), "test");
			button->setIconSize({ 50, 50 });
			layout()->addWidget(button);
		}
	}
}