cmake_minimum_required (VERSION 3.8)

project ("broadway_boogie")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})	

target_include_directories(broadway_boogie PUBLIC include)

set(CURL_INCLUDE_DIR C:/cmake_prefix_path/curl-8.3.0_2-win64-mingw/include)
set(CURL_LIBRARY C:/cmake_prefix_path/curl-8.3.0_2-win64-mingw/lib/libcurl_a_debug.lib)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
