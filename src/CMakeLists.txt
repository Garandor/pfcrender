configure_file(projectinfo.h.in projectinfo.h @ONLY)

option(COMPILE_GUI_SUPPORT "For tinyfication, turn this off to not compile any GUI code into the application. Batch mode usage only" ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

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
        "QtGUI/PFCRender.cpp"

	"Plugin/Plugin_Registry.cpp"

        "PFCStart.cpp"
)

set(INC 

        "QtGUI/PFCRender.h"

        "Plugin/Plugin_Registry.h"
)




#Build executable
if(COMPILE_GUI_SUPPORT)
        add_executable(${PROJECT_NAME} ${SRC} ${INC} ${qml_QRC})
else()
        add_executable(${PROJECT_NAME} ${SRC} ${INC})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_BINARY_DIR}
	"Plugin"
)

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)
endif()

