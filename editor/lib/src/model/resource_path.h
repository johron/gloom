#pragma once
#include <QDir>

namespace gloom {
	struct resource_path {
		resource_path(const char* path)
			: m_path(QString("../../resources/") + path) { }

		size_t count() const {
			return std::min(m_path.count(), m_path.count()-2);
		}

		QString path() const {
			return m_path.absolutePath() + "/";
		}

		template <typename T>
		void for_each(const T& functor) {
			for (auto& file : m_path.entryList(QDir::Filter::Files)) {
				functor(file);
			}
		}

		QString operator[](int index) const {
			return m_path.entryList(QDir::Filter::Files)[index];
		}

	private:
		QDir m_path;

	};

	namespace resources {
		struct scenario_tiles : public resource_path {
			scenario_tiles() : resource_path("scenario_book/scenario_tiles/") { }
		};

		struct scenario_tokens : public resource_path {
			scenario_tokens() : resource_path("scenario_book/tokens") { }
		};

		struct monster_tokens : public resource_path {
			monster_tokens() : resource_path("scenario_book/monsters") { }
		};
	}
}