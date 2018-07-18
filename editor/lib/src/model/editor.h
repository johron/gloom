#pragma once
#include "settings.h"
#include "scenario/scenario.h"

namespace gloom {
	class editor {
	public:
		editor()
			: m_scenario(std::make_unique<scenario>()) { }
		~editor() = default;

		void new_scenario() {
			m_scenario = std::make_unique<scenario>();
		}

		std::unique_ptr<scenario> m_scenario;
		settings m_settings;
	};
}