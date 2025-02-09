//
//  compiler.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//

#include "compiler.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <iostream>

Compiler::Compiler(std::string moduleName)
    : module(std::make_unique<llvm::Module>(moduleName, context)),
      builder(context) {}

bool Compiler::compile(const std::string& source) {
    Lexer lexer(source);
    Parser parser(lexer);

    auto ast = parser.parseExpression();
    if (!ast) return false;

    llvm::FunctionType* mainType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(context), false);
    llvm::Function* mainFunc = llvm::Function::Create(
        mainType, llvm::Function::ExternalLinkage, "main", module.get());

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(context, "entry", mainFunc);
    builder.SetInsertPoint(entry);

    llvm::Value* result = ast->codegen(builder);
    if (!result) return false;

    builder.CreateRet(builder.CreateFPToSI(
        result, llvm::Type::getInt32Ty(context)));

    return true;
}

void Compiler::dumpIR() {
    module->print(llvm::outs(), nullptr);
}
