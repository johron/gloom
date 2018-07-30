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
			setBrush(QColor(65, 65, 65, 165));
		}
	};

	struct hex_layout {
		hex_layout() = default;
		hex_layout(std::vector<hex_coordinate>&& coordinates)
			: m_coordinates(std::move(coordinates)) { }
		hex_layout(const QJsonObject& data) {
			deserialize(data);
		}

		QJsonObject serialize() const {
			QJsonArray data;
			for (const auto& hex : m_coordinates) {
				data.append(QJsonArray{ std::get<0>(hex), std::get<1>(hex), std::get<2>(hex) });
			}

			return QJsonObject{ {"hex_layout", std::move(data)} };
		}

		void deserialize(const QJsonObject& data) {
			assert(m_coordinates.empty());
			const auto hex_layout = data["hex_layout"].toArray();
			for (const auto& hex : hex_layout) {
				const auto hex_data = hex.toArray();
				m_coordinates.emplace_back(hex_coordinate{ hex_data[0].toInt(), hex_data[1].toInt(), hex_data[2].toInt() });
			}
		}

		std::vector<hex_coordinate> m_coordinates;
	};
}