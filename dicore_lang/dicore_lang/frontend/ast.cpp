//
//  ast.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//

#include "ast.h"

NumberExprAST::NumberExprAST(double val) : value(val) {}

llvm::Value* NumberExprAST::codegen(llvm::IRBuilder<>& builder) {
    return llvm::ConstantFP::get(builder.getContext(), llvm::APFloat(value));
}
