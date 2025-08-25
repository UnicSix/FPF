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

add_executable(dijk dijkstra_test.cpp)
target_link_libraries(dijk PRIVATE fpf)
target_include_directories(dijk PRIVATE ${INCLUDE_DIRS})

add_test(NAME DijkstraTest COMMAND dijk)

set_tests_properties(DijkstraTest PROPERTIES
    TIMEOUT 1
    WILL_FAIL FALSE
    LABELS "Dijkstra Test"
)
