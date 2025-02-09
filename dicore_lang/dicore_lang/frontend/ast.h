//
//  ast.h
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//
//this is the abstarct syntax tree
//just incase the ancronyms are unclear

#pragma once
#include <llvm/IR/IRBuilder.h>


class ASTNode {
public:
//    enable polymorphism so we can override the destructuring method
    virtual ~ASTNode() = default;
    virtual llvm::Value* codegen(llvm::IRBuilder<>& builder) = 0;

    class NumberExprAST : public ASTNode {
        double val;
        public:
        NumberExprAST(double val);
        llvm::Value* codegen(llvm::IRBuilder<>& builder) override;
    }
}
