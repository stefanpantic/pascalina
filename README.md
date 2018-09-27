# λ: Pascalina
Mini Pascal to LLVM complier written in C++. The project uses ```flex``` and ```bison``` to construct an AST and perform some validity checks in the process. The tree can then be traversed via visitors to perform aditional checks or produce IR from it.
The end goal is to implement an LLVM visitor that will generate valid LLVM IR code from the tree.

## :clipboard: Plans:
- [x] Simple project structure (lexical and syntaxical analysis, Makefile)
- [x] Implement basic AST
- [x] Support function prototypes, definitions and function calls
- [x] Support basic arithmetic/relational operations
- [x] Support control structures (if-else, while)
- [x] Support functions
- [x] Perform semantic analysis
- [x] Include LLVM
- [x] Generate LLVM IR
- [x] Add arrays
- [ ] Allow passing of arrays to/from functions
- [ ] Add vectors

## :information_source: About me:
**Author:** Stefan Pantic.  
**Contact:** stefanpantic13@gmail.com  
