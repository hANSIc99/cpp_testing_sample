cmake_minimum_required(VERSION 3.14)

# set the project name and version
project(CPP_Testing_Sample VERSION 1.0)

# define C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Generator)

# donwload gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/bb9216085fbbf193408653ced9e73c61e7766e80.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add the executable
add_executable(Producer producer.cpp)

# alternative cmake -DCMAKE_BUILD_TYPE=Debug <path and other arguments>
#set(CMAKE_BUILD_TYPE Debug) // funcktioniert nicht

# add library
target_link_libraries(Producer PUBLIC Generator)

# specifz include directories
target_include_directories(Producer PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# create compile commands for intelli sense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


enable_testing()

add_executable(unit_test unit_test.cpp)

target_link_libraries(unit_test gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_test)
                           