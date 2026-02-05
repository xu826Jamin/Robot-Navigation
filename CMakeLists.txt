cmake_minimum_required(VERSION 3.10)
project(RobotNavigator)

# Set C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files
add_executable(RobotNavigator
    src/main.cpp
    src/Map.cpp
    src/Robot.cpp
    src/Simulator.cpp
)

# Include directories
target_include_directories(RobotNavigator PRIVATE include)