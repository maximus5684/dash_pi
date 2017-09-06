cmake_minimum_required(VERSION 2.8.3)
project(dash_pi)

add_definitions(-std=c++11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories (
  include
)

add_executable (
  ${PROJECT_NAME}
  src/main.cpp
)
