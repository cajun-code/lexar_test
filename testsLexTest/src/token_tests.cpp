// token_tests.cpp create by alley on 15, Sep 2019 
#include "catch.hpp"
#include "fakeit.hpp"
#include <token.h>

// tutorial: https://github.com/philsquared/Catch/blob/master/docs/tutorial.md
// API Reference: https://github.com/philsquared/Catch/blob/master/docs/Readme.md
// FakeIt: https://github.com/eranpeer/FakeIt/wiki/Quickstart

Token token;
SCENARIO( "Tokens can be created", "[Token]" ) {
    GIVEN( "I have a token created " ) {
        token = Token(4, 1, TOKEN_TYPE::Keyword_print);
        WHEN( "I create a string out of the token" ) {
            std::string result = token.toString();
            THEN( "I should see the following values" ) {
                REQUIRE( result == "4\t1\tKeyword_print" );
            }
        }
    }
}

SCENARIO( "Tokens can be printed with value", "[Token]" ) {
    GIVEN( "I have a token created " ) {
        token = Token(4, 1, TOKEN_TYPE::String, std::string("\"Hello, World!\\n\""));
        WHEN( "I create a string out of the token" ) {
            std::string result = token.toString();
            THEN( "I should see the following values with identifier" ) {
                REQUIRE( result == "4\t1\tString\t\"Hello, World!\\n\"" );
            }
        }
    }
}