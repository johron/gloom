set(name "gloom-tests")

set(src_files
"src/resource_path.cpp")

add_executable(${name} ${src_files})

target_link_libraries(${name} "gloom-lib")
target_link_libraries(${name} "gtest_main")

target_include_directories(${name} PUBLIC  "../lib")

set_target_properties(${name} PROPERTIES FOLDER "gloom")
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})
set_target_properties(${name} PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)

cotire(${name})