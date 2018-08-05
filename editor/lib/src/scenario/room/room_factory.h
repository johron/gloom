#pragma once
#include "room.h"

namespace gloom {
	class room_factory {
	public:
		room create(room_id id) const;
	};
}