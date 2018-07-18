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

set(src_view
	"src/view/main_window.cpp"
	"src/view/main_window.h"
	"src/view/main_window.ui"
	"src/view/resource_browser.h"
	"src/view/resource_browser.cpp"
	"src/view/scenario_view.cpp"
	"src/view/scenario_view.h")

set(src_model
	"src/model/resource_collection.h"
	"src/model/settings.cpp"
	"src/model/settings.h"
	"src/model/editor.cpp"
	"src/model/editor.h")

set(src_util
	"src/util/flow_layout.cpp"
	"src/util/flow_layout.h")

set(readme
	"../../readme.md")

set(all_sources
	${qrc_files}
	${src_view}
	${src_model}
	${src_util}
	${readme})

add_library(${name} ${all_sources})

source_group("src\\view" FILES ${src_view})
source_group("src\\model" FILES ${src_model})
source_group("src\\util" FILES ${src_util})
source_group("qrc" FILES ${qrc_files})
source_group("readme" FILES ${readme})

target_link_libraries(${name} Qt5::Widgets)
target_link_libraries(${name} Qt5::Core)
target_link_libraries(${name} Qt5::Gui)

set_target_properties(${name} PROPERTIES FOLDER "gloom")

include("../scripts/cmake/copy_resources.cmake")