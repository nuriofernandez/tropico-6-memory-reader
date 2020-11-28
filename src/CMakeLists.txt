cmake_minimum_required(VERSION 3.16)
project(tropico-6-memory-reader)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        tropico-6-memory-reader
        main.cpp

        MemoryReader.cpp
        GameResources.cpp
)