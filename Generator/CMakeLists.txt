add_library(Generator STATIC Generator.cpp Generator.h)

target_include_directories(Generator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(GeneratorTest GeneratorTest.cpp)
target_link_libraries(Generator PUBLIC gtest_main Generator)

add_test(
    NAME GeneratorTest 
    COMMAND GeneratorTest
)