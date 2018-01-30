SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)

#Save so plugins can find the common interface headers
SET(PLUGIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(plugin_ALL INTERFACE )

#add subdirectories of each plugin to be built
add_subdirectory(LSYS)
add_subdirectory(SVG)
add_subdirectory(STDOUT)
