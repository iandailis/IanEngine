#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "IanEngine" for configuration ""
set_property(TARGET IanEngine APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(IanEngine PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libIanEngine.dll.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libIanEngine.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IanEngine )
list(APPEND _IMPORT_CHECK_FILES_FOR_IanEngine "${_IMPORT_PREFIX}/lib/libIanEngine.dll.a" "${_IMPORT_PREFIX}/bin/libIanEngine.dll" )

# Import target "glfw" for configuration ""
set_property(TARGET glfw APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(glfw PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libglfw3.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS glfw )
list(APPEND _IMPORT_CHECK_FILES_FOR_glfw "${_IMPORT_PREFIX}/lib/libglfw3.a" )

# Import target "tinyobjloader" for configuration ""
set_property(TARGET tinyobjloader APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tinyobjloader PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtinyobjloader.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS tinyobjloader )
list(APPEND _IMPORT_CHECK_FILES_FOR_tinyobjloader "${_IMPORT_PREFIX}/lib/libtinyobjloader.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
