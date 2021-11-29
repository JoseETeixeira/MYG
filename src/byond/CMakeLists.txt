cmake_minimum_required(VERSION 3.9)
project(byond-core VERSION 1.0.0 DESCRIPTION "BYOND DME Core")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(byond-core SHARED
    library.cpp
    
)

if(NOT TARGET spdlog)
    # Stand-alone build
    SET(spdlog_DIR "../../third_party/spdlog")
    include_directories("../../third_party/spdlog/include" "../../third_party/spdlog/src")
endif()



set_target_properties(byond-core PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(byond-core PROPERTIES PUBLIC_HEADER library.h)

target_include_directories(byond-core PRIVATE .)
target_include_directories(byond-core PRIVATE "../../third_party/color/src" "../byond" "../../third_party/json" "../../third_party/gil/include" "../../third_party/io/include")


install(TARGETS byond-core 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})