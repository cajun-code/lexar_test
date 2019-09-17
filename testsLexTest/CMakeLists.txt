

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}/include
)
include_directories( ${INCLUDE_DIRS} )
include_directories(${LIBLexTest_INCLUDE_DIRS})
file(GLOB SOURCES "src/*.cpp")

add_executable(test_lex_test ${SOURCES})
target_link_libraries(test_lex_test libLexTest)

add_test(test_lex_test test_lex_test -s)