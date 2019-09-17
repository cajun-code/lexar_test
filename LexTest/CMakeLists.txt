
#include_directories(include)
file(GLOB SOURCES "src/*.cpp")

include_directories(${LIBLexTest_INCLUDE_DIRS})

file(GLOB INCLUDE_FILES "include/*.h")

add_executable(lex_test ${SOURCES})
target_link_libraries(lex_test libLexTest)