file(GLOB_RECURSE resource_files RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/editor/resources/*)
message("-- Copy resource files")

# preferably this would copy files on first build, and then update content on
# subsequent builds to match folder in data
foreach(file ${resource_files})
	configure_file(${CMAKE_SOURCE_DIR}/${file} ${CMAKE_BINARY_DIR}/${file} COPYONLY)
endforeach()