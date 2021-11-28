project(Editor)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



if(LINUX)
    SET(GLFW_FLAGS "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -zlib -libpng16 -lwebp -lwebpmux -lwebpdemux")
    add_definitions(${GLFW_FLAGS})
endif(LINUX)

if(WIN32)
    LINK_DIRECTORIES("../../libs/glfw/lib-vc2019")
endif(WIN32)

SET(EDITOR_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
# Main

file(GLOB BASE_HEADERS "*.hpp" "*.h" "source_navigation/*.h" "map_editor/*.h" "code_editor/*.h" "DMI/DMI.h" )
file(GLOB GLAD_HEADERS "../../third_party/glfw/deps/*.h" )
file(GLOB GLAD_SOURCE "../../third_party/glfw/deps/*.c" )

file(GLOB SOURCE *.cpp ${BASE_HEADERS} ${EDITOR_FOLDER}/*.cpp ${EDITOR_FOLDER}/source_navigation/*.cpp  ${EDITOR_FOLDER}/map_editor/*.cpp ${EDITOR_FOLDER}/code_editor/*.cpp ${EDITOR_FOLDER}/DMI/*.cpp)
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

if (WIN32)
    ##ZLIB
    include_directories(deps/zlib-1.2.11)
    include_directories(deps/zlib-1.2.11/Release)
    set(ZLIB_INCLUDE_DIR deps/zlib-1.2.11)
    set(ZLIB_LIBRARY zlib)
    add_subdirectory(deps/zlib-1.2.11)
    find_package(ZLIB REQUIRED)

    link_directories (${ZLIB_LIBRARY_DIRS})
    link_libraries (${ZLIB_LIBRARIES})


    ##LIBPNG
    include_directories(deps/libpng)
    set(PNG_PNG_INCLUDE_DIR deps/libpng)
    set(PNG_LIBRARY deps/libpng/Release/png)
    add_subdirectory(deps/libpng)

    find_package(PNG REQUIRED)

    include_directories (${PNG_INCLUDE_DIRS})
    link_directories (${PNG_LIBRARY_DIRS})
    link_libraries (${PNG_LIBRARIES})

    ##WEBP
    include_directories(deps/libwebp/include)

    find_library(libwebp "deps/libwebp")

    include_directories (${LIBWEBP_INCLUDE_DIR})
    link_directories (${LIBWEBP_LIBRARY_DIRS})
    link_libraries (${LIBWEBP_LIBRARIES})

    ##BOOST
    SET("Boost_DIR" "C:/boost")
    find_package(Boost REQUIRED)


    add_executable(Editor ${MAIN_CPP} DMI/codecs/png.cpp DMI/codecs/webp.cpp DMI/codecs/file.cpp  ${SOURCE} ${GLAD_SOURCE} ${FA_HEADER_FILES} ${MAIN_HEADER} ${GLAD_HEADERS} ${IMGUI_HEADER_FILES} ${IMGUI_SOURCE_FILES} ${BYOND_HEADER_FILES} ${BYOND_SOURCE_FILES} ${LIBPNG_LINK_FLAGS})

    include_directories(Editor ${ZLIB_DEPS} ${Boost_INCLUDE_DIRS}  "../../../third_party/gil/include" "../../../third_party/io/include" )
        
    target_link_libraries(Editor glfw ${GLFW_LIBRARIES}  ${PNG_LIBRARIES} ${LIBWEBP_LIBRARIES} deps/libwebp/libwebp deps/libwebp/libwebpmux deps/libwebp/libwebpdemux  zlib png)
else(LINUX)
    ##ZLIB
    find_package(ZLIB REQUIRED)

    link_directories (${ZLIB_LIBRARY_DIRS})
    link_libraries (${ZLIB_LIBRARIES})


    ##LIBPNG
    find_package(PNG REQUIRED)

    include_directories (${PNG_INCLUDE_DIRS})
    link_directories (${PNG_LIBRARY_DIRS})
    link_libraries (${PNG_LIBRARIES})

    ##WEBP
    include_directories(deps/libwebp/include)

    find_library(libwebp "deps/libwebp")

    include_directories (${LIBWEBP_INCLUDE_DIR})
    link_directories (${LIBWEBP_LIBRARY_DIRS})
    link_libraries (${LIBWEBP_LIBRARIES})

    ##BOOST
    SET("Boost_DIR" "/usr/share/Boost")
    find_package(Boost REQUIRED)


    add_executable(Editor ${MAIN_CPP} DMI/codecs/png.cpp DMI/codecs/webp.cpp DMI/codecs/file.cpp  ${SOURCE} ${GLAD_SOURCE} ${FA_HEADER_FILES} ${MAIN_HEADER} ${GLAD_HEADERS} ${IMGUI_HEADER_FILES} ${IMGUI_SOURCE_FILES} ${BYOND_HEADER_FILES} ${BYOND_SOURCE_FILES} ${LIBPNG_LINK_FLAGS})

    include_directories(Editor ${ZLIB_DEPS} ${Boost_INCLUDE_DIRS}  "../../../third_party/gil/include" "../../../third_party/io/include")
        
    target_link_libraries(Editor glfw ${GLFW_LIBRARIES}  ${PNG_LIBRARIES} ${LIBWEBP_LIBRARIES} ${Boost_LIBRARIES}  webp webpmux webpdemux)
endif()
