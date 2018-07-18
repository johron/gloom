#pragma once
#include "room.h"

namespace gloom {
	class scenario {
	public:
		scenario() = default;
		~scenario() = default;

		QJsonObject serialize() const;
		bool deserialize(QJsonObject&& json);

		const std::vector<room>& get_rooms() const;
		void add_room(room&& room);

	private:
		std::vector<room> m_rooms;
	};
}