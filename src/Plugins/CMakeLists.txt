SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)

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
