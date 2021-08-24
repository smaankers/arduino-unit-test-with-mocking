set(testsuite_name arduino-unit-test-with-mocking_gtest)



set(
  SOURCE_FILES
    src/test_string_utils.cpp
    src/main.cpp)

set(
  INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../${CMAKE_PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../target/dependencies/googletest/target/export/include
)

set(
  LINK_LIBS
    ${CMAKE_CURRENT_SOURCE_DIR}/../target/dependencies/googletest/target/export/lib/libgtestd.a
    ${CMAKE_CURRENT_SOURCE_DIR}/../target/dependencies/googletest/target/export/lib/libgmockd.a
    pthread
)


add_executable             (${testsuite_name} ${SOURCE_FILES})
target_include_directories (${testsuite_name} PUBLIC ${INCLUDE_DIRS})
target_link_libraries      (${testsuite_name} PUBLIC ${LINK_LIBS})
target_compile_definitions (${testsuite_name} PUBLIC -DPLATFORM_X86)
