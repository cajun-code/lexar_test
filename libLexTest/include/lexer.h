// lexer.h create by alley on 15, Sep 2019 
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "token.h"

enum class LEXER_STATE {NORMAL, IN_COMMENT, IN_QUOTE};
class Lexer{
public:
    Lexer();
    virtual ~Lexer();
    
    void processTokens(std::istream &inFile, std::ostream &outFile);
    std::vector<Token> getTokens();

private:
    LEXER_STATE currentState;
    std::vector<Token> tokens;

};