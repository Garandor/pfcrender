cmake_minimum_required(VERSION 3.0)

project(pfcrender)

if(WIN32)
  if(!CYGWIN)
    message(SEND_ERROR "This program uses linux only libs and won't run on windows. Compile on a linux system or use cygwin.")
endif(!CYGWIN)
endif(WIN32)
add_subdirectory(lib)
add_subdirectory(src)
