cmake_minimum_required (VERSION 3.8)

project ("broadway_boogie")

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS FALSE) 

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})	

target_include_directories(broadway_boogie PUBLIC include)

include(FetchContent)
FetchContent_Declare(
    cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 2553fc41450301cd09a9271c8d2c3e0cf3546b73
)
FetchContent_MakeAvailable(cpr)

target_link_libraries(broadway_boogie PRIVATE cpr::cpr SDL2::SDL2)
