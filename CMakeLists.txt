cmake_minimum_required(VERSION 3.4.3)
project (LexTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(libLexTest)
add_subdirectory(testsLexTest)

add_subdirectory(LexTest)
