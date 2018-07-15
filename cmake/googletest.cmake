set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("third_party/googletest")

set_target_properties("gtest" PROPERTIES FOLDER "third_party")
set_target_properties("gtest_main" PROPERTIES FOLDER "third_party")
set_target_properties("gmock" PROPERTIES FOLDER "third_party")
set_target_properties("gmock_main" PROPERTIES FOLDER "third_party")