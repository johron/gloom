set(name "gloom-lib")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT_HOME}/lib/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(src_files
    "src/test.cpp"
    "src/test.h")

add_library(${name} ${src_files})

target_link_libraries(${name} Qt5::Widgets)
target_link_libraries(${name} Qt5::Core)
target_link_libraries(${name} Qt5::Gui)

set_target_properties(${name} PROPERTIES FOLDER "gloom")