cmake_minimum_required(VERSION 3.5)
project("gloom")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY AUTOMOC_FOLDER generated)
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER generated)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER generated)

add_subdirectory("editor")