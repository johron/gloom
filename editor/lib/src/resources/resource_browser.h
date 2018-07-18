#pragma once
#include "resource_collection.h"

namespace gloom {
	class resource_browser : public QScrollArea {
	public:
		resource_browser(resource_collection&& resources, QWidget* parent = nullptr);
	};
}