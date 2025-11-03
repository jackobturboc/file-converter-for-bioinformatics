cmake_minimum_required(VERSION 3.29)
project(projectFM)

set(CMAKE_CXX_STANDARD 20)

add_executable(projectFM main.cpp
        sequences_files_format_descriptions.h
        sequences_files_format_descriptions.cpp)
