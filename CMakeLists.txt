cmake_minimum_required(VERSION 2.8)

project(pfcrender)

add_subdirectory(lib)
add_subdirectory(src)


enable_testing()
add_subdirectory(test)
