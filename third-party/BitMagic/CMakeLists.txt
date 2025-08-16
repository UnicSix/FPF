cmake_minimum_required(VERSION 3.12)

project("bm" VERSION 7.4.0
             DESCRIPTION "BitMagic Library"
             HOMEPAGE_URL "https://github.com/tlk00/BitMagic")

set( CMAKE_VERBOSE_MAKEFILE on )

# SET(BMOPTFLAGS "BMSSE42OPT" CACHE STRING "User-specified optimization flag")

find_package(Threads REQUIRED)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}/src")
message(STATUS "Project source: ${PROJECT_SOURCE_DIR}")

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src >
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set(BM_HEADERS ${PROJECT_SOURCE_DIR}/src/bm.h 
               ${PROJECT_SOURCE_DIR}/src/bmblocks.h
               ${PROJECT_SOURCE_DIR}/src/bm3vl.h
               ${PROJECT_SOURCE_DIR}/src/bmaggregator.h
               ${PROJECT_SOURCE_DIR}/src/bmalgo.h
               ${PROJECT_SOURCE_DIR}/src/bmbvimport.h
               ${PROJECT_SOURCE_DIR}/src/bmalgo_impl.h
               ${PROJECT_SOURCE_DIR}/src/bmalgo_similarity.h
               ${PROJECT_SOURCE_DIR}/src/bmalloc.h
               ${PROJECT_SOURCE_DIR}/src/bmbmatrix.h
               ${PROJECT_SOURCE_DIR}/src/bmbuffer.h
               ${PROJECT_SOURCE_DIR}/src/bmconst.h
               ${PROJECT_SOURCE_DIR}/src/bmdbg.h
               ${PROJECT_SOURCE_DIR}/src/bmdef.h
               ${PROJECT_SOURCE_DIR}/src/bmfunc.h
               ${PROJECT_SOURCE_DIR}/src/bmfwd.h
               ${PROJECT_SOURCE_DIR}/src/bmgamma.h
               ${PROJECT_SOURCE_DIR}/src/bmintervals.h
               ${PROJECT_SOURCE_DIR}/src/bmrandom.h
               ${PROJECT_SOURCE_DIR}/src/bmrs.h
               ${PROJECT_SOURCE_DIR}/src/bmserial.h
               ${PROJECT_SOURCE_DIR}/src/bmsimd.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec_algo.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec_compr.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec_parallel.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec_serial.h
               ${PROJECT_SOURCE_DIR}/src/bmsparsevec_util.h
               ${PROJECT_SOURCE_DIR}/src/bmstrsparsevec.h
               ${PROJECT_SOURCE_DIR}/src/bmtask.h
               ${PROJECT_SOURCE_DIR}/src/bmthreadpool.h
               ${PROJECT_SOURCE_DIR}/src/bmtimer.h
               ${PROJECT_SOURCE_DIR}/src/bmtrans.h
               ${PROJECT_SOURCE_DIR}/src/bmundef.h
               ${PROJECT_SOURCE_DIR}/src/bmutil.h
               ${PROJECT_SOURCE_DIR}/src/bmxor.h
               ${PROJECT_SOURCE_DIR}/src/encoding.h
               ${PROJECT_SOURCE_DIR}/src/bmsse2.h
               ${PROJECT_SOURCE_DIR}/src/bmsse4.h
               ${PROJECT_SOURCE_DIR}/src/bmsse_util.h
               ${PROJECT_SOURCE_DIR}/src/bmavx2.h
               ${PROJECT_SOURCE_DIR}/src/bmavx512.h
               ${PROJECT_SOURCE_DIR}/src/bmbmi1.h
               ${PROJECT_SOURCE_DIR}/src/bmbmi2.h
)


set (CMAKE_CXX_STANDARD 17)


if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(warnopt "-Wno-psabi")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if ("${BMOPTFLAGS}" STREQUAL "BMSSE42OPT")
	    set(bmoptf "-march=nehalem -O2 -msse4.2 -DBMSSE42OPT")
    elseif("${BMOPTFLAGS}" STREQUAL "BMAVX2OPT")
        set(bmoptf "-march=skylake -mavx2 -O2 -DBMAVX2OPT")
    else()
	if (CMAKE_BUILD_TYPE MATCHES "Release")
		set(bmoptf "-march=native -O2")
	else()
		set(bmoptf "-march=native")
	endif()
    endif()

    set(flags "-Wall -Wextra -Wno-ignored-qualifiers -fPIC -fomit-frame-pointer")
    set(optflags -g0 -O2)
    set(bmptflags -pthread)
    SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,-lpthread")
    

elseif (CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    set(flags, "-tpp7 -march=core2 -restrict -DBM_HASRESTRICT -fno-fnalias -Wall")
    set(optflags, "-g0 -O2 -opt_report_fileopt.txt -opt_report_levelmax")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    if ("${BMOPTFLAGS}" STREQUAL "BMSSE42OPT")
	set(bmoptf "-DBMSSE42OPT")
    elseif("${BMOPTFLAGS}" STREQUAL "BMAVX2OPT")
        set(bmoptf "-DBMAVX2OPT") 
    endif()

    set(flags "/W4 /EHsc /F 5000000 ")
    set(optflags "-O2")
    SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ")
endif()

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${flags} ${bmoptf} ${bmptflags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags} ${bmoptf} ${bmptflags} ${warnopt}")
