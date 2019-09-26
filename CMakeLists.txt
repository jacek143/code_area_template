cmake_minimum_required(VERSION 3.9.2)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB SRC_FILES sources/*.cpp)
add_executable(kata ${SRC_FILES})
target_link_libraries(kata gtest gtest_main)

# RUN UNIT TESTS
add_custom_target(run_kata ALL COMMAND ./kata)
add_dependencies(run_kata kata)
