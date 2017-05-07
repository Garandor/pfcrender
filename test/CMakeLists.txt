include_directories(
	${CMAKE_SOURCE_DIR}/lib/CUTE/cute
	${CMAKE_SOURCE_DIR}/src
	)

file(GLOB_RECURSE SRC *.cpp)
#add_executable(cute ${SRC})
add_executable(cute Test.cpp)
add_test(NAME UnitTests COMMAND cute)
