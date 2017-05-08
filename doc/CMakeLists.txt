find_package(Doxygen)

if(DOXYGEN_FOUND)
	#Doc buildtarget
	set(doxyfile_in Doxyfile.in)
	set(doxyfile Doxyfile)
	set(doxymainpage ${CMAKE_SOURCE_DIR}/README.md)
	configure_file(${doxyfile_in} ${doxyfile} @ONLY)
	
	add_custom_target(doc
	COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generate docs and xml for Astah reversing"
	VERBATIM)
	
endif()