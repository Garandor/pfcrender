cmake_minimum_required(VERSION 2.8.4)

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Major version number.")
set(VERSION_MINOR   1   CACHE STRING "Minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

add_subdirectory(doc)
add_subdirectory(lib)
add_subdirectory(src)

add_subdirectory(test)
