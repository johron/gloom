set(name "gloom-lib")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT_HOME}/lib/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(qrc_files "")

set(src_editor
	"src/editor/editor.cpp"
	"src/editor/editor.h"
	"src/editor/main_window.cpp"
	"src/editor/main_window.h"
	"src/editor/main_window.ui")

set(src_resources
	"src/resources/resource_browser.cpp"
	"src/resources/resource_browser.h"
	"src/resources/resource_collection.h")

set(src_scenario
	"src/scenario/scenario.cpp"
	"src/scenario/scenario.h"
	"src/scenario/room.cpp"
	"src/scenario/room.h"
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
	"src/util/flow_layout.cpp"
	"src/util/flow_layout.h")

set(readme
	"../../readme.md")

set(all_sources
	${qrc_files}
	${src_editor}
	${src_resources}
	${src_scenario}
	${src_scenario_view}
	${src_scenario_commands}
	${src_precompiled}
	${src_util}
	${readme})

add_library(${name} ${all_sources})

source_group("src\\editor" FILES ${src_editor})
source_group("src\\resources" FILES ${src_resources})
source_group("src\\scenario" FILES ${src_scenario})
source_group("src\\scenario\\view" FILES ${src_scenario_view})
source_group("src\\scenario\\commands" FILES ${src_scenario_commands})
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