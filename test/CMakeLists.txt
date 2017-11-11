enable_testing()

set(CMAKE_AUTOMOC ON)

#Check for Qt5
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

include_directories(
	${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/Plugins
        ${Qt5Core_INCLUDES}
        ${Qt5Test_INCLUDES}
        )

#file(GLOB_RECURSE SRC *.cpp)
#add_executable(cute ${SRC})

add_executable(testexe Test.cpp)

target_link_libraries(testexe PRIVATE
    Qt5::Core
    Qt5::Test
    plugin_LSYS
    )

add_test(NAME UnitTests COMMAND testexe)
