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

        #QNanoPainter
        qt5_add_resources(qml_QRC ${CMAKE_SOURCE_DIR}/lib/qnanopainter/libqnanopainter/libqnanopainterdata.qrc)

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
        "QtGUI/QNanoPaintedCurve.cpp"
        "QtGUI/QNanoCurvePainter.cpp"
)

set(INC 
        "Common/Config_Registry.h"
        "Common/Plugin_Registry.h"
        "Common/Sequence_Walker.h"
        "Common/CLIParser.h"
        "Common/CLIOptions.h"

        "util/PolarVector2D.h"

        "Model/ModelStringParser.h"
        "Model/ModelStringBuilder.h"
        "Model/LSYSModel.h"
        "Model/LSYSModelImpl.h"

        "QtCLI/PFCRenderCLI.h"

        "QtGUI/PFCRenderGUI.h"
        "QtGUI/QNanoPaintedCurve.h"
        "QtGUI/QNanoCurvePainter.h"

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
        "${Qt5Quick_INCLUDE_DIRS}"
        "${Qt5Qml_INCLUDE_DIRS}"
)

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)

#make CMake drop the main exe into the root bin folder
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)

        target_link_libraries(${PROJECT_NAME} qnanopainter)
endif()

#descend into plugins subdirectory to build plugins
add_subdirectory(Plugins)


#on Windows: Copy Qt libraries to Executable folder, src https://gist.github.com/Rod-Persky/e6b93e9ee31f9516261b
if (WIN32)
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	    COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif(WIN32)
