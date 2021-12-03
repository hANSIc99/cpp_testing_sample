add_library(Generator STATIC Generator.cpp Generator.h)

target_include_directories(Generator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


enable_testing()

add_executable(GeneratorTest GeneratorTest.cpp)

target_link_libraries(GeneratorTest gtest_main Generator)

include(GoogleTest)
gtest_discover_tests(GeneratorTest)