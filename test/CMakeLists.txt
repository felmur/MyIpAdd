cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_link_options(-lMyIpAdd)

add_executable(test main.cpp)
