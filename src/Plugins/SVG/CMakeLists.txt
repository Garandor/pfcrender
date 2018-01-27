find_package(Qt5 REQUIRED Core Gui Quick Svg)

set (SVG_SRC

    "${CMAKE_SOURCE_DIR}/src/Common/Plugin_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/Config_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/CLIParser.cpp"

    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Export.h"

    "SVG.cpp"
    "SVG.h"

    "QPainterParse.cpp"
    "QPainterParse.h"

    )

add_library(plugin_SVG SHARED ${SVG_SRC} )

target_include_directories(plugin_SVG PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_SOURCE_DIR}/src
    )

target_link_libraries(plugin_SVG PUBLIC
            Qt5::Core
            Qt5::Gui
            Qt5::Quick
            Qt5::Svg
    )

target_link_libraries(plugin_SVG INTERFACE plugin_ALL)

#Add unit tests
if(GENERATE_UNITTESTS)
        find_package(Qt5 REQUIRED Test)

        set(CMAKE_AUTOMOC ON)

        add_executable(test_SVG
            Test_SVG.cpp
            ${SVG_SRC}
            )
        target_include_directories(test_SVG PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_SOURCE_DIR}/src"
            "${PLUGIN_DIR}"
            )
        target_link_libraries(test_SVG PRIVATE
            Qt5::Core
            Qt5::Gui
            Qt5::Quick
            Qt5::Svg
            Qt5::Test)

        add_test(NAME Test_SVG COMMAND test_SVG)
endif()
