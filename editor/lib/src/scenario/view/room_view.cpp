#include "room_view.h"

namespace gloom {
	room_view::room_view(room& room, QGraphicsItem* parent)
		: QGraphicsPixmapItem(QPixmap(room.get_resource()), parent)
		, m_room(room) {
		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable);
		setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
		setPos(room.get_position());

		setObjectName(room.get_resource());
	}

	void room_view::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
		QMenu menu;
		if (QGraphicsPixmapItem::flags() & QGraphicsItem::ItemIsMovable) {
			menu.addAction("Lock room", [this]() { setFlag(QGraphicsItem::ItemIsMovable, false); });
		} else {
			menu.addAction("Unlock room", [this]() { setFlag(QGraphicsItem::ItemIsMovable, true); });
		}
		menu.addSection("Dangerous");
		menu.addAction("Remove room");
		menu.exec(event->screenPos());
	}

	QVariant room_view::itemChange(GraphicsItemChange change, const QVariant& value) {
		if (change == QGraphicsItem::ItemScenePositionHasChanged) {
			m_room.set_position(scenePos());
		}

		return QGraphicsPixmapItem::itemChange(change, value);
	}
}