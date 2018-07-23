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

		const room_storage& get_rooms() const;
		room_storage& get_rooms();

		const room& get_room(const QString& resource) const;
		room& get_room(const QString& resource);

		void add_room(std::unique_ptr<room> room);
		void remove_room(const QString& resource);

	signals:
		void added_room(room& room);
		void removed_room(const room& room);

	private:
		room_storage m_rooms;
	};
}