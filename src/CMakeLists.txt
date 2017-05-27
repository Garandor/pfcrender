configure_file(projectinfo.h.in projectinfo.h @ONLY)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE INCFLS *.h)

foreach(_hdrfile ${INCFLS})
	get_filename_component(_dir ${_hdrfile} PATH)
	list (APPEND INCDIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCDIRS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

#Check for Qt5
find_package(Qt5Core REQUIRED)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${INCDIRS}
)

#Build executable
add_executable(${PROJECT_NAME} ${SRCS})

#Link with Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core)
