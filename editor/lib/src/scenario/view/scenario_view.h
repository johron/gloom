#pragma once
#include "../scenario.h"

namespace gloom {
	class scenario_view : public QGraphicsScene {
	public:
		scenario_view(scenario& scenario);

	private:
		void add_room_view(const room& room);
		void remove_room_view(const room& room);
	};
}