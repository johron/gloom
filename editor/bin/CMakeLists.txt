set(name "editor-bin")

set(src_files
    "src/main.cpp")

add_executable(${name} ${src_files})

target_link_libraries(${name} "editor-lib")
