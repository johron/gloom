#pragma once

namespace gloom {
	class monster {
	public:
		QJsonObject serialize() const {
			return QJsonObject();
		}

		bool deserialize(const QJsonObject& json) {
			return true;
		}
	};
}