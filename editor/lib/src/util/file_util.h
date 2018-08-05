#pragma once

namespace util {
	struct file_reader {
		static QByteArray read(const QString& filename) {
			QFile file(filename);
			file.open(QFile::ReadOnly);
			const auto data = file.readAll();
			file.close();
			return data;
		}
	};

	struct file_writer {
		static bool write(const QString& filename, const QByteArray& data) {
			QFile file(filename);
			file.open(QFile::WriteOnly);
			const auto written_data = file.write(data);
			file.close();
			return written_data == data.size();
		}
	};

	struct json_file_reader {
		static decltype(auto) read(const QString& filename) {
			return QJsonDocument::fromJson(file_reader::read(filename));
		}
	};

	struct json_file_writer {
		static decltype(auto) write(const QString& filename, const QJsonDocument& data, QJsonDocument::JsonFormat format = QJsonDocument::Indented) {
			return file_writer::write(filename, data.toJson(format));
		}
	};
}