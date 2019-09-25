cmake_minimum_required(VERSION 3.9.2)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
add_executable(solution solution.cpp)
target_link_libraries(solution gtest gtest_main)

# RUN UNIT TESTS
add_custom_target(run_solution ALL COMMAND ./solution)
add_dependencies(run_solution solution)
