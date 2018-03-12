find_package(Qt5 REQUIRED Core)
set (PLUGIN_NAME plugin_STDOUT)
set (TEST_NAME test_STDOUT)

set (SRC

    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Export.h"

    "stdout.cpp"
    "stdout.h"
    )

add_library(${PLUGIN_NAME} SHARED ${SRC} )

target_include_directories(${PLUGIN_NAME} PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_SOURCE_DIR}/src
    )

target_link_libraries(${PLUGIN_NAME} PUBLIC
            Qt5::Core
    )

target_link_libraries(${PLUGIN_NAME} INTERFACE plugin_ALL)

COPY_TO_PLUGIN_DIR(${PLUGIN_NAME})

#Add unit tests
if(BUILD_UNITTESTS)
        find_package(Qt5 REQUIRED Test)

        set(CMAKE_AUTOMOC ON)

        add_executable(${TEST_NAME}
            test_stdout.cpp
            ${SRC}
            )
        target_include_directories(${TEST_NAME} PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}"
            ${CMAKE_SOURCE_DIR}/src
            "${PLUGIN_DIR}"
            )
        target_link_libraries(${TEST_NAME} PRIVATE
            Qt5::Core
            Qt5::Test)

        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endif()
