#include "gtest/gtest.h"
#include "src/scenario/room/room_factory.h"
#include "src/scenario/room/room_directory.h"
#include "src/scenario/room/room_filter.h"

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

class room_directory : public ::testing::Test {
public:
	room_directory() 
		: m_directory(std::make_unique<gloom::room_directory>(util::json_file_reader::read(util::path::resource_root() + "data/room_list.json").object())) { }

	const gloom::room_directory& get_directory() const {
		return *m_directory;
	}

private:
	std::unique_ptr<gloom::room_directory> m_directory;
};

TEST_F(room_directory, default_rooms) {
	const auto num_rooms = get_directory().size();
	EXPECT_EQ(num_rooms, 60);
}

TEST_F(room_directory, get_rooms) {
	const auto stone_rooms = gloom::room_filter::style(gloom::room_style::stone);
	const auto rooms = get_directory().get_rooms(stone_rooms);
	EXPECT_EQ(rooms.size(), 24);
}
