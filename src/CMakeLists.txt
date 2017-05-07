file(GLOB_RECURSE SRCFLS *.cpp)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

#Build executable
add_executable(${PROJECT_NAME} ${SRCFLS})
