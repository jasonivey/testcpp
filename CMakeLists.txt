cmake_minimum_required (VERSION 2.6)
project (TEST_APP)
add_executable(test_app main.cpp)

find_package(Boost REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O0 -g -ggdb3 -DDEBUG")

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

target_link_libraries(test_app ${Boost_LIBRARIES})
