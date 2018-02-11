find_package(Qt5 REQUIRED Core Qml Gui Quick Svg PrintSupport)

set (PLUGIN_NAME plugin_pdf)
set (TEST_NAME test_pdf)

set (SRC

    "${CMAKE_SOURCE_DIR}/src/Common/Plugin_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/Config_Registry.cpp"
    "${CMAKE_SOURCE_DIR}/src/Common/CLIParser.cpp"

    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Export.h"

    "pdf.cpp"
    "pdf.h"

    "BboxParse.cpp"
    "BboxParse.h"

    "QPainterParse.cpp"
    "QPainterParse.h"

    )

add_library(${PLUGIN_NAME} SHARED ${SRC} )

target_include_directories(${PLUGIN_NAME} PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_SOURCE_DIR}/src
    )

target_link_libraries(${PLUGIN_NAME} PUBLIC
            Qt5::Core
            Qt5::Gui
            Qt5::Qml
            Qt5::Quick
            Qt5::PrintSupport
    )

target_link_libraries(${PLUGIN_NAME} INTERFACE plugin_ALL)

#Add unit tests
if(GENERATE_UNITTESTS)
        find_package(Qt5 REQUIRED Test)

        set(CMAKE_AUTOMOC ON)

        add_executable(${TEST_NAME}
            ${TEST_NAME}.cpp
            ${SRC}
            )
        target_include_directories(${TEST_NAME} PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_SOURCE_DIR}/src"
            "${PLUGIN_DIR}"
            )
        target_link_libraries(${TEST_NAME} PRIVATE
            Qt5::Core
            Qt5::Gui
            Qt5::Qml
            Qt5::Quick
            Qt5::PrintSupport
            Qt5::Test
            )

        add_test(NAME Test_PDF COMMAND ${TEST_NAME})
endif()
