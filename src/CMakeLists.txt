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
find_package(Qt5Core REQUIRED)

if(COMPILE_GUI_SUPPORT)
	find_package(Qt5Gui REQUIRED)
	find_package(Qt5Qml REQUIRED)
	find_package(Qt5Quick REQUIRED)

        #Add QtQuick resources
        qt5_add_resources(qml_QRC QtGUI/qml.qrc)

endif()

set(SRC
        "PFCStart.cpp"

        "Plugins/Plugin_Registry.cpp"

        "Model/LSYSModel.cpp"

        "ViewModel/ViewModelFactory.cpp"
        "ViewModel/CustomGeometryModel.cpp"


        "QtGUI/PFCRender.cpp"
)

set(INC 

        "Plugins/Plugin_Registry.h"

        "Model/LSYSModel.h"

        "ViewModel/ViewModelFactory.h"
        "ViewModel/CustomGeometryModel.h"

        "QtGUI/PFCRender.h"

)




#Build executable
if(COMPILE_GUI_SUPPORT)
        add_executable(${PROJECT_NAME} ${SRC} ${INC} ${qml_QRC})
else()
        add_executable(${PROJECT_NAME} ${SRC} ${INC})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_BINARY_DIR}
)

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)
endif()

#descend into plugins subdirectory to build plugins
add_subdirectory(Plugins)
