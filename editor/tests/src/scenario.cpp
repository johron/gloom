#include "gtest/gtest.h"
#include "src/editor/editor.h"
#include "src/scenario/commands/place_room.h"

TEST(scenario, serialize) {
	gloom::editor editor;
	auto& original = editor.get_scenario();
	const auto rooms = gloom::resources::scenario_tiles();

	editor.apply(new gloom::commands::place_room(rooms[0], original));
	auto& room = original.get_room(rooms[0].original());
	room.set_position({ 10, 10 });
	room.set_rotation(100);
	const auto original_data = original.serialize();

	gloom::scenario compare;
	compare.deserialize(QJsonObject(original_data));
	const auto compare_data = compare.serialize();

	EXPECT_EQ(original_data, compare_data);
}