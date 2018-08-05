#pragma once
#include "room_id.h"
#include "../../util/hexagon.h"
#include "../../resources/resource_collection.h"

namespace gloom {
	class room_directory {
	public:
		struct entry {
			entry(const QJsonObject& data) 
				: m_id(get_id(data["id"].toString()))
				, m_style(get_style(data["style"].toString()))
				, m_layout(data["layout"].toObject())
				, m_resource(data["resource"].toObject()) { }
			room_id m_id;
			room_style m_style;
			hex_layout m_layout;
			resource m_resource;
		};

		room_directory(QJsonObject data) {
			const auto rooms = data["rooms"].toArray();
			for (const auto& room_data : rooms) {
				m_entries.emplace_back(room_data.toObject());
			}
		}

		size_t size() const {
			return m_entries.size();
		}

		template <typename T>
		std::vector<entry> get_rooms(const T& predicate) const {
			std::vector<entry> results;
			for (const auto& entry : m_entries) {
				if (predicate(entry)) {
					results.emplace_back(entry);
				}
			}
			return results;
		}

	private:
		std::vector<entry> m_entries;
	};
}