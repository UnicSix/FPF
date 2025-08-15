add_executable(test0
  main.cpp
)

target_include_directories( test0 PRIVATE "${CMAKE_SOURCE_DIR}" )

target_link_libraries(test0
  PRIVATE fpf
)
