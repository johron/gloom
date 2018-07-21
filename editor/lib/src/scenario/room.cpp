#include "room.h"

namespace gloom {
	room::room(const resource& resource) 
		: m_resource(resource.original())
		, m_position(0, 0) { }

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
		set_position({ room_data["position"]["x"].toDouble(), room_data["position"]["y"].toDouble() });
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

	bool room::operator==(const room& other) const {
		return m_resource == other.m_resource;
	}

}