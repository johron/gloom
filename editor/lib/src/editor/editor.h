#pragma once
#include "settings.h"
#include "../scenario/scenario.h"

namespace gloom {
	class editor {
	public:
		editor()
			: m_scenario(std::make_unique<scenario>()) { }
		~editor() = default;

		void new_scenario() {
			m_scenario = std::make_unique<scenario>();
		}

		void load_scenario(const QString& filename) {
			QFile file(filename);
			auto json = QJsonDocument::fromBinaryData(file.readAll());
			if (!json.isEmpty()) {
				new_scenario();
				m_scenario->deserialize(json.object());
			} else {
				qCritical() << "failed to read json from file" << filename;
			}
		}

		const scenario& get_scenario() const {
			return *m_scenario;
		}

		scenario& get_scenario() {
			return *m_scenario;
		}

		std::unique_ptr<scenario> m_scenario;
		settings m_settings;
	};
}