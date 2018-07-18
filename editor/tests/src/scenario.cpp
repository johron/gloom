#include "gtest/gtest.h"
#include "src/scenario/scenario.h"
#include "src/resources/resource_collection.h"

TEST(scenario, add_room) {
	gloom::scenario scenario;
	EXPECT_TRUE(scenario.get_rooms().empty());
	scenario.add_room(gloom::room(gloom::resources::scenario_tiles()[0]));
	EXPECT_EQ(scenario.get_rooms().size(), 1);
}