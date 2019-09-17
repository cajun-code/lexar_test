SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}/include
)
include_directories( ${INCLUDE_DIRS} )

file(GLOB SOURCES "src/*.cpp")

file(GLOB INCLUDE_FILES "include/*.h")

add_library(libLexTest SHARED ${INCLUDE_FILES} ${SOURCES})

set(LIBLexTest_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)