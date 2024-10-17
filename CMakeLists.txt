cmake_minimum_required(VERSION 2.8.6)

#sample/
#${CMAKE_SOURCE_DIR}
#sample/build
#${CMAKE_BINARY_DIR}
#sample/project
#${PROJECT_SOURCE_DIR}

project(src CXX)

#compiler option with accordance to compiler
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET (CMAKE_CXX_FLAGS "-std=c++20 ${CMAKE_CXX_FLAGS}")
	SET (CMAKE_CXX_FLAGS "-g3 ${CMAKE_CXX_FLAGS}")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET (CMAKE_CXX_FLAGS "-std=c++20 ${CMAKE_CXX_FLAGS}")
	SET (CMAKE_CXX_FLAGS "-g3 ${CMAKE_CXX_FLAGS}")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19)
		MESSAGE ( FATAL_ERROR "MSVC doesn't support C++11.")
	ENDIF ()
ENDIF ()

#GTEST and GMOCK build
SET(BUILD_GTEST ON CACHE BOOL "Use some expat option")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodule/googletest)

# include directory
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/submodule
	${CMAKE_CURRENT_SOURCE_DIR}/submodule/googletest/googlemock/include
	${CMAKE_CURRENT_SOURCE_DIR}/submodule/googletest/googletest/include
)

#inclue sources
include(cmake/chap2.cmake)
include(cmake/chap2_test.cmake)
include(cmake/chap3.cmake)
include(cmake/chap3_test.cmake)
include(cmake/chap4.cmake)
include(cmake/chap4_test.cmake)
include(cmake/algorithm.cmake)
include(cmake/algorithm_test.cmake)
include(cmake/cp/chap01.cmake)
include(cmake/cp/chap01_test.cmake)

#add library
add_library(chap2 ${chap2_SOURCES})
add_library(chap3 ${chap3_SOURCES})
add_library(chap4 ${chap4_SOURCES})
add_library(algorithm ${algorithm_SOURCES})
add_library(cp_chap01 ${cp_chap01_SOURCES})

#
# test
#
enable_testing()

add_executable(chap2_test ${chap2_test_SOURCES})
target_link_libraries(chap2_test chap2)
target_link_libraries(chap2_test gmock)
target_link_libraries(chap2_test gtest)
add_test(chap2_test chap2_test)

add_executable(chap3_test ${chap3_test_SOURCES})
target_link_libraries(chap3_test chap3)
target_link_libraries(chap3_test gmock)
target_link_libraries(chap3_test gtest)
add_test(chap3_test chap3_test)

add_executable(chap4_test ${chap4_test_SOURCES})
target_link_libraries(chap4_test chap4)
target_link_libraries(chap4_test gmock)
target_link_libraries(chap4_test gtest)
add_test(chap4_test chap4_test)

add_executable(algorithm_test ${algorithm_test_SOURCES})
target_link_libraries(algorithm_test algorithm)
target_link_libraries(algorithm_test gmock)
target_link_libraries(algorithm_test gtest)
add_test(algorithm_test algorithm_test)

add_executable(cp_chap01_test ${cp_chap01_test_SOURCES})
target_link_libraries(cp_chap01_test cp_chap01)
target_link_libraries(cp_chap01_test gmock)
target_link_libraries(cp_chap01_test gtest)
add_test(cp_chap01_test cp_chap01_test)
