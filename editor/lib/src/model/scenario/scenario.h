#pragma once
#include "room.h"

namespace gloom {
	class scenario {
	public:

		QJsonObject serialize() const {
			QJsonArray rooms;
			for (const auto& room : m_rooms) {
				rooms.append(room->serialize());
			}

			return QJsonObject{ { "rooms", std::move(rooms) } };
		}

		bool deserialize(QJsonObject&& json) {
			try {
				const auto rooms = json["rooms"].toArray();
				for (const auto& room_data : rooms) {
					m_rooms.emplace_back(std::make_unique<room>());
					if (!m_rooms.back()->deserialize(room_data.toObject())) {
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

		std::vector<std::unique_ptr<room>> m_rooms;
	};
}