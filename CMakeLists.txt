cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(CPP_Testing_Sample VERSION 1.0)

add_subdirectory(Generator)

# add the executable
add_executable(Producer producer.cpp)

# alternative cmake -DCMAKE_BUILD_TYPE=Debug <path and other arguments>
set(CMAKE_BUILD_TYPE Debug)

# add library
target_link_libraries(Producer PUBLIC Generator)

# specifz include directories
#target_include_directories(Producer PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                           )