#include "gtest/gtest.h"
#include "../../lib/src/util/file_util.h"

QJsonDocument make_sample_json() {
	return QJsonDocument({ { "sample", "data" },	{ "number", 1234 }, { "boolean", false } });
}

TEST(file_util, json_utils) { 
	const auto write_success = util::json_file_writer::write("sample.json", make_sample_json());
	EXPECT_TRUE(write_success);

	const auto read_json = util::json_file_reader::read("sample.json");
	EXPECT_EQ(read_json, make_sample_json());

	EXPECT_TRUE(QFile::remove("sample.json"));
}
