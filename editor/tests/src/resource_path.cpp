#include "gtest/gtest.h"
#include "src/model/resource_path.h"

TEST(resource_path, scenario_tiles) {
	gloom::resources::scenario_tiles resources;
	EXPECT_EQ(resources.count(), 60);
}

TEST(resource_path, scenario_tokens) {
	gloom::resources::scenario_tokens resources;
	EXPECT_EQ(resources.count(), 53);
}

TEST(resource_path, monster_tokens) {
	gloom::resources::monster_tokens resources;
	EXPECT_EQ(resources.count(), 70);
}

TEST(resource_path, for_each) {
	gloom::resources::scenario_tiles resources;
	size_t count(0);
	auto file_counter = [&count](const QString& filename) { ++count; };

	resources.for_each(file_counter);
	EXPECT_EQ(count, resources.count());
}

TEST(resource_path, subscript_operator) {
	gloom::resources::scenario_tiles resources;
	const auto filename = resources[0];
	EXPECT_EQ(filename, "a1a-man-made_stone_u1.png");
}

TEST(resource_path, absolute_path) {
	gloom::resources::scenario_tiles resources;
	const auto absolute_path = resources.path() + resources[0];
	EXPECT_TRUE(QFile::exists(absolute_path));
}