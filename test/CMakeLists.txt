set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0)

if(Boost_FOUND)
	include_directories(
		${Boost_INCLUDE_DIRS}
		${CMAKE_SOURCE_DIR}/lib/CUTE/cute
		${CMAKE_SOURCE_DIR}/src
		)

	#file(GLOB_RECURSE SRC *.cpp)
	#add_executable(cute ${SRC})
	add_executable(cute Test.cpp)
	add_test(NAME UnitTests COMMAND cute)
	target_link_libraries(cute ${Boost_LIBRARIES})
else()
	message(STATUS "Boost not found, no unit testing possible")
endif()
