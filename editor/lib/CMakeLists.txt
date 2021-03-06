set(name "gloom-lib")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT_HOME}/lib/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(AUTOMOC_MOC_OPTIONS "-f E:/dev/gloom/editor/shared/precompiled_header.h")

set(qrc_files "")

set(src_editor
	"src/editor/editor.cpp"
	"src/editor/editor.h"
	"src/editor/main_window.cpp"
	"src/editor/main_window.h"
	"src/editor/main_window.ui"
	"src/editor/room_browser.ui")

set(src_layout_editor
	"src/editor/layout/layout_editor.cpp"
	"src/editor/layout/layout_editor.h")

set(src_resources
	"src/resources/resource_browser.cpp"
	"src/resources/resource_browser.h"
	"src/resources/resource_collection.h")

set(src_room
	"src/scenario/room/room_directory.h"
	"src/scenario/room/room_factory.cpp"
	"src/scenario/room/room_factory.h"
	"src/scenario/room/room.cpp"
	"src/scenario/room/room.h"
	"src/scenario/room/room_id.h"
	"src/scenario/room/room_filter.h")

set(src_scenario
	"src/scenario/scenario.cpp"
	"src/scenario/scenario.h"
	"src/scenario/token.h"
	"src/scenario/monster.h")

set(src_scenario_view
	"src/scenario/view/room_view.cpp"
	"src/scenario/view/room_view.h"
	"src/scenario/view/scenario_view.cpp"
	"src/scenario/view/scenario_view.h")

set(src_scenario_commands
	"src/scenario/commands/place_room.h"
	"src/scenario/commands/place_token.h"
	"src/scenario/commands/place_monster.h")

set(src_util
	"src/util/_moc_precompiled_header_include.h"
	"src/util/hexagon.h"
	"src/util/file_util.h"
	"src/util/path_util.h"
	"src/util/flow_layout.cpp"
	"src/util/flow_layout.h"
	"src/util/graphics_view_zoom.cpp"
	"src/util/graphics_view_zoom.h")

set(readme
	"../../readme.md")

set(all_sources
	${qrc_files}
	${src_editor}
	${src_layout_editor}
	${src_resources}
	${src_room}
	${src_scenario}
	${src_scenario_view}
	${src_scenario_commands}
	${src_room_builder}
	${src_precompiled}
	${src_util}
	${readme})

add_library(${name} ${all_sources})

source_group("src\\editor" FILES ${src_editor})
source_group("src\\editor\\layout" FILES ${src_layout_editor})
source_group("src\\resources" FILES ${src_resources})
source_group("src\\scenario" FILES ${src_scenario})
source_group("src\\room_builder" FILES ${src_room_builder})
source_group("src\\scenario\\view" FILES ${src_scenario_view})
source_group("src\\scenario\\commands" FILES ${src_scenario_commands})
source_group("src\\scenario\\room" FILES ${src_room})
source_group("src\\util" FILES ${src_util})
source_group("src\\precompiled" FILES ${src_precompiled})
source_group("files\\qrc" FILES ${qrc_files})
source_group("files\\readme" FILES ${readme})

target_link_libraries(${name} Qt5::Widgets)
target_link_libraries(${name} Qt5::Core)
target_link_libraries(${name} Qt5::Gui)

set_target_properties(${name} PROPERTIES FOLDER "gloom")
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})
set_target_properties(${name} PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
set_target_properties(${name} PROPERTIES MAKE_CXX_STANDARD 17)
set_target_properties(${name} PROPERTIES CMAKE_CXX_STANDARD_REQUIRED ON)

cotire(${name})

include("../scripts/cmake/copy_resources.cmake")