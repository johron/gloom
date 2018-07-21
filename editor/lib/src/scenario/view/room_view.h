#pragma once
#include "../scenario.h"

namespace gloom {
	class room_view : public QObject, public QGraphicsPixmapItem {
	public:
		room_view(room& room, QGraphicsItem* parent = nullptr);

	private:
		virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
		virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

		room& m_room;
	};
}