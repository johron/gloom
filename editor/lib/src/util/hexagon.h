#pragma once

namespace util {
	class hexagon : public QPolygonF {
	public:
		hexagon(QPointF position, float size) 
			: QPolygonF({
				{ position.x() + size * cos(qDegreesToRadians(30.0)), position.y() + size * sin(qDegreesToRadians(30.0)) },
				{ position.x() + size * cos(qDegreesToRadians(90.0)), position.y() + size * sin(qDegreesToRadians(90.0)) },
				{ position.x() + size * cos(qDegreesToRadians(150.0)), position.y() + size * sin(qDegreesToRadians(150.0)) },
				{ position.x() + size * cos(qDegreesToRadians(210.0)), position.y() + size * sin(qDegreesToRadians(210.0)) },
				{ position.x() + size * cos(qDegreesToRadians(270.0)), position.y() + size * sin(qDegreesToRadians(270.0)) },
				{ position.x() + size * cos(qDegreesToRadians(330.0)), position.y() + size * sin(qDegreesToRadians(330.0)) } }) { }
	};
}

namespace gloom {
	using hex_coordinate = std::tuple<int, int, int>;
	inline QPointF to_pos(hex_coordinate c, float size) {
		const auto w = sqrt(3) * size;
		const auto h = size * 2;

		const auto y = std::get<2>(c) * h * 3/4;
		const auto x = std::get<0>(c) * w/2 + std::get<1>(c) * -w/2;
		return { x, y };
	}


	struct hexagon : public QGraphicsPolygonItem {
		hexagon(hex_coordinate coordinate, float size, QGraphicsItem* parent)
			: QGraphicsPolygonItem(util::hexagon(to_pos(coordinate, size), size), parent) {
			setPen(QPen(Qt::red, 4));
		}
	};
}