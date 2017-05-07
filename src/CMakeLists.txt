#Gather Sources and include folders
SET ( SRCS "")
SET ( INCDIRS "")

file(GLOB_RECURSE INCFLS *.h)
file(GLOB_RECURSE SRCFLS *.cpp)

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