#include "layout_editor.h"

namespace {
	const QColor color_disabled(120, 0, 0, 120);
	const QColor color_enabled(0, 120, 0, 120);
}

namespace gloom {
	room_hex::room_hex(hex_coordinate coordinate, QGraphicsItem* parent)
		: hexagon(coordinate, 112.5, parent)
		, m_enabled(false)
		, m_coordinate(coordinate) { 
		setZValue(100);
		update_brush();
	}

	void room_hex::mousePressEvent(QGraphicsSceneMouseEvent* event) { 
		m_enabled = !m_enabled;
		update_brush();
	}

	void room_hex::update_brush() { 
		setBrush(m_enabled ? ::color_enabled : ::color_disabled);
	}

	layout_editor::layout_editor()
		: m_background(nullptr) { 

		std::vector<hex_coordinate> coordinates;
		const int range = 5;
		for (int x=-range; x<=range; ++x) {
			for (int y=-range; y<=range; ++y) {
				for (int z=-range; z<=range; ++z) {
					if (x + y + z == 0) {
						coordinates.emplace_back(hex_coordinate{ x, y, z });
					}
				}
			}
		}

		m_hexagons.reserve(coordinates.size());
		for (const auto& c : coordinates) {
			auto item = new room_hex(c, nullptr);
			m_hexagons.emplace_back(item);
			addItem(item);
		}
	}

	void layout_editor::set_resource(const resource& resource) {
		if (m_background) {
			removeItem(m_background);
			delete m_background;
			m_background = nullptr;
		}

		m_background = new QGraphicsPixmapItem(resource.original());
		m_background->setOffset(-m_background->boundingRect().center());
		m_resource = resource.original();
		addItem(m_background);
	}

	void layout_editor::save_layout() { 
		const auto filename = QFileDialog::getSaveFileName(nullptr, "Save layout", "", "Hex layout(*.hexlayout)");
		if (!filename.isEmpty()) {
			hex_layout layout;

			for (const auto hex : m_hexagons) {
				if (hex->m_enabled) {
					layout.m_coordinates.emplace_back(hex->m_coordinate);
				}
			}
			
			const auto json_data = QJsonDocument(layout.serialize());
			QFile file(filename);
			file.open(QFile::WriteOnly);
			file.write(json_data.toJson(QJsonDocument::Compact));
			file.close();
		}
	}

	void layout_editor::keyPressEvent(QKeyEvent* event) { 
		switch (event->key()) {
		case Qt::Key_Down:
			m_background->setOffset(m_background->offset() + QPointF(0, 1));
			event->accept();
			break;
		case Qt::Key_Up:
			m_background->setOffset(m_background->offset() + QPointF(0, -1));
			event->accept();
			break;
		case Qt::Key_Left:
			m_background->setOffset(m_background->offset() + QPointF(-1, 0));
			event->accept();
			break;
		case Qt::Key_Right:
			m_background->setOffset(m_background->offset() + QPointF(1, 0));
			event->accept();
			break;
		}

		QGraphicsScene::keyPressEvent(event);
	}
}