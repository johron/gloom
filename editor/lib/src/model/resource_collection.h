#pragma once
#include <QDir>
#include <QString>

namespace gloom {
	// this is written with the assumption that resources won't change after application start.

	struct resource_collection {
		resource_collection(const char* path)
			: m_resources(QString("../resources/original/") + path)
			, m_thumbnails(QString("../resources/thumbnails/") + path) { }

		size_t count() const {
			return std::min(m_resources.count(), m_resources.count()-2);
		}

		bool empty() const {
			return count() == 0;
		}

		template <typename T>
		void for_each_resource(const T& functor) {
			for (const auto& file : m_resources.entryList(QDir::Filter::Files)) {
				functor(file);
			}
		}

		template <typename T>
		void for_each_thumbnail(const T& functor) {
			for (const auto& file : m_thumbnails.entryList(QDir::Filter::Files)) {
				functor(file);
			}
		}

		QString resource(int index) const {
			return resource_dir() + m_resources.entryList(QDir::Filter::Files)[index];
		}

		QString resource_dir() const {
			return m_resources.absolutePath() + "/";
		}

		QString thumbnail(int index) const {
			return thumbnail_dir() + m_thumbnails.entryList(QDir::Filter::Files)[index];
		}

		QString thumbnail_dir() const {
			return m_thumbnails.absolutePath() + "/";
		}

	private:
		QDir m_resources;
		QDir m_thumbnails;
	};

	namespace resources {
		struct scenario_tiles : public resource_collection {
			scenario_tiles() : resource_collection("scenario_book/scenario_tiles/") { }
		};

		struct scenario_tokens : public resource_collection {
			scenario_tokens() : resource_collection("scenario_book/tokens") { }
		};

		struct monster_tokens : public resource_collection {
			monster_tokens() : resource_collection("scenario_book/monsters") { }
		};
	}
}