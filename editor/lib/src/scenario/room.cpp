#include "room.h"

namespace gloom {
	room::room(const resource& resource) { }

	QJsonObject room::serialize() const {
		QJsonArray tokens;
		for (const auto& token : m_tokens) {
			tokens.append(token.serialize());
		}

		QJsonArray monsters;
		for (const auto& monster : m_monsters) {
			monsters.append(monster.serialize());
		}

		return QJsonObject{
			{ "tokens", std::move(tokens) },
			{ "monsters", std::move(monsters) }
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
		return true;
	}

	const QString& room::get_resource() const {
		return m_resource;
	}

	void room::set_resource(const QString& resource) { 
		m_resource = resource;
	}

}