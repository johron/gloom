#include "gtest/gtest.h"
#include "src/scenario/commands/place_room.h"
#include "src/editor/editor.h"

TEST(commands, place_room) {
	gloom::editor editor;
	const auto& scenario = editor.get_scenario();
	EXPECT_EQ(scenario.get_rooms().size(), 0);
	const auto resource = gloom::resources::scenario_tiles()[0];
	editor.apply(new gloom::commands::place_room(resource, editor.get_scenario()));
	EXPECT_EQ(scenario.get_rooms().size(), 1);
	editor.undo();
	EXPECT_EQ(scenario.get_rooms().size(), 0);
	editor.redo();
	EXPECT_EQ(scenario.get_rooms().size(), 1);
}

TEST(commands, remove_room) {
	gloom::editor editor;
	auto& scenario = editor.get_scenario();
	const auto resource = gloom::resources::scenario_tiles()[0];
	editor.apply(new gloom::commands::place_room(resource, editor.get_scenario()));
	EXPECT_EQ(scenario.get_rooms().size(), 1);
	editor.apply(new gloom::commands::remove_room(*scenario.get_rooms().front(), scenario));
	EXPECT_EQ(scenario.get_rooms().size(), 0);
	editor.undo();
	EXPECT_EQ(scenario.get_rooms().size(), 1);
	editor.redo();
	EXPECT_EQ(scenario.get_rooms().size(), 0);
}