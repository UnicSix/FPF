cmake_minimum_required(VERSION 3.30)

set( CMAKE_C_COMPILER gcc )
set( CMAKE_CXX_COMPILER g++ )

project(fpf VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (NOT MSVC)
set(CMAKE_CXX_FLAGS "-std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
else()
set(CMAKE_CXX_FLAGS "/std:c++20 /EHsc")
set(CMAKE_CXX_FLAGS_DEBUG   "/W4 /Od /Zi /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "/O2 /MD /Zi")
endif()
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "clang")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-stack-pointer")
endif()
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

string(ASCII 27 Esc)
set(ColourReset "${Esc}[0m")
set(Blue        "${Esc}[34m")
set(Magenta     "${Esc}[35m")

find_package(absl)

file( GLOB_RECURSE PROJECT_SRC
  fpf/*.hpp
)
message( STATUS "${Magenta}src: ${PROJECT_SRC}${ColourReset}")

add_library(${PROJECT_NAME} INTERFACE)

# Add include directory
message(${PROJECT_SOURCE_DIR})
list(APPEND INCLUDE_DIRS
  "${CMAKE_CURRENT_SOURCE_DIR}/fpf/"
  "${CMAKE_CURRENT_SOURCE_DIR}/third-party/BitMagic/src"
)
message(STATUS "INCLUDE dirs: ${INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME}
  INTERFACE ${INCLUDE_DIRS}
)

add_subdirectory(third-party/BitMagic)
target_link_libraries(${PROJECT_NAME}
  INTERFACE bm
  INTERFACE absl::flat_hash_map
)

enable_testing()
add_subdirectory(examples)
add_subdirectory(tests)

message(STATUS "BINARY DIR: ${CMAKE_BINARY_DIR}")
