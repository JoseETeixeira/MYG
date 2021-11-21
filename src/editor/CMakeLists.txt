project(Editor)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



if(LINUX)
    SET(GLFW_FLAGS "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl")
    add_definitions(${GLFW_FLAGS})
endif(LINUX)

if(WIN32)
    LINK_DIRECTORIES("../../libs/glfw/lib-vc2019")
endif(WIN32)

SET(EDITOR_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
# Main

file(GLOB BASE_HEADERS "*.hpp" "*.h" "source_navigation/*.h" "map_editor/*.h" "code_editor/*.h")
file(GLOB GLAD_HEADERS "../../third_party/glfw/deps/*.h" )
file(GLOB GLAD_SOURCE "../../third_party/glfw/deps/*.c" )

file(GLOB SOURCE *.cpp ${BASE_HEADERS} ${EDITOR_FOLDER}/*.cpp ${EDITOR_FOLDER}/source_navigation/*.cpp  ${EDITOR_FOLDER}/map_editor/*.cpp ${EDITOR_FOLDER}/code_editor/*.cpp)
SET(MAIN_CPP ${EDITOR_FOLDER}/editor.cpp)
SET(MAIN_HEADER ${EDITOR_FOLDER}/editor.hpp)

# ImGUI

find_library(imgui ../../third_party/imgui)

file(GLOB IMGUI_HEADER_FILES "../../third_party/imgui/*.h" )
file(GLOB IMGUI_SOURCE_FILES "../../third_party/imgui/*.cpp" )

# Font Awesome

file(GLOB FA_HEADER_FILES "../../third_party/fonts/*.h" )

## BYOND

find_library(byond-core byond)

file(GLOB BYOND_HEADER_FILES "byond/*.h" "byond/utils/*.h" "byond/parser/*.h" "byond/tree/*.h" )
file(GLOB BYOND_SOURCE_FILES "byond/*.cpp" )

##OpenCV
set(OpenCV_DIR "../../third_party/opencvlib")
include_directories( ${OpenCV_DIR} )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable(Editor ${MAIN_CPP} ${SOURCE} ${GLAD_SOURCE} ${FA_HEADER_FILES} ${MAIN_HEADER} ${GLAD_HEADERS} ${IMGUI_HEADER_FILES} ${IMGUI_SOURCE_FILES} )


    
target_link_libraries(Editor glfw ${GLFW_LIBRARIES} byond-core ${OpenCV_LIBS} )