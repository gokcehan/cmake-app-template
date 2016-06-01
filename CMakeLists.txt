cmake_minimum_required(VERSION 2.6)

project(app)
set(BIN ${PROJECT_NAME})
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

add_compile_options("-std=c++11")
add_compile_options("-Wall")
add_compile_options("-Wextra")

file(GLOB_RECURSE SRCS src/*)

option(BOOST_TESTS
  "Enables/Disables Boost unit test framework" OFF)

if(BOOST_TESTS)
  enable_testing()

  set(LIB ${PROJECT_NAME}_test)
  set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

  list(REMOVE_ITEM SRCS ${PROJECT_SOURCE_DIR}/src/main.cc)
  add_library(${LIB} STATIC ${SRCS})
  add_executable(${BIN} ${PROJECT_SOURCE_DIR}/src/main.cc)
  target_link_libraries(${BIN} ${LIB})

  find_package(Boost COMPONENTS unit_test_framework REQUIRED)
  include_directories(src test ${Boost_INCLUDE_DIRS})
  add_definitions(-DBOOST_TEST_DYN_LINK)

  file(GLOB_RECURSE TESTS test/*)
  foreach(TEST ${TESTS})
    get_filename_component(TEST_NAME ${TEST} NAME_WE)
    add_executable(${TEST_NAME}_test ${TEST})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME}_test)
    target_link_libraries(${TEST_NAME}_test
                          ${LIB}
                          ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
  endforeach()
else()
  add_executable(${BIN} ${SRCS})
endif(BOOST_TESTS)

install(TARGETS ${BIN} DESTINATION bin)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE}
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
else(DOXYGEN_FOUND)
  message(STATUS "Doxygen not found - Documentation will not be generated")
endif(DOXYGEN_FOUND)
