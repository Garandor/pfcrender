cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS_COVERAGE "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -lgcov")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto=full")

project(pfcrender)

# The project version number.
set(VERSION_MAJOR   0   )
set(VERSION_MINOR   8   )
set(VERSION_PATCH   0   )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(GENERATE_UNITTESTS "Enable building and running of ctest unit testing files" ON)
option(GENERATE_DOCS "Enable building and running of Doxygen doc creation" ON)

#--- START SUBMODULES
#gsl
include_directories("lib/GSL/include")

#QNanoPainter
include_directories("lib/qnanopainter/libqnanopainter")
add_subdirectory("lib/qnanopainter")

find_package(Qt5 REQUIRED Gui)

find_package(OpenGL REQUIRED)
LINK_LIBRARIES(OpenGL::GL)
LINK_LIBRARIES(	Qt5::Gui_EGL
    )
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
add_definitions(
    -DQT_NO_INFO_OUTPUT
    -DQNANO_USE_RENDERNODE
    -DQNANO_ENABLE_GLES3
    -DQNANO_QT_GL_INCLUDE
   )

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

