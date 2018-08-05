#pragma once
#include "room_directory.h"

namespace gloom {
	namespace room_filter {
		decltype(auto) style(room_style style) {
			return [style](const room_directory::entry& entry) {
				return entry.m_style == style;
			};
		}
	}
}