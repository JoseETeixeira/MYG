cmake_minimum_required(VERSION 3.9)
project(byond-core VERSION 1.0.0 DESCRIPTION "BYOND DME Core")

add_library(byond-core SHARED
    library.cpp
    
)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()


set_target_properties(byond-core PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(byond-core PROPERTIES PUBLIC_HEADER library.h)

target_include_directories(byond-core PRIVATE .)

target_link_libraries(byond-core PRIVATE spdlog::spdlog)

install(TARGETS byond-core 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})