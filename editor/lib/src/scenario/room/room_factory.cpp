#include "room_factory.h"

namespace {
// 	gloom::hex_layout get_layout(gloom::room_id id) {
// 		switch (id) {
// 		case gloom::room_id::a1a:
// 			break;
// 		case gloom::room_id::a1b:
// 			break;
// 		case gloom::room_id::a2a:
// 			break;
// 		case gloom::room_id::a2b:
// 			break;
// 		case gloom::room_id::a3a:
// 			break;
// 		case gloom::room_id::a3b:
// 			break;
// 		default:
// 			break;
// 		}
// 	}
}

namespace gloom {
	room room_factory::create(room_id id) const {
		return room(id);
	}
}