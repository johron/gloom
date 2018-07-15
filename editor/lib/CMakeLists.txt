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
	"src/view/scenario_view.cpp"
	"src/view/scenario_view.h")

set(src_model
	"src/model/resource_path.h"
	"src/model/settings.cpp"
	"src/model/settings.h"
	"src/model/editor.cpp"
	"src/model/editor.h")

set(src_files
    "src/test.cpp"
    "src/test.h")

set(all_sources
	${qrc_files}
	${src_view}
	${src_model})

add_library(${name} ${all_sources})

source_group("src\\view" FILES ${src_view})
source_group("src\\model" FILES ${src_model})
source_group("qrc" FILES ${qrc_files})

target_link_libraries(${name} Qt5::Widgets)
target_link_libraries(${name} Qt5::Core)
target_link_libraries(${name} Qt5::Gui)

set_target_properties(${name} PROPERTIES FOLDER "gloom")

# works, but don't want to run each time we run cmake
#execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/editor/resources ${CMAKE_BINARY_DIR}/editor/resources)

include("../scripts/cmake/copy_resources.cmake")