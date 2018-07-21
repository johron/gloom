#pragma once
#include "room.h"

namespace gloom {
	class scenario : public QObject {
		Q_OBJECT
	public:
		scenario() = default;
		~scenario() = default;

		QJsonObject serialize() const;
		bool deserialize(QJsonObject&& json);

		const std::vector<room>& get_rooms() const;
		std::vector<room>& get_rooms();

		void add_room(room&& room);
		void remove_room(const room& room);

	signals:
		void added_room(room& room);
		void removed_room(const room& room);

	private:
		std::vector<room> m_rooms;
	};
}