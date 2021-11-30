get_filename_component(byond_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(byond_INCLUDE_DIRS "@CONF_INCLUDE_DIRS@")

# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET foo AND NOT byond_BINARY_DIR)
  include("${byond_CMAKE_DIR}/byondTargets.cmake")
endif()

# These are IMPORTED targets created by FooBarTargets.cmake
set(byond_LIBRARIES byond)
set(byond_EXECUTABLE byond)
