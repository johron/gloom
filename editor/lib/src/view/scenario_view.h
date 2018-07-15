#pragma once
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace gloom {
	class scenario_view : public QGraphicsScene {
	public:
		scenario_view() {
			QPixmap img;
			auto res = img.load("E:/dev/gloom/editor/resources/scenario_book/scenario_tiles/a1a-man-made_stone_u1.png");
			res = img.load("../resources/scenario_book/scenario_tiles/a1a-man-made_stone_u1.png");

			addItem(new QGraphicsPixmapItem(img));
		}

	};
}