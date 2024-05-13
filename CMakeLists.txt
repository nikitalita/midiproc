cmake_minimum_required(VERSION 3.10)

project(midiproc)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp" "compat/os_compat.c")

add_library(midiproc ${SOURCES})
target_include_directories(midiproc PRIVATE compat)

add_executable(test test/test_midiproc.c)
target_include_directories(test PRIVATE src)

target_link_libraries(test midiproc)
