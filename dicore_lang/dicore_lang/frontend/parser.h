//
//  parser.h
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//

#pragma once
#include "lexer.h"
#include "ast.h"
#include <vector>
#include <memory>

class Parser {
    Lexer& lexer;
    std::vector<Token> tokens;
    size_t current;
    
public:
    Parser(Lexer& lex);
    std::unique_ptr<ASTNode> parseExpression();
};
