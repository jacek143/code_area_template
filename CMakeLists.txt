cmake_minimum_required(VERSION 3.9.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(./googletest)

file(GLOB SRC_FILES sources/*/*.cpp)
file(GLOB INC_FILES sources/*/*.h)

add_executable(unit_tests ${SRC_FILES})
target_compile_options(unit_tests PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(unit_tests PUBLIC 
    ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
target_link_libraries(unit_tests gtest_main)

add_custom_target(check_formatting COMMAND ./check_formatting.sh ${SRC_FILES} ${INC_FILES} WORKING_DIRECTORY ..)
add_custom_target(check_statically COMMAND ./check_statically.sh ${SRC_FILES} WORKING_DIRECTORY ..)
add_custom_target(check_unit_tests COMMAND ./unit_tests DEPENDS unit_tests)
add_custom_target(check_everything DEPENDS check_formatting check_statically check_unit_tests)
