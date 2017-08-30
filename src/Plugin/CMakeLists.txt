#Save so plugins can find the common interface headers
SET(PLUGIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(plugin_all INTERFACE)

#add subdirectories of each plugin to be built
add_subdirectory(LSYS)
