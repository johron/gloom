#include "room_view.h"

namespace gloom {
	room_view::room_view(const QString& resource, QGraphicsItem* parent)
		: QGraphicsPixmapItem(QPixmap(resource), parent) { 
		QGraphicsPixmapItem::setFlag(QGraphicsItem::ItemIsMovable);
		QObject::setObjectName(resource);
		qDebug() << "room_view:" << resource;
	}
}