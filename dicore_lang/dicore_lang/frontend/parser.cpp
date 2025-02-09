//
//  parser.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//

#include "parser.h"

Parser::Parser(Lexer& lex) : lexer(lex), current(0) {
    Token tok = lexer.getNextToken();
    while (tok.type != TOK_EOF) {
        tokens.push_back(tok);
        tok = lexer.getNextToken();
    }
}

std::unique_ptr<ASTNode> Parser::parseExpression() {
    if (current < tokens.size() && tokens[current].type == TOK_NUMBER) {
        auto node = std::make_unique<NumberExprAST>(tokens[current].numValue);
        current++;
        return node;
    }
    return nullptr;
}
