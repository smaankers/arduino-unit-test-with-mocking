cmake_minimum_required (VERSION 2.8.11)
project (arduino-unit-test-with-mocking)

set(CMAKE_BUILD_TYPE "Debug")

IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_subdirectory(test)
