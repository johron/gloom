set(name "gloom-bin")

set(src_files
    "src/main.cpp")

add_executable(${name} WIN32 ${src_files})

target_link_libraries(${name} "gloom-lib")

target_include_directories(${name} PUBLIC  "../lib")

set_target_properties(${name} PROPERTIES FOLDER "gloom")
