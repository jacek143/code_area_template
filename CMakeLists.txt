cmake_minimum_required(VERSION 3.9.2)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./googletest)

file(GLOB SRC_FILES sources/*/*.cpp)
add_executable(kata ${SRC_FILES})
target_include_directories(kata PUBLIC 
    ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
target_link_libraries(kata gtest_main)


# RUN UNIT TESTS
add_custom_target(run_kata ALL COMMAND ./kata)
add_dependencies(run_kata kata)
