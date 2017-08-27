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
endif()

set(SRC "PFCStart.cpp"

	"Plugin/Plugin_Registry.cpp"
)

set(INC "PFCStart.h"

	"Plugin/Plugin_Registry.h"
)

#Build executable
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_BINARY_DIR}
	"Plugin"
)

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)

if(COMPILE_GUI_SUPPORT)
	target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Qml Qt5::Quick)
endif()

