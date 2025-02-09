cmake_minimum_required(VERSION 3.10)

project(dicore_lang)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files (adjust paths based on where your files are)
set(SOURCES
    backend/compiler.cpp
    frontend/ast.cpp
    frontend/lexer.cpp
    frontend/parser.cpp
    main.cpp 
)

add_executable(dicore_lang ${SOURCES})

# Link LLVM
target_link_libraries(dicore_lang
    /opt/homebrew/opt/llvm@14/lib/libLLVM.dylib
)
