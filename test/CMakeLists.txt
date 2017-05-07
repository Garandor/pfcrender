include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SRC *.cpp)
add_executable(unittest ${SRC})
add_test(NAME UnitTests COMMAND unittest)
