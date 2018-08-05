#pragma once

namespace gloom {
	// this is written with the assumption that resources won't change after application start.

	struct resource : private std::pair<QString, QString> {
		resource() = default;
		resource(const QString& first, const QString& second)
			: std::pair<QString, QString>(first, second) { }
		resource(const QJsonObject& data) {
			deserialize(data);
		}

		const QString& original() const { return first; }
		const QString& thumbnail() const { return second; }

		QJsonObject serialize() const {
			return QJsonObject{ {"original", original()}, {"thumbnail", thumbnail()} };
		}

		void deserialize(const QJsonObject& data) {
			first = data["original"].toString();
			second = data["thumbnail"].toString();
		}
	};

	struct resource_collection {
		resource_collection(const QString& path) {
			const auto resource_path = "../resources/original/" + path;
			const auto thumbnail_path = "../resources/thumbnail/" + path;
			const auto resource_files = QDir(resource_path).entryList(QDir::Filter::Files);
			const auto thumbnail_files = QDir(thumbnail_path).entryList(QDir::Filter::Files);
			for (int i=0; i<resource_files.size(); ++i) {
				m_resources.emplace_back(resource_path + resource_files[i], thumbnail_path + thumbnail_files[i]);
			}
		}

		decltype(auto) begin() { return m_resources.begin(); }
		decltype(auto) end() { return m_resources.end(); }

		size_t count() const {
			return m_resources.size();
		}

		bool empty() const {
			return m_resources.empty();
		}

		const resource& operator[](size_t index) const {
			return m_resources[index];
		}

		resource& operator[](size_t index) {
			return m_resources[index];
		}

	private:
		std::vector<resource> m_resources;
	};

	namespace resources {
		struct scenario_tiles : public resource_collection {
			scenario_tiles() : resource_collection("scenario_book/scenario_tiles/") { }
		};

		struct scenario_tokens : public resource_collection {
			scenario_tokens() : resource_collection("scenario_book/tokens/") { }
		};

		struct monster_tokens : public resource_collection {
			monster_tokens() : resource_collection("scenario_book/monsters/") { }
		};
	}
}