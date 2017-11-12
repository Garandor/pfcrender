#Check for Qt5
find_package(Qt5 REQUIRED Core Test OPTIONAL_COMPONENTS Quick)

if(Qt5Test_FOUND)
        enable_testing()

        set(CMAKE_AUTOMOC ON)


        include_directories(
                ${CMAKE_SOURCE_DIR}/src
                ${CMAKE_SOURCE_DIR}/src/ViewModel
                ${CMAKE_SOURCE_DIR}/src/Plugins
                ${Qt5Core_INCLUDES}
                ${Qt5Test_INCLUDES}
                )

        #CLI Testing
        add_executable(test_cli "Test_CLI.cpp")

        target_link_libraries(test_cli PRIVATE
            Qt5::Core
            Qt5::Test
            plugin_LSYS
            )

        add_test(NAME Test_CLI COMMAND test_cli)

        #GUI Testing
        add_executable(test_gui
            "Test_GUI.cpp"
            "../src/ViewModel/ViewModelBuilder.cpp"
            )

        target_link_libraries(test_gui PRIVATE
            Qt5::Core
            Qt5::Quick
            Qt5::Test
            plugin_LSYS
            )

        add_test(NAME Test_GUI COMMAND test_gui)

endif()
