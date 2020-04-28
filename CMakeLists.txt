cmake_minimum_required(VERSION 3.15)
project(maximum_subarray_problem)

# Copy data files to build dir
foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")
set(CMAKE_CXX_FLAGS "-Wall")
add_executable(maximum_subarray_problem main.cpp Processing.cpp Processing.h)