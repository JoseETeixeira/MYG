project(Editor)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(LINUX)
    SET(GLFW_FLAGS "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl")
    add_definitions(${GLFW_FLAGS})
endif(LINUX)

SET(EDITOR_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
# Main

file(GLOB BASE_HEADERS "*.hpp" "*.h")
file(GLOB GLAD_HEADERS "../../third_party/glfw/deps/*.h" )
file(GLOB GLAD_SOURCE "../../third_party/glfw/deps/*.c" )

file(GLOB SOURCE *.cpp ${BASE_HEADERS} ${EDITOR_FOLDER}/*.cpp )
SET(MAIN_CPP ${EDITOR_FOLDER}/editor.cpp)
SET(MAIN_HEADER ${EDITOR_FOLDER}/editor.hpp)



add_executable(Editor ${MAIN_CPP} ${SOURCE} ${GLAD_SOURCE} ${MAIN_HEADER} ${GLAD_HEADERS})
target_link_libraries(Editor glfw ${GLFW_LIBRARIES})