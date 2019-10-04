cmake_minimum_required(VERSION 3.9.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(./googletest)

file(GLOB SRC_FILES sources/*/*.cpp)
add_executable(kata ${SRC_FILES})
target_include_directories(kata PUBLIC 
    ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
target_link_libraries(kata gtest_main)

# RUN UNIT TESTS
add_custom_target(unit_tests ALL COMMAND ./kata)
add_dependencies(unit_tests kata)

# LINT
add_custom_target(lint COMMAND ./lint.sh ${SRC_FILES} WORKING_DIRECTORY ..)
