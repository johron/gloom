#include "resource_browser.h"
#include "../util/flow_layout.h"

namespace gloom {
	resource_browser::resource_browser(resource_collection&& resources, QWidget* parent)
		: QScrollArea(parent) {
		setWidgetResizable(true);

		auto content = new QWidget();
		content->setLayout(new util::flow_layout());
		
		for (int i=0; i<resources.count(); ++i) {
			auto path = resources.thumbnail(i);
			auto button = new QPushButton(QPixmap(path), "");
			button->setIconSize({ 60, 60 });
			button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
			content->layout()->addWidget(button);
		}
		setWidget(content);
	}
}