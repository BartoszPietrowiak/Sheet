cmake_minimum_required(VERSION 3.12)
project(MyProject VERSION 1.0.0)

set(SFML_DIR src/SFML/install/lib/cmake/SFML/)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
  src/main.cpp
  src/Cell.cpp
  src/Sheet.cpp
  src/Chart.cpp
  src/RangeException.cpp
)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(Sheet ${SOURCE_FILES})

target_link_libraries(Sheet sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

install(TARGETS Sheet DESTINATION )