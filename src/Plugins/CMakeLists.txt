SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)

find_package(Qt5 REQUIRED Quick)

#Save so plugins can find the common interface headers
SET(PLUGIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(plugin_ALL INTERFACE )

target_link_libraries(plugin_ALL INTERFACE Qt5::Quick)

#add subdirectories of each plugin to be built

OPTION (Use_Plugin_LSYS "Compile import plugin using stringsubst.h to generate the model string" ON)
if(Use_Plugin_LSYS)
        add_subdirectory(LSYS)
endif()
