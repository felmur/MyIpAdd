cmake_minimum_required(VERSION 3.5)

project(MyIpAdd LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MyIpAdd SHARED
  MyIpAdd_global.h
  myipadd.cpp
  myipadd.h
)

set_target_properties(MyIpAdd PROPERTIES VERSION "1.0.0"" SOVERSION "1"")

target_compile_definitions(MyIpAdd PRIVATE MYIPADD_LIBRARY)

install(TARGETS MyIpAdd DESTINATION /usr/lib)
install(FILES  MyIpAdd_global.h myipadd.h DESTINATION /usr/include)
