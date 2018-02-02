configure_file(projectinfo.h.in projectinfo.h @ONLY)

option(COMPILE_GUI_SUPPORT "For tinyfication, turn this off to not compile any GUI code into the application. Implies you will use --batch mode only" ON)

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

        "Common/Config_Registry.cpp"
        "Common/Plugin_Registry.cpp"
        "Common/CLIParser.cpp"
        "Common/Sequence_Walker.cpp"

        "PFCStart.cpp"

        "Model/LSYSModelImpl.cpp"

        "QtCLI/PFCRenderCLI.cpp"

        "QtGUI/PFCRenderGUI.cpp"
        "QtGUI/ViewModelBuilder.cpp"
        "QtGUI/CustomGeometryModel.cpp"
)

set(INC 
        "Common/Config_Registry.h"
        "Common/Plugin_Registry.h"
        "Common/Sequence_Walker.h"
        "Common/CLIParser.h"
        "Common/CLIOptions.h"

        "util/PolarVector2D.h"

        "Model/ModelStringParser.h"
        "Model/ModelFactory.h"
        "Model/LSYSModel.h"
        "Model/LSYSModelImpl.h"

        "QtCLI/PFCRenderCLI.h"

        "QtGUI/PFCRenderGUI.h"
        "QtGUI/ViewModelBuilder.h"
        "QtGUI/CustomGeometryModel.h"

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

#make CMake drop the main exe into the root bin folder
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)
endif()

#descend into plugins subdirectory to build plugins
add_subdirectory(Plugins)
