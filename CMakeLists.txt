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

FetchContent_MakeAvailable(googletest)

# add the executable
add_executable(Producer Producer.cpp)

# alternative cmake -DCMAKE_BUILD_TYPE=Debug <path and other arguments>
#set(CMAKE_BUILD_TYPE Debug) // funcktioniert nicht


# specify dependecies
target_link_libraries(Producer PUBLIC Generator)

# specifz include directories
target_include_directories(Producer PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# create compile commands for intelli sense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


enable_testing()

add_test(NAME RegularUsage COMMAND Producer 10)
set_tests_properties(RegularUsage
  PROPERTIES PASS_REGULAR_EXPRESSION "^[0-9 ]+"
  )
                           
add_test(NAME NoArg COMMAND Producer)
set_tests_properties(NoArg
  PROPERTIES PASS_REGULAR_EXPRESSION "^Enter the number of elements as argument"
  )

add_test(NAME WrongArg COMMAND Producer ABC)
set_tests_properties(WrongArg
  PROPERTIES PASS_REGULAR_EXPRESSION "^Error: Cannot parse"
  )

add_test(NAME NegativeNo COMMAND Producer -3)
set_tests_properties(NegativeNo
  PROPERTIES PASS_REGULAR_EXPRESSION "^Error: Zero or negative number provided: "
  )