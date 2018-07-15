set(name "gloom-tests")

set(src_files
"src/resource_path.cpp")

add_executable(${name} ${src_files})

target_link_libraries(${name} "gloom-lib")
target_link_libraries(${name} "gtest_main")

target_include_directories(${name} PUBLIC  "../lib")

set_target_properties(${name} PROPERTIES FOLDER "gloom")
