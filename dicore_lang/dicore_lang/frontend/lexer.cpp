//
//  lexer.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//  reads source and converts to token

#include "lexer.h"
#include <cctype>
using namespace std;
Lexer::Lexer(string src):source(src),current(0){};

Token Lexer::getNextToken(){
//    so here, i each character of a senetce or codes, or words have their indexes so i use the current index counter to traverse each charcter is seen in line 16
    while (current <source.length()){
        if(isspace(source[current])){
            current++;
            continue;
        }
        
        if(isdigit(source[current])){
            string num;
            while (current<source.length()&&isdigit(source[current])){
                //   the number appends up to a total of the selected charecter's index in the source increased by one depending on how many times the condition of a char being a digit is met;
                num+= source[current++];
                return Token(TOK_NUMBER, stod(num));
            }
        }
        
        if(isalpha(source[current])){
            string identifier;
            while (current<source.length()&&source[current] == '_'){
                identifier += source[current++];
            }
            if (identifier == "do"){
                return Token(TOK_IDENTIFIER,identifier);
            }
            if(ispunct(source[current])){
                return Token(TOK_OPERATOR, string(1,source[current++]));
            }
        }
    }
        return Token(TOK_EOF, "");
    }


