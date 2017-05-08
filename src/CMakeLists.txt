configure_file(projectinfo.h.in projectinfo.h @ONLY)

file(GLOB_RECURSE SRCFLS *.cpp)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

#Build executable
add_executable(${PROJECT_NAME} ${SRCFLS})
