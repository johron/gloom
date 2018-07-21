#pragma once
#include "monster.h"
#include "token.h"
#include "../resources/resource_collection.h"

namespace gloom {
	class room {
	public:
		room() = default;
		room(const resource& resource);
		~room() = default;

		QJsonObject serialize() const;
		bool deserialize(const QJsonObject& json);

		const QString& get_resource() const;
		void set_resource(const QString& resource);

		const QPointF get_position() const;
		void set_position(const QPointF& position);

		bool operator==(const room& other) const;

	private:
		QString m_resource;
		QPointF m_position;
		std::vector<token> m_tokens;
		std::vector<monster> m_monsters;
	};
}