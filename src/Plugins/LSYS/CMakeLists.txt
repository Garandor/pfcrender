
add_library(plugin_LSYS SHARED

    #XXX: This might break once we get more than 1 plugin because of MOC. Might need to refactor interfaces into their own library
    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Import.h"

    "fxt/stringsubst.cc"

    "LSYS.cpp"
    "LSYS.h"
    "PFCModel.cpp"
    "PFCModel.h"
    )

target_include_directories(plugin_LSYS PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/fxt
    )

target_link_libraries(plugin_LSYS PRIVATE
    Qt5::Core
    Qt5::Quick
    )

target_link_libraries(plugin_LSYS INTERFACE plugin_ALL)
