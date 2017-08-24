configure_file(projectinfo.h.in projectinfo.h @ONLY)

option(COMPILE_GUI_SUPPORT "For tinyfication, turn this off to not compile any GUI code into the application. Batch mode usage only" ON)

set(SRC PFCStart.cpp)
set(INC PFCStart.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

#Check for Qt5
find_package(Qt5Core REQUIRED)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${INCDIRS}
)


add_subdirectory(CLI)
add_subdirectory(Plugin)
add_subdirectory(Model)
add_subdirectory(QtGUI)
add_subdirectory(QtCLI)

#Build executable
add_executable(${PROJECT_NAME} ${SRC})

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)
