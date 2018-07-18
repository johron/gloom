#pragma once

namespace gloom {
	class token {
	public:
		QJsonObject serialize() const {
			return QJsonObject();
		}

		bool deserialize(const QJsonObject& json) {
			return true;
		}
	};
}