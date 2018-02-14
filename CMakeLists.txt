cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS_COVERAGE "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -lgcov")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto=full")

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   )
set(VERSION_MINOR   9   )
set(VERSION_PATCH   0   )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DEBUG_VERBOSE_MAKEFILE "Enable verbose makefile generation" OFF )
option(BUILD_UNITTESTS "Enable building and running of ctest unit testing files" ON)
option(GENERATE_DOCS "Enable building and running of Doxygen doc creation" ON)

if(DEBUG_VERBOSE_MAKEFILE)
    set( CMAKE_VERBOSE_MAKEFILE on )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

#--- START SUBMODULES
#gsl
include_directories("lib/GSL/include")

#QNanoPainter
add_definitions(
	-DQNANO_QT_GL_INCLUDE	#Platform-specific OpenGL/OpenGLES headers included through Qt::Gui module
        -DQNANO_USE_RENDERNODE
   )
include_directories("lib/qnanopainter/libqnanopainter")
add_subdirectory("lib/qnanopainter/")

#--- END SUBMODULES

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
