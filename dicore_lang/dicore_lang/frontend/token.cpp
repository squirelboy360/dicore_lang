//
//  token.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//

#include "token.h"
using namespace std;
//? provided the value of the double cause i dont want to leave it NULL for all cases
Token::Token(TokenType t,string lex):type(t),lexeme(lex),numValue(0.0){}

Token::Token(TokenType t, double val):type(t),numValue(val){}
