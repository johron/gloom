#pragma once
#include "monster.h"
#include "token.h"
#include "../resources/resource_collection.h"
#include "../util/hexagon.h"

namespace gloom {
	struct cell {
		cell(const hex_coordinate& pos)
			: m_position(pos) { }
		hex_coordinate m_position;

		bool operator==(const cell& other) const { return m_position == other.m_position; }
	};

	class room {
	public:
		room();
		room(const resource& resource);
		~room() = default;

		QJsonObject serialize() const;
		bool deserialize(const QJsonObject& json);

		const QString& get_resource() const;
		void set_resource(const QString& resource);

		const QPointF get_position() const;
		void set_position(const QPointF& position);

		const int get_rotation() const;
		void set_rotation(int rotation);

		const QPointF get_offset() const;
		void set_offset(const QPointF& offset);

		const std::vector<cell>& get_cells() const;

		bool operator==(const room& other) const;

	private:
		QString m_resource;
		QPointF m_position;
		QPointF m_offset;

		int m_rotation;
		std::vector<token> m_tokens;
		std::vector<monster> m_monsters;
		std::vector<cell> m_cells;
	};

	using room_storage = std::vector<std::unique_ptr<room>>;
}