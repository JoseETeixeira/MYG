cmake_minimum_required(VERSION 3.9)
project(byond VERSION 1.0.0 DESCRIPTION "BYOND DME Core")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(byond SHARED
    library.cpp
    DMI/codecs/png.cpp 
    DMI/codecs/webp.cpp
    DMI/codecs/file.cpp
    DMI/errors.cpp
    DMI/DMI.cpp
    
)

if(LINUX)
    SET(GLFW_FLAGS "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -zlib -libpng16 -lwebp -lwebpmux -lwebpdemux")
    add_definitions(${GLFW_FLAGS})
endif(LINUX)

if(WIN32)
    LINK_DIRECTORIES("../../libs/glfw/lib-vc2019")
endif(WIN32)


if(NOT TARGET spdlog)
    # Stand-alone build
    SET(spdlog_DIR "../../third_party/spdlog")
    include_directories("../../third_party/spdlog/include" "../../third_party/spdlog/src")
endif()

if (WIN32)
    ##ZLIB
    include_directories(deps/zlib-1.2.11)
    include_directories(deps/zlib-1.2.11/Release)
    set(ZLIB_INCLUDE_DIR deps/zlib-1.2.11)
    set(ZLIB_LIBRARY zlib)
    
    find_package(ZLIB REQUIRED)

    link_directories (${ZLIB_LIBRARY_DIRS})
    link_libraries (${ZLIB_LIBRARIES})


    ##LIBPNG
    include_directories(deps/libpng)
    set(PNG_PNG_INCLUDE_DIR deps/libpng)
    set(PNG_LIBRARY deps/libpng/Release/png)
   

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
    include_directories (${BOOST_INCLUDE_DIRS})
    
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

    #BOOST

    SET("Boost_DIR" "/usr/share/Boost")
    find_package(Boost REQUIRED)
    include_directories (${BOOST_INCLUDE_DIRS})
endif()


set_target_properties(byond PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(byond PROPERTIES PUBLIC_HEADER library.h)

target_include_directories(byond PRIVATE .)
target_include_directories(byond PRIVATE "../../third_party/color/src" "../../third_party/json" ${ZLIB_INCLUDE_DIR} ${PNG_INCLUDE_DIRS}   "../../third_party/gil/include" "../../third_party/io/include")
include_directories(byond  ${ZLIB_DEPS}  ${PNG_DEPS} ${Boost_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIR}  "../../third_party/gil/include" "../../third_party/io/include" "deps/libpng" "deps/libwebp" "deps/zlib-1.2.11" "DMI" "dme".)
target_link_libraries(byond glfw ${GLFW_LIBRARIES}  ${Boost_LIBRARIES} ${PNG_LIBRARIES} ${LIBWEBP_LIBRARIES} deps/libwebp/libwebp deps/libwebp/libwebpmux deps/libwebp/libwebpdemux  zlib png)


install(TARGETS byond
    EXPORT byondTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})