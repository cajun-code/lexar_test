// token.cpp create by alley on 15, Sep 2019 
#include "token.h"
#include <cstdio>
#include <string>

Token::Token(int line_no , int column_no, TOKEN_TYPE type, const std::string& value){
    this->line_number = line_no;
    this->column_number = column_no;
    this->type = type;
    this->value = value;
}

Token::~Token(){

}

std::string Token::getDisplayType(){
    switch(this->type){
        case TOKEN_TYPE::End_of_input: 
            return "End_of_input";
        case TOKEN_TYPE::Op_multiply:
            return "Op_multiply"; 
        case TOKEN_TYPE::Op_divide:
            return "Op_divide"; 
        case TOKEN_TYPE::Op_mod: 
            return "Op_mod";
        case TOKEN_TYPE::Op_add: 
            return "Op_add";
        case TOKEN_TYPE::Op_subtract:
            return "Op_subtract";
        case TOKEN_TYPE::Op_negate:
            return "Op_negate"; 
        case TOKEN_TYPE::Op_not: 
            return "Op_not";
        case TOKEN_TYPE::Op_less: 
            return "Op_less";
        case TOKEN_TYPE::Op_lessequal: 
            return "Op_lessequal";
        case TOKEN_TYPE::Op_greater: 
            return "Op_greater";
        case TOKEN_TYPE::Op_greaterequal:
            return "Op_greaterequal";
        case TOKEN_TYPE::Op_equal: 
            return "Op_equal";
        case TOKEN_TYPE::Op_notequal:
            return "Op_notequal"; 
        case TOKEN_TYPE::Op_assign:
            return "Op_assign"; 
        case TOKEN_TYPE::Op_and: 
            return "Op_and";
        case TOKEN_TYPE::Op_or: 
            return "Op_or";
        case TOKEN_TYPE::Keyword_if:
            return "Keyword_if";
        case TOKEN_TYPE::Keyword_else:  
            return "Keyword_else";
        case TOKEN_TYPE::Keyword_while: 
            return "Keyword_while";
        case TOKEN_TYPE::Keyword_putc: 
            return "Keyword_putc";
        case TOKEN_TYPE::LeftParen:
            return "LeftParen";  
        case TOKEN_TYPE::RightParen:
            return "RightParen";
        case TOKEN_TYPE::LeftBrace:
            return "LeftBrace"; 
        case TOKEN_TYPE::RightBrace:
            return "RightBrace"; 
        case TOKEN_TYPE::Semicolon:
            return "Semicolon"; 
        case TOKEN_TYPE::Comma: 
            return "Comma";
        case TOKEN_TYPE::Identifier:
            return "Identifier"; 
        case TOKEN_TYPE::Integer:
            return "Integer";
        case TOKEN_TYPE::Keyword_print:
            return "Keyword_print";
        case TOKEN_TYPE::String:
            return "String";
        default:
            return "Unrecognized Type";
    }
}

std::string Token::toString(){
    char result [50];  
    std::sprintf(result, "%d\t%d\t%s", this->line_number, this->column_number, getDisplayType().c_str());
    if(!this->value.empty()){
        char appendage [50];
        std::sprintf(appendage, "\t%s", this->value.c_str());
        strcat(result, appendage);
    }
    return std::string(result);
}
