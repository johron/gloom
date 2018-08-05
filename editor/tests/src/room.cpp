#include "gtest/gtest.h"
#include "src/scenario/room/room_factory.h"
#include "src/scenario/room/room_directory.h"

TEST(room_factory, create) {
	gloom::room_factory factory;
	const auto room = factory.create(gloom::room_id::a1a);
	EXPECT_EQ(room.get_id(), gloom::room_id::a1a);
}

TEST(room_factory, cell_count) {
	gloom::room_factory factory;
	const auto room_a1a = factory.create(gloom::room_id::a1a);
	EXPECT_EQ(room_a1a.get_cells().size(), 9);

	const auto room_f1a = factory.create(gloom::room_id::f1a);
	EXPECT_EQ(room_f1a.get_cells().size(), 23);
}

TEST(room_directory, size) {
	const auto data = util::json_file_reader::read(util::path::resource_root() + "data/room_list.json").object();
	gloom::room_directory directory(data);

	EXPECT_EQ(directory.size(), 60);
}