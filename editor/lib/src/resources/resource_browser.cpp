#include "resource_browser.h"
#include "../util/flow_layout.h"

namespace gloom {
	resource_browser::resource_browser(resource_collection&& resources, 
									   std::function<void(const resource& )> on_click, 
									   QWidget* parent)
		: QScrollArea(parent) {
		setWidgetResizable(true);

		auto content = new QWidget();
		content->setLayout(new util::flow_layout());
		
		for (const auto& resource : resources) {
			auto button = new QPushButton(QPixmap(resource.thumbnail()), "");
			button->setToolTip(QFile(resource.original()).fileName());;
			button->setIconSize({ 60, 60 });
			button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
			QObject::connect(button, &QPushButton::clicked, [on_click, resource]() { on_click(resource); });
			content->layout()->addWidget(button);
		}

		setWidget(content);
	}
}