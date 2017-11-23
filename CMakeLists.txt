cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS_COVERAGE "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -lgcov")


project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   )
set(VERSION_MINOR   5   )
set(VERSION_PATCH   0   )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(GENERATE_UNITTESTS "Enable building and running of ctest unit testing files" ON)
option(GENERATE_DOCS "Enable building and running of Doxygen doc creation" ON)

include_directories("lib/GSL/include")
add_subdirectory(src)

if(GENERATE_UNITTESTS)
        enable_testing()
        add_subdirectory(test)
endif()

if(GENERATE_DOCS)
        add_subdirectory(doc)
endif()


#update version in all relevant files
configure_file("conf/README.md.in" "${CMAKE_SOURCE_DIR}/README.md")
configure_file("conf/appveyor.yml.in" "${CMAKE_SOURCE_DIR}/appveyor.yml")

