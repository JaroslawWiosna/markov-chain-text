cmake_minimum_required (VERSION 2.6)

option(SANITIZER "Address Sanitizer" OFF)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_LONG_RUNNING_TESTS "Build tests" OFF)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

set(COMPILE_FLAGS "-std=c++1z -Wall -O2")
set(GTEST_FLAGS "-lgtest")
set(LINK_FLAGS "-lpthread")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(COMPILE_FLAGS  "${COMPILE_FLAGS} -stdlib=libstdc++")
endif()

if(BUILD_TESTS)
  set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

add_subdirectory(src)

if(BUILD_TESTS)

endif()
