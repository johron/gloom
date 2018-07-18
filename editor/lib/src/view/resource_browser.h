#pragma once
#include <QWidget>
#include "../model/resource_collection.h"

namespace gloom {
	class resource_browser : public QWidget {
	public:
		resource_browser(resource_collection&& resources, QWidget* parent = nullptr);


	};
}