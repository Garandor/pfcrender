#Gather Sources and include folders
SET ( SRCS "")
SET ( INCDIRS "")

#CMSIS
file(GLOB_RECURSE INCFLS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SRCFLS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

SET( SRCS
  ${SRCFLS}
)

#add all includes
foreach (_headerFile ${INCFLS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCDIRS ${_dir})
endforeach()

include_directories(
	${INCDIRS}
)

#Build executable
add_executable(${TARGET} ${SRCS})