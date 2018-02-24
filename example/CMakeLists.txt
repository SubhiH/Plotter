
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(plotter)
find_package( OpenCV REQUIRED )
add_executable(plotter main.cpp ../src/plotter.cpp ../src/plotter.hpp)
target_link_libraries( plotter ${OpenCV_LIBS} )
