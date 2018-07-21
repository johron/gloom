#include "scenario.h"

namespace gloom {
	QJsonObject scenario::serialize() const {
		QJsonArray rooms;
		for (const auto& room : m_rooms) {
			rooms.append(room.serialize());
		}
		
		QJsonObject scenario_data;

		return QJsonObject{ 
			{ "rooms", std::move(rooms) },
			{ "scenario_data", std::move(scenario_data) }
		};
	}

	bool scenario::deserialize(QJsonObject&& json) {
		try {
			const auto rooms = json["rooms"].toArray();
			for (const auto& room_data : rooms) {
				m_rooms.emplace_back();
				if (!m_rooms.back().deserialize(room_data.toObject())) {
					m_rooms.pop_back();
					throw std::runtime_error("failed to deserialize room");
				}
			}
		} catch (const std::exception& exception) {
			qCritical() << exception.what();
			if (QMessageBox::critical(nullptr, "Serialization error", exception.what(),
									  QMessageBox::StandardButton::Ignore, QMessageBox::StandardButton::Abort) == QMessageBox::Abort) {
				return false;
			}
		}

		return true;
	}

	const std::vector<room>& scenario::get_rooms() const {
		return m_rooms;
	}

	std::vector<room>& scenario::get_rooms() {
		return m_rooms;
	}

	void scenario::add_room(room&& room) { 
		m_rooms.emplace_back(std::move(room));
		emit added_room(m_rooms.back());
	}

	void scenario::remove_room(const room& room) { 
		const auto iterator = std::find(m_rooms.begin(), m_rooms.end(), room);
		if (iterator != m_rooms.end()) {
			emit removed_room(room);
			m_rooms.erase(iterator);
		}
	}
}