cmake_minimum_required(VERSION 3.1)

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Major version number.")
set(VERSION_MINOR   2   CACHE STRING "Minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(doc)
add_subdirectory(lib)
add_subdirectory(src)

add_subdirectory(test)
