# Install script for directory: /home/eduardo/Desktop/BYOND/MYG/src/byond

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/eduardo/Desktop/BYOND/MYG/libs" TYPE SHARED_LIBRARY FILES "/home/eduardo/Desktop/BYOND/MYG/src/byond/libbyond-core.so.1.0.0")
  if(EXISTS "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so.1.0.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/eduardo/Desktop/BYOND/MYG/libs" TYPE SHARED_LIBRARY FILES "/home/eduardo/Desktop/BYOND/MYG/src/byond/libbyond-core.so")
  if(EXISTS "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/eduardo/Desktop/BYOND/MYG/libs/libbyond-core.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/eduardo/Desktop/BYOND/MYG/src/byond/library.h")
endif()

