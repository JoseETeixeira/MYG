cmake_minimum_required(VERSION 3.5)

project(MYG)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++2a")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)

add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)
include_directories(third_party/glfw/deps/glad)

add_subdirectory(src/editor)
