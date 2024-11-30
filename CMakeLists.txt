cmake_minimum_required(VERSION 3.27)

project(solfege_c LANGUAGES C)

set(CMAKE_C_STANDARD 99)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

set(COMMON_FLAGS "-flto -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

message("CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")

add_executable(solfege
  src/main.c
  src/notes.c
  src/interval.c
  src/chromatic.c
  src/white_note.c
)
target_include_directories(solfege PRIVATE include)
