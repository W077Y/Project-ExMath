cmake_minimum_required(VERSION 3.19)

#set(CMAKE_VERBOSE_MAKEFILE on )

project("Project-ExMath"
 VERSION 0.0.0.0
 DESCRIPTION ""
 HOMEPAGE_URL ""
 LANGUAGES C CXX ASM
)

set(PROJECT_THIRD_PARTY_DIR
    "${CMAKE_CURRENT_LIST_DIR}/third_party"
)

set(
  FETCHCONTENT_BASE_DIR
  "${PROJECT_THIRD_PARTY_DIR}/_deps"
  CACHE PATH "Project-local dependency cache"
)

include(FetchContent)

message(STATUS "#         FETCHING catch2")

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.15.3
  GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(Catch2)

message(STATUS "########################")
message(STATUS "#          PROJECT NAME: ${CMAKE_PROJECT_NAME}")
message(STATUS "#   PROJECT DESCRIPTION: ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "#           PROJECT URL: ${CMAKE_PROJECT_HOMEPAGE_URL}")
message(STATUS "#       PROJECT VERSION: ${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}.${CMAKE_PROJECT_VERSION_TWEAK}")
message(STATUS "#         FETCH CONTENT: ${FETCHCONTENT_BASE_DIR}")
message(STATUS "#     CMAKE MODULE PATH: ${CMAKE_MODULE_PATH}")
message(STATUS "########################")

if(MSVC)
     add_compile_options(
       /W4
       /std:c++latest
       /Zi
     )
else()
     add_compile_options(
         "$<$<COMPILE_LANGUAGE:CXX>:-std=c++23>"
         "$<$<COMPILE_LANGUAGE:CXX>:-Wall>"
         "$<$<COMPILE_LANGUAGE:CXX>:-Wextra>"
         "$<$<COMPILE_LANGUAGE:CXX>:-Wpedantic>"
         "$<$<COMPILE_LANGUAGE:CXX>:-Werror>"
     )
endif()

enable_testing()

add_subdirectory( "${CMAKE_CURRENT_LIST_DIR}/exmath-lib" )
add_subdirectory( "${CMAKE_CURRENT_LIST_DIR}/tests" )
add_subdirectory( "${CMAKE_CURRENT_LIST_DIR}/experimental" )
