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