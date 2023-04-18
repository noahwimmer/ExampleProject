cmake_minimum_required(VERSION 3.24)
project(c_demo)
set(CMAKE_COLOR_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

add_library(ex_lib SHARED src/main.c src/node.c src/linked_list.c)

add_executable(exampleTest test/tests.cpp)
add_executable(example src/main.c src/node.c src/linked_list.c)
target_link_libraries(exampleTest  ex_lib GTest::gtest_main ${GTEST_LIBRARIES})
include_directories(GoogleTest)
