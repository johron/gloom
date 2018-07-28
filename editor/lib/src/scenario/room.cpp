#include "room.h"

namespace {
	std::vector<gloom::cell> get_cells() {
		std::vector<gloom::cell> cells;
		cells.emplace_back(gloom::cell({ 0, 0, 0 }));
		cells.emplace_back(gloom::cell({ -1, 1, 0 }));
		cells.emplace_back(gloom::cell({ 1, -1, 0 }));
		cells.emplace_back(gloom::cell({ 0, 1, -1 }));
		cells.emplace_back(gloom::cell({ 1, 0, -1 }));
		cells.emplace_back(gloom::cell({ -1, 0, 1 }));
		cells.emplace_back(gloom::cell({ 0, -1, 1 }));
		return cells;
	}
}

namespace gloom {
	room::room()
		: m_cells(::get_cells()) { }
	room::room(const resource& resource)
		: m_resource(resource.original())
		, m_position(0, 0)
		, m_rotation(0)
		, m_cells(get_cells()) { }

	QJsonObject room::serialize() const {
		QJsonArray tokens;
		for (const auto& token : m_tokens) {
			tokens.append(token.serialize());
		}

		QJsonArray monsters;
		for (const auto& monster : m_monsters) {
			monsters.append(monster.serialize());
		}

		QJsonObject room_data;
		room_data["resource"] = get_resource();
		room_data["position"] = QJsonObject{ {"x", get_position().x()}, { "y", get_position().y()} };
		room_data["rotation"] = m_rotation;

		return QJsonObject{
			{ "tokens", std::move(tokens) },
			{ "monsters", std::move(monsters) },
			{ "room_data", std::move(room_data) }
		};
	}

	bool room::deserialize(const QJsonObject& json) {
		const auto tokens = json["tokens"].toArray();
		for (const auto& token_data : tokens) {
			m_tokens.emplace_back();
			if (!m_tokens.back().deserialize(token_data.toObject())) {
				m_tokens.pop_back();
				throw std::runtime_error("failed to deserialize token");
				return false;
			}
		}

		const auto monsters = json["monsters"].toArray();
		for (const auto& monster_data : monsters) {
			m_monsters.emplace_back();
			if (!m_monsters.back().deserialize(monster_data.toObject())) {
				m_monsters.pop_back();
				throw std::runtime_error("failed to deserialize monster");
				return false;
			}
		}

		const auto room_data = json["room_data"].toObject();
		set_resource(room_data["resource"].toString());
		set_position({ room_data["position"].toObject()["x"].toDouble(), room_data["position"].toObject()["y"].toDouble() });
		set_rotation(room_data["rotation"].toInt());
		return true;
	}

	const QString& room::get_resource() const {
		return m_resource;
	}

	void room::set_resource(const QString& resource) { 
		m_resource = resource;
	}

	const QPointF room::get_position() const {
		return m_position;
	}

	void room::set_position(const QPointF& position) {
		m_position = position;
	}

	const int room::get_rotation() const {
		return m_rotation;
	}

	void room::set_rotation(int rotation) {
		m_rotation = rotation;
	}

	const std::vector<cell>& room::get_cells() const {
		return m_cells;
	}

	bool room::operator==(const room& other) const {
		return m_resource == other.m_resource;
	}

}