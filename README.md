# Bison-Flex_Compiler
# Custom Programming Language Compiler

**A complete compiler built with Flex (Lexical Analyzer) and Bison (Parser) for a Python-like programming language.**

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
![Flex](https://img.shields.io/badge/Flex-Lexical_Analyzer-4B0082.svg)
![Bison](https://img.shields.io/badge/Bison-Parser-006400.svg)
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)

**This project implements the front-end of a compiler (Lexical Analysis + Syntax Analysis) for a custom language supporting variables, control structures (if-elif-else, loops), functions, classes, and more.**

## ✨ Features

- **Lexical Analyzer** (Flex): Tokenization of keywords, identifiers, operators, strings, comments, and indentation handling
- **Syntax Analyzer** (Bison): Parsing with grammar rules and Abstract Syntax Tree (AST) generation
- Support for:
  - Variables and data types
  - Control flow: `if`, `elif`, `else`, `while`, `for`
  - Functions and classes
  - Comments (single & multi-line)
  - Indentation-based syntax (Python-like)
- Error detection and reporting
- Generation of `.gv` files for AST visualization using Graphviz

## 🛠 Technologies Used

- **Lexical Analyzer**: Flex (.l file)
- **Parser**: Bison (.y file)
- **Language**: C/C++
- **Visualization**: Graphviz (`.gv` → PNG)
- **Build Tools**: GCC / MinGW

## 📋 Project Details

- **Project Title**: مشروع بناء كومبايلر للغة باستخدام Flex و Bison
- **University**: Damascus University - Faculty of Informatics Engineering
- **Course**: Compiler Construction
- **Year**: 2023-2024

## 🚀 Build & Run

```bash
# On Windows (using win_flex & win_bison)
win_flex -o scanner.cpp test4.l
win_bison -d -o parser.cpp parser.y
g++ ast.cpp scanner.cpp parser.cpp -o compiler
compiler < input.txt > output.gv
dot -Tpng output.gv -o ast.png
