#include "gtest/gtest.h"
#include "src/model/resource_collection.h"

TEST(resource_collection, scenario_tiles) {
	gloom::resources::scenario_tiles tiles;
	EXPECT_EQ(tiles.count(), 60);
}

TEST(resource_collection, scenario_tokens) {
	gloom::resources::scenario_tokens tokens;
	EXPECT_EQ(tokens.count(), 53);
}

TEST(resource_collection, monster_tokens) {
	gloom::resources::monster_tokens monsters;
	EXPECT_EQ(monsters.count(), 70);
}

TEST(resource_collection, empty) {
	gloom::resource_collection collection("does_not_exist");
	EXPECT_EQ(collection.count(), 0);
	EXPECT_TRUE(collection.empty());
}

TEST(resource_collection, for_each_resource) {
	gloom::resources::scenario_tiles resources;
	size_t count(0);
	auto file_counter = [&count](const QString& filename) { ++count; };
	resources.for_each_resource(file_counter);
	EXPECT_EQ(count, resources.count());
}

TEST(resource_collection, resource_path) {
	gloom::resources::scenario_tiles tiles;
	const auto resource_path = tiles.resource(0);
	EXPECT_TRUE(QFile::exists(resource_path));
}

TEST(resource_collection, thumbnail_path) {
	gloom::resources::scenario_tiles tiles;
	const auto resource_path = tiles.thumbnail(0);
	EXPECT_TRUE(QFile::exists(resource_path));
}