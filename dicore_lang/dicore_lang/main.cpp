//
//  main.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//

#include <iostream>
#include "compiler.h"

int main() {
    std::string sourceCode = "do main() { return 42; }";  // Example code

    Compiler compiler("MyModule");
    if (compiler.compile(sourceCode)) {
        std::cout << "Compilation successful!" << std::endl;
        compiler.dumpIR();
    } else {
        std::cerr << "Compilation failed!" << std::endl;
    }

    return 0;
}
