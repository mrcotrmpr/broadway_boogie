cmake_minimum_required (VERSION 3.8)

project(broadway_boogie_tests)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt on)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCE_FILES CONFIGURE_DEPENDS ./*/*_tests.cpp)
add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    GTest::gmock
    GTest::gtest_main
    broadway_boogie_lib
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
