#pragma once
#include "../scenario.h"

namespace gloom {
	class room_view : public QObject, public QGraphicsPixmapItem {
	public:
		room_view(const QString& resource, QGraphicsItem* parent = nullptr);

	};
}