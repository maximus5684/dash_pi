cmake_minimum_required(VERSION 2.8.3)
project(dash_pi)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS
  system
  window
  graphics
  audio
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories (
  include
  ${SFML_INCLUDE_DIR}
)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/dash_pi_main.cpp
  src/audio_controller.cpp
  src/playback_controller.cpp
  src/control_bar.cpp
  src/nav_bar.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  AlsaPlusPlus
  ${SFML_LIBRARIES}
)
