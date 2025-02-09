//
//  compiler.h
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/9/25.
//

#pragma once
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include "parser.h"

class Compiler {
    llvm::LLVMContext context;
    std::unique_ptr<llvm::Module> module;
    llvm::IRBuilder<> builder;

public:
    Compiler(std::string moduleName);
    bool compile(const std::string& source);
    void dumpIR();
};
