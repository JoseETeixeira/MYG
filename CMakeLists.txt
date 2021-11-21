cmake_minimum_required(VERSION 3.5)

project(MYG)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++2a")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_LIBDIR ${CMAKE_BINARY_DIR}/libs )
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)

add_subdirectory(third_party/glfw)
add_subdirectory(third_party/imgui)
#add_subdirectory(third_party/opencv)
#add_subdirectory(third_party/ultralight)
include_directories(third_party/spdlog/include)
include_directories(third_party/glfw/include)
include_directories(third_party/glfw/deps/glad)
include_directories(third_party/imgui)
#include_directories(third_party/opencv)


add_subdirectory(src/byond)

add_subdirectory(src/editor)

add_custom_target(clean-all
   COMMAND ${CMAKE_BUILD_TOOL} clean
   COMMAND ${CMAKE_COMMAND} -P clean.cmake
)

