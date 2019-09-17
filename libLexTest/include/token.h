#include <string>
// token.h create by alley on 15, Sep 2019 
#pragma once

enum class TOKEN_TYPE { End_of_input, Op_multiply, Op_divide, Op_mod, Op_add, Op_subtract,
Op_negate, Op_not, Op_less, Op_lessequal, Op_greater, Op_greaterequal,
Op_equal, Op_notequal, Op_assign, Op_and, Op_or, Keyword_if,
Keyword_else,  Keyword_while, Keyword_print, Keyword_putc, LeftParen,  RightParen,
LeftBrace, RightBrace, Semicolon, Comma, Identifier, Integer, String};

class Token{
public:
    Token(int line_no =0 , int column_no = 0, TOKEN_TYPE type = TOKEN_TYPE::End_of_input, const std::string& value = std::string(""));
    virtual ~Token();

    std::string toString();
    

private:
    int line_number;
    int column_number;
    TOKEN_TYPE type;
    std::string value;
    std::string getDisplayType();
};