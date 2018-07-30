#pragma once
#include <unordered_set>
#include "../room.h"

namespace gloom {
	class room_hex : public hexagon {
	public:
		room_hex(hex_coordinate coordinate, QGraphicsItem* parent);


		const hex_coordinate m_coordinate;
		bool m_enabled;

	private:
		virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
		void update_brush();
	};

	class room_builder : public QGraphicsScene {
	public:
		room_builder();

		void set_resource(const resource& resource);
		void save_room();

		room build();

	private:
		virtual void keyPressEvent(QKeyEvent *event) override;

		std::vector<room_hex*> m_hexagons;
		QGraphicsPixmapItem* m_background;
		QString m_resource;
	};
}