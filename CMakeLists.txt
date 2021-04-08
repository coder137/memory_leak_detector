cmake_minimum_required(VERSION 3.10.0)

project(memory_leak_detector)

include(CTest)
enable_testing()

# Libraries
add_subdirectory(lib/linkedlist)

# mldmalloc implementation
add_subdirectory(src)

# Tests
add_subdirectory(test)

