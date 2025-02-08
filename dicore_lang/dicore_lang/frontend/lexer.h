//
//  lexer.h
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//

#pragma once
#include "token.h"
#include <string>

class Lexer{
    string source;
    size_t current;
    
public:
    Lexer(string src);
    Token getNextToken();
};
