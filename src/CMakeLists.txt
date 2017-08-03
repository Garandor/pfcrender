configure_file(projectinfo.h.in projectinfo.h @ONLY)

set(SRC LSYS.cpp PFCRender.cpp)
set(INC LSYS.h PFCRender.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

#Check for Qt5
find_package(Qt5Core REQUIRED)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${INCDIRS}
)


add_subdirectory(CLI)
add_subdirectory(Export)
add_subdirectory(GUI)
add_subdirectory(Model)

#Build executable
add_executable(${PROJECT_NAME} ${SRC})

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)
