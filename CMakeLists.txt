cmake_minimum_required(VERSION 3.10)

project(splines)

file(GLOB_RECURSE SPLINES_SRC "./src/*.cc")

add_library(splines SHARED ${SPLINES_SRC})
add_subdirectory(test)

target_include_directories(splines PUBLIC "./include")