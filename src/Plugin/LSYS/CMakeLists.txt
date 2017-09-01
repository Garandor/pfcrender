SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Plugins)

add_library(plugin_LSYS SHARED

    "fxt/stringsubst.cc"

    "LSYS.cpp"
    "LSYS.h"
    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Import.h"
    )

target_include_directories(plugin_LSYS PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/fxt
    )

target_link_libraries(plugin_LSYS PRIVATE
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    )


target_link_libraries(plugin_all INTERFACE plugin_LSYS)
