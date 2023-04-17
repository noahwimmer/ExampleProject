cmake_minimum_required(VERSION 3.10)
project(c_demo)

include_directories(include)

add_executable(demo src/main.c src/node.c src/linked_list.c)