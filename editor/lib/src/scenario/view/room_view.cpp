#include "room_view.h"
#include "src/util/hexagon.h"

namespace gloom {
	room_view::room_view(room& room, QObject* parent)
		: QObject(parent)
		, m_room(room) {

		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable);
		setFlag(QGraphicsItem::ItemSendsGeometryChanges);
		setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

		auto background = new QGraphicsPixmapItem(room.get_resource(), this);
		background->setOffset(room.get_offset());
		setTransformOriginPoint(background->boundingRect().center());
		addToGroup(background);

		setPos(room.get_position());
		setRotation(room.get_rotation());
		setObjectName(room.get_resource());

 		const auto& cells = room.get_cells();
 		for (const auto& cell : cells) {
 			addToGroup(new hexagon(cell.m_position, 112.5, this));
 		}
	}

	room& room_view::get_room() {
		return m_room;
	}

	void room_view::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
		QMenu menu;
		if (QGraphicsItem::flags() & QGraphicsItem::ItemIsMovable) {
			menu.addAction("Lock room", [this]() { setFlag(QGraphicsItem::ItemIsMovable, false); });
		} else {
			menu.addAction("Unlock room", [this]() { setFlag(QGraphicsItem::ItemIsMovable, true); });
		}
		menu.addSection("Dangerous");
		menu.addAction("Remove room");
		menu.exec(event->screenPos());
	}

	QVariant room_view::itemChange(GraphicsItemChange change, const QVariant& value) {
		switch (change) {
		case QGraphicsItem::ItemScenePositionHasChanged:
			m_room.set_position(value.toPointF());
			break;
		case QGraphicsItem::ItemRotationChange:
			m_room.set_rotation(value.toReal());
			break;
		}	

		return QGraphicsItemGroup::itemChange(change, value);
	}
}