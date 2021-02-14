file(GLOB_RECURSE SPLINES_TEST_SRC "*.cc")

add_executable(splines_test ${SPLINES_TEST_SRC})

target_link_libraries(splines_test PRIVATE splines)