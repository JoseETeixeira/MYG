project(Editor)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



if(LINUX)
    SET(GLFW_FLAGS "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lUltralight -lUltralightCore -lWebCore -lAppCore")
    add_definitions(${GLFW_FLAGS})
endif(LINUX)

if(WIN32)
    LINK_DIRECTORIES("../../libs/glfw/lib-vc2019")
endif(WIN32)

SET(EDITOR_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
# Main

file(GLOB BASE_HEADERS "*.hpp" "*.h")
file(GLOB GLAD_HEADERS "../../third_party/glfw/deps/*.h" )
file(GLOB GLAD_SOURCE "../../third_party/glfw/deps/*.c" )

file(GLOB SOURCE *.cpp ${BASE_HEADERS} ${EDITOR_FOLDER}/*.cpp )
SET(MAIN_CPP ${EDITOR_FOLDER}/editor.cpp)
SET(MAIN_HEADER ${EDITOR_FOLDER}/editor.hpp)

# ImGUI

find_library(imgui ../../third_party/imgui)

file(GLOB IMGUI_HEADER_FILES "../../third_party/imgui/*.h" )
file(GLOB IMGUI_SOURCE_FILES "../../third_party/imgui/*.cpp" )

# Ultralight

LINK_DIRECTORIES("../../libs/ultralight")


file(GLOB ULTRALIGHT_INCLUDES "../../third_party/ultralight/Ultralight/*.h","../../third_party/ultralight/AppCore/*.h","../../third_party/ultralight/JavaScriptCore/*.h" )

add_executable(Editor ${MAIN_CPP} ${SOURCE} ${GLAD_SOURCE} ${MAIN_HEADER} ${GLAD_HEADERS} ${IMGUI_HEADER_FILES} ${IMGUI_SOURCE_FILES} ${ULTRALIGHT_INCLUDES})


    
target_link_libraries(Editor glfw ${GLFW_LIBRARIES} UltralightCore AppCore Ultralight WebCore)