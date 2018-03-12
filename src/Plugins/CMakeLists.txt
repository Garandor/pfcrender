#SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)
#if(WIN32)
#	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)
#	SET(BUILD_UNITTESTS OFF)
#	MESSAGE(WARNING "Unit Tests not supported on Windows, deactivating")
#endif()

macro (COPY_TO_PLUGIN_DIR target_name)

#copy runtime library to binary dir - https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
add_custom_command(TARGET ${target_name} POST_BUILD        # Adds a post-build event to MyTest
	COMMAND ${CMAKE_COMMAND} -E copy_if_different	# which executes "cmake - E copy_if_different..."
	$<TARGET_FILE:${target_name}>     			# <--this is in-file
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/$<TARGET_FILE_NAME:${target_name}> # <--this is out-file path
)
endmacro()

#Save so plugins can find the common interface headers
SET(PLUGIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(plugin_ALL INTERFACE )

#add subdirectories of each plugin to be built
option(BUILD_PLUGIN_LSYS "Generate L-System import plugin" on )
if(BUILD_PLUGIN_LSYS)
add_subdirectory(LSYS)
endif()

option(BUILD_PLUGIN_STDOUT "Generate STDOUT export plugin " on )
if(BUILD_PLUGIN_STDOUT)
add_subdirectory(STDOUT)
endif()

option(BUILD_PLUGIN_SVG "Generate SVG export plugin" on )
if(BUILD_PLUGIN_SVG )
add_subdirectory(SVG)
endif()

option(BUILD_PLUGIN_PDF "Generate PDF export plugin" on )
if(BUILD_PLUGIN_PDF)
add_subdirectory(PDF)
endif()
