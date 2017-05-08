cmake_minimum_required(VERSION 2.8)

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   1   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)


add_subdirectory(doc)
add_subdirectory(lib)
add_subdirectory(src)


enable_testing()
add_subdirectory(test)
