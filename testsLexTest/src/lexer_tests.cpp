// lexer_tests.cpp create by alley on 15, Sep 2019 
#include "catch.hpp"
#include "fakeit.hpp"
#include <lexer.h>
#include <iostream>
#include <fstream>
#include <sstream>
// tutorial: https://github.com/philsquared/Catch/blob/master/docs/tutorial.md
// API Reference: https://github.com/philsquared/Catch/blob/master/docs/Readme.md
// FakeIt: https://github.com/eranpeer/FakeIt/wiki/Quickstart



Lexer lexer;
SCENARIO( "Lexer willnot process comments", "[Lexer]" ) {
    GIVEN( "I have a file to process " ) {
        std::ifstream inFile;
        std::ostringstream outFile;
        inFile.open("./testsLexTest/data/case1.txt");
        WHEN( "I run the file through the lexer" ) {
            lexer.processTokens(inFile, outFile);
            std::string result = outFile.str();
            THEN( "I should see the following values" ) {
                REQUIRE( lexer.getTokens().front().getLineNumber() == 4 );
            }
        }
        inFile.close();
    }
}

SCENARIO( "Lexer will recognize a string", "[Lexer]" ) {
    GIVEN( "I have a string to process " ) {
        std::istringstream inFile;
        std::ostringstream outFile;
        inFile.str("\"Hello, World!\n\"");
        WHEN( "I run the file through the lexer" ) {
            lexer.processTokens(inFile, outFile);
            std::string result = outFile.str();
            THEN( "I should see the following values" ) {
                Token resultToken = lexer.getTokens().front();
                REQUIRE(resultToken.getTokenType() == TOKEN_TYPE::String );
                REQUIRE(resultToken.getValue() ==  "\"Hello, World!\n\"");
            }
        }
        
    }
}

SCENARIO( "Lexer will recognize a Integer", "[Lexer]" ) {
    GIVEN( "I have a Integer to process " ) {
        std::istringstream inFile;
        std::ostringstream outFile;
        inFile.str("25");
        WHEN( "I run the file through the lexer" ) {
            lexer.processTokens(inFile, outFile);
            std::string result = outFile.str();
            THEN( "I should see the following values" ) {
                Token resultToken = lexer.getTokens().front();
                REQUIRE(resultToken.getTokenType() == TOKEN_TYPE::Integer );
                REQUIRE(resultToken.getValue() ==  "25");
            }
        }
        
    }
}

SCENARIO( "Lexer will recognize a Character", "[Lexer]" ) {
    GIVEN( "I have a Integer to process " ) {
        std::istringstream inFile;
        std::ostringstream outFile;
        inFile.str("\'A\'");
        WHEN( "I run the file through the lexer" ) {
            lexer.processTokens(inFile, outFile);
            std::string result = outFile.str();
            THEN( "I should see the following values" ) {
                Token resultToken = lexer.getTokens().front();
                REQUIRE(resultToken.getTokenType() == TOKEN_TYPE::Integer );
                REQUIRE(resultToken.getValue() ==  "65");
            }
        }
        
    }
}

// Full Test Cases 
SCENARIO( "Lexer will process first test case", "[Lexer]" ) {
    GIVEN( "I have a file to process " ) {
        std::ifstream inFile;
        std::ostringstream outFile;
        inFile.open("./testsLexTest/data/case1.txt");
        WHEN( "I run the file through the lexer" ) {
            lexer.processTokens(inFile, outFile);
            std::string result = outFile.str();
            THEN( "I should see the following values" ) {
                std::string expected = "4\t1\tKeyword_print\n4\t6\tLeftParen\n4\t7\tString\t\"Hello, World!\\n\"\n4\t24\tRightParen\n4\t25\tSemicolon\n5\t1\tEnd_of_input\n";
                REQUIRE(result == expected );
            }
        }
        inFile.close();
    }
}
