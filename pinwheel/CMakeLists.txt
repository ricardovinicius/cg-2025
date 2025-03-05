cmake_minimum_required(VERSION 3.2)
project(pinwheel)

set(CMAKE_CXX_STANDARD 17)

add_executable(pinwheel pinwheel.cpp)
target_link_libraries(pinwheel GL glut GLU)
