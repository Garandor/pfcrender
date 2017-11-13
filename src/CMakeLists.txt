configure_file(projectinfo.h.in projectinfo.h @ONLY)

option(COMPILE_GUI_SUPPORT "For tinyfication, turn this off to not compile any GUI code into the application. Batch mode usage only" ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

if(APPLE AND EXISTS /usr/local/opt/qt5)
        # Homebrew installs Qt5 (up to at least 5.9.1) in
        # /usr/local/qt5, ensure it can be found by CMake since
        # it is not in the default /usr/local prefix.
        list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt5")
endif()

#Check for Qt5
find_package(Qt5 REQUIRED Core)

if(COMPILE_GUI_SUPPORT)
        find_package(Qt5 REQUIRED Gui Qml Quick)

        #Add QtQuick resources
        qt5_add_resources(qml_QRC QtGUI/qml.qrc)

else()
    add_definitions(-DNOGUI)
endif()

set(SRC
        "PFCStart.cpp"

        "Plugins/Plugin_Registry.cpp"

        "Model/LSYSModel.cpp"

        "ViewModel/ViewModelBuilder.cpp"
        "ViewModel/CustomGeometryModel.cpp"


        "CLI/CLIParser.cpp"
        "QtCLI/PFCRender.cpp"
        "QtGUI/PFCRender.cpp"
)

set(INC 

        "Plugins/Plugin_Registry.h"

        "Model/LSYSModel.h"

        "ViewModel/ViewModelBuilder.h"
        "ViewModel/CustomGeometryModel.h"

        "CLI/CLIParser.h"
        "QtCLI/PFCRender.h"
        "QtGUI/PFCRender.h"

        "projectinfo.h.in"
)

#TODO: Split SRC and INC by common and GUI

#Build executable
if(COMPILE_GUI_SUPPORT)
        add_executable(${PROJECT_NAME} ${SRC} ${INC} ${qml_QRC})
else()
        add_executable(${PROJECT_NAME} ${SRC} ${INC})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_BINARY_DIR}"
        "${Qt5Core_INCLUDE_DIRS}"
        "${Qt5Gui_INCLUDE_DIRS}"
        "${Qt5Qml_INCLUDE_DIRS}"
        "${Qt5Quick_INCLUDE_DIRS}"
)

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)
endif()

#descend into plugins subdirectory to build plugins
add_subdirectory(Plugins)
