find_package(Qt5 REQUIRED Core)

add_library(plugin_LSYS SHARED

    #XXX: This might break once we get more than 1 plugin because of MOC. Might need to refactor interfaces into their own library
    "${PLUGIN_DIR}/Plugin.h"
    "${PLUGIN_DIR}/Import.h"

    "fxt/stringsubst.cc"

    "LSYS.cpp"
    "LSYS.h"
    )

target_include_directories(plugin_LSYS PRIVATE
    ${PLUGIN_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/fxt
    )

target_link_libraries(plugin_LSYS PRIVATE
    Qt5::Core
    )

target_link_libraries(plugin_LSYS INTERFACE plugin_ALL)

#Add unit tests
if(GENERATE_UNITTESTS)
        find_package(Qt5 REQUIRED Test)
        enable_testing()

        set(CMAKE_AUTOMOC ON)

        add_executable(test_lsys
            Test_LSYS.cpp)
        target_include_directories(test_lsys PRIVATE
            "${PLUGIN_DIR}")
        target_link_libraries(test_lsys PRIVATE
            plugin_LSYS
            Qt5::Core
            Qt5::Test)

        add_test(NAME Test_LSYS COMMAND test_lsys)
endif()
