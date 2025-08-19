# Sample test
add_executable(mytest mytest.cpp)
target_link_libraries(mytest PRIVATE fpf)
target_include_directories(mytest PRIVATE ${INCLUDE_DIRS})

add_test(NAME SimpleTest COMMAND mytest)

set_tests_properties(SimpleTest PROPERTIES
    TIMEOUT 1
    WILL_FAIL FALSE
    LABELS "SampleTest"
)


add_executable(graph_gen_test graph_gen_test.cpp)
target_link_libraries(graph_gen_test PRIVATE fpf)
target_include_directories(graph_gen_test PRIVATE ${INCLUDE_DIRS})

add_test(NAME GraphGenTest COMMAND graph_gen_test)

set_tests_properties(GraphGenTest PROPERTIES
    TIMEOUT 5
    WILL_FAIL FALSE
    LABELS "GraphGen"
)

add_executable(gen_test gen_test.cpp)
target_link_libraries(gen_test PRIVATE fpf)
target_include_directories(gen_test PRIVATE ${INCLUDE_DIRS})

add_test(NAME GenTest COMMAND gen_test)

set_tests_properties(GenTest PROPERTIES
    TIMEOUT 5
    WILL_FAIL FALSE
    LABELS "GenTest"
)
