//
//  token.h
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//

#pragma once
#include <string>
using namespace std;

enum TokenType{
    TOK_EOF = 0,
    TOK_DEF,
    TOK_IDENTIFIER,
    TOK_NUMBER,
    TOK_OPERATOR
};

class Token{
public:
    TokenType type;
    string lexeme;
    double numValue;
    
    Token(TokenType t, string lex);
    Token(TokenType t, double val);
};
