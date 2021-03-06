find_package(Qt5 REQUIRED Core)

set (LSYS_SRC

    "${CMAKE_SOURCE_DIR}/src/Common/Plugin_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/Config_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/CLIParser.cpp"

    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Import.h"

    "fxt/stringsubst.cc"

    "LSYS.cpp"
    "LSYS.h"

    "LSYSModelFactory.cpp"
    "LSYSModelFactory.h"
    )

add_library(plugin_LSYS SHARED ${LSYS_SRC} )

target_include_directories(plugin_LSYS PRIVATE
    "${PLUGIN_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/fxt"
    "${CMAKE_SOURCE_DIR}/src"
    )

target_link_libraries(plugin_LSYS PRIVATE
    Qt5::Core
    )

target_link_libraries(plugin_LSYS INTERFACE plugin_ALL)

COPY_TO_PLUGIN_DIR(plugin_LSYS)

#Add unit tests
if(BUILD_UNITTESTS)
        find_package(Qt5 REQUIRED Test)

        set(CMAKE_AUTOMOC ON)

        add_executable(test_lsys
            Test_LSYS.cpp
            )
        target_include_directories(test_lsys PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_SOURCE_DIR}/src"
            "${PLUGIN_DIR}"
            )
        target_link_libraries(test_lsys PRIVATE
            Qt5::Core
            Qt5::Test
            plugin_LSYS
            )

        add_test(NAME Test_LSYS COMMAND test_lsys)
endif()
