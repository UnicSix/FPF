# Sample test
add_executable(mytest mytest.cpp)
target_link_libraries(mytest PRIVATE fpf)
target_include_directories(mytest PRIVATE ${CMAKE_SOURCE_DIR}/fpf)

add_test(NAME SimpleTest COMMAND mytest)

set_tests_properties(SimpleTest PROPERTIES
    TIMEOUT 1
    WILL_FAIL FALSE
    LABELS "SampleTest"
)
