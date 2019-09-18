// lexar.cpp create by alley on 15, Sep 2019 
#include "lexer.h"
using namespace std;

Lexer::Lexer(){
    
}

Lexer::~Lexer(){

}

vector<Token> Lexer::getTokens(){
    return tokens;
}

void Lexer::processTokens(istream &inFile, ostream &outFile){
    currentState = LEXER_STATE::NORMAL;
	int lineNumber = 1;
	int topLineNumber = -1; 
    int startofword = -1;
    int column = 0;
    char c;
    tokens.clear();
    string comstr;

    while (inFile.get(c)) {
        column ++;
        //////INSIDE A QUOTE///////
        if (currentState == LEXER_STATE::IN_QUOTE) {
            
            if (c == '\"') {
                if (inFile.peek() == '\"') {
                    comstr += c;
                    inFile.get(c);
                    column++;
                }
                else {
                    //this is the end of the string
                    comstr += c;

                    Token token(topLineNumber, startofword , TOKEN_TYPE::String, comstr);
                    tokens.push_back(token);

                    comstr = "";

                    currentState = LEXER_STATE::NORMAL;
                }
            }
            else {
                comstr += c;
                if (c == '\n') {
                    lineNumber++;
                    column = 0;
                }
            }
        }

        /////INSIDE A COMMENT//////
        else if (currentState == LEXER_STATE::IN_COMMENT) {
            if (c == '*' && inFile.peek() == '/') {
                //end of the block comment
                currentState = LEXER_STATE::NORMAL;
                comstr += "*/";
                inFile.get(c);//read in the next one too
                column++;
            } else {
                comstr += c;
                if (c == '\n') {
                    lineNumber++;
                    column = 0;
                }
            }

            //////NOT INSIDE ANYTHING AT THE MOMENT//////
        } else {
            //checks if c is an alphabetic letter
            if (isalpha(c)) {

                //check for SCHEMES, FACTS, RULES, QUERIES
                string tempString = "";
                startofword = column;
                while (isalnum(inFile.peek()) || inFile.peek() == '_' ) {
                    tempString += c;
                    inFile.get(c);
                    column++;
                }

                if(inFile.peek() != EOF) tempString += c;

                Token token(lineNumber, startofword);

                if (tempString == "if") {
                    token.setTokenType(TOKEN_TYPE::Keyword_if);
                }
                else if (tempString == "else") {
                    token.setTokenType(TOKEN_TYPE::Keyword_else);
                }
                else if (tempString == "while") {
                    token.setTokenType(TOKEN_TYPE::Keyword_while);
                }
                else if (tempString == "putc") {
                    token.setTokenType(TOKEN_TYPE::Keyword_putc);
                }
                else if (tempString == "print") {
                    token.setTokenType(TOKEN_TYPE::Keyword_print);
                }
                else{
                    token.setTokenType(TOKEN_TYPE::Identifier);
                    token.setValue(tempString);
                }
                tokens.push_back(token);
                
            }
            ////WHITESPACE
            else if (isspace(c)) {
                //check if it is a new line
                if (c == '\n') {
                    lineNumber++;
                    column = 0;
                }
            }
            ////NUMBERS
            else if (isdigit(c)) {
                string tempDigit = "";
                startofword = column;
                while (isdigit(inFile.peek())) {
                    tempDigit += c;
                    inFile.get(c);
                    column++;
                }
                tempDigit += c;
                Token token(lineNumber,startofword, TOKEN_TYPE::Integer, tempDigit);
                tokens.push_back(token);
            }
            else if( c == '\''){
                // Character
                string tempChar= "";
                startofword = column;
                inFile.get(c);
                column++;
                if('\'' == inFile.peek()){
                    tempChar += to_string((int)c);
                    inFile.get(c);
                    column++;
                }
                Token token(lineNumber,startofword, TOKEN_TYPE::Integer, tempChar);
                tokens.push_back(token);
            }
            else if (c =='\"') {
                //starting a quote
                topLineNumber = lineNumber;
                currentState = LEXER_STATE::IN_QUOTE;
                startofword = column;
                comstr = "\"";
            }
            else if (c == '/') {
                topLineNumber = lineNumber;
                if (inFile.peek() == '*') {
                    inFile.get(c);
                    column++;
                    currentState = LEXER_STATE::IN_COMMENT;
                    comstr = "/*";
                }
            }else {
                //check for our special characters:
                
                Token token(lineNumber, column);

                switch (c) {
                    // Symbols
                    case ',': token.setTokenType(TOKEN_TYPE::Comma); break;
                    case '{': token.setTokenType(TOKEN_TYPE::LeftBrace); break;
                    case '}': token.setTokenType(TOKEN_TYPE::RightBrace); break;
                    case '(': token.setTokenType(TOKEN_TYPE::LeftParen); break;
                    case ')': token.setTokenType(TOKEN_TYPE::RightParen); break;
                    case ';': token.setTokenType(TOKEN_TYPE::Semicolon); break;
                    // Operations
                    case '+': token.setTokenType(TOKEN_TYPE::Op_add); break;
                    case '-': token.setTokenType(TOKEN_TYPE::Op_subtract); break;
                    case '*': token.setTokenType(TOKEN_TYPE::Op_multiply); break;
                    case '/': token.setTokenType(TOKEN_TYPE::Op_divide); break;
                    case '%': token.setTokenType(TOKEN_TYPE::Op_mod); break;
                    case '<':
                        if (inFile.peek() == '=') {
                            token.setTokenType(TOKEN_TYPE::Op_lessequal);
                            inFile.get(c);
                            column++;
                        }
                        else {
                            token.setTokenType(TOKEN_TYPE::Op_less);
                        }
                        break;
                    case '>':
                        if (inFile.peek() == '=') {
                            token.setTokenType(TOKEN_TYPE::Op_greater);
                            inFile.get(c);
                            column++;
                        }
                        else {
                            token.setTokenType(TOKEN_TYPE::Op_greaterequal);
                        }
                        break;
                    
                    case '=':
                        if (inFile.peek() == '=') {
                            token.setTokenType(TOKEN_TYPE::Op_equal);
                            inFile.get(c);
                            column++;
                        }
                        else {
                            token.setTokenType(TOKEN_TYPE::Op_assign);
                        }
                        break;
                    case '!':
                        if (inFile.peek() == '=') {
                            token.setTokenType(TOKEN_TYPE::Op_notequal);
                            inFile.get(c);
                            column++;
                        }
                        else {
                            token.setTokenType(TOKEN_TYPE::Op_not);
                        }
                        break;
                    case '&':
                        if (inFile.peek() == '&') {
                            token.setTokenType(TOKEN_TYPE::Op_and);
                            inFile.get(c);
                            column++;
                        }
                        break;
                    case '|':
                        if (inFile.peek() == '|') {
                            token.setTokenType(TOKEN_TYPE::Op_or);
                            inFile.get(c);
                            column++;
                        }
                        break;
                    

                }

                tokens.push_back(token);
                    
            }
        }
    }
    lineNumber++;
    Token token(lineNumber, 1, TOKEN_TYPE::End_of_input);
    tokens.push_back(token);
    for(Token temp : tokens)
        outFile << temp.toString() << std::endl;
}