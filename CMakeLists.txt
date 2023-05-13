cmake_minimum_required(VERSION 3.24)
project(SSC)

set(CMAKE_CXX_STANDARD 17)

add_executable(SSC main.cpp Cell.h Cell.cpp Spreadsheet.h Spreadsheet.cpp Test.h Test.cpp)
