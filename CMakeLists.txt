cmake_minimum_required(VERSION 3.1)

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Major version number.")
set(VERSION_MINOR   4   CACHE STRING "Minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(GENERATE_UNITTESTS "Enable building and running of ctest unit testing files" ON)
option(GENERATE_DOCS "Enable building and running of Doxygen doc creation" ON)


INCLUDE_DIRECTORIES("lib/GSL/include")
add_subdirectory(src)

if(GENERATE_UNITTESTS)
        enable_testing()
        add_subdirectory(test)
endif()

if(GENERATE_DOCS)
        add_subdirectory(doc)
endif()
