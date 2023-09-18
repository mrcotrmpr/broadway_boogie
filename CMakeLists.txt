cmake_minimum_required (VERSION 3.8)

project ("broadway_boogie")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})	

target_include_directories(broadway_boogie PUBLIC include)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
