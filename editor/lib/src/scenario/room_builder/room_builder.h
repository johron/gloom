#pragma once
#include "../room.h"

namespace gloom {
	class room_builder : public QGraphicsScene {
	public:
		room_builder() = default;

		room build();
	};
}