cmake_minimum_required(VERSION 3.10)
project(ExtractFloat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fsanitize=address")

include_directories(include)
add_executable(main main.cpp funcs.cpp)