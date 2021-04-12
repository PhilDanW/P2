#ifndef PARSETREE_H
#define PARSETREE_H
#include "token.h"
#include "treeNode.h"

extern std::ifstream file;

treeNode* parser();
treeNode* program();
treeNode* block(unsigned int nodeDepth);
treeNode* vars(unsigned int nodeDepth);
treeNode* expr(unsigned int nodeDepth);
treeNode* N(unsigned int nodeDepth);
treeNode* A(unsigned int nodeDepth);
treeNode* M(unsigned int nodeDepth);
treeNode* R(unsigned int nodeDepth);
treeNode* stats(unsigned int nodeDepth);
treeNode* mstat(unsigned int nodeDepth);
treeNode* stat(unsigned int nodeDepth);
treeNode* In(unsigned int nodeDepth);
treeNode* Out(unsigned int nodeDepth);
treeNode* If(unsigned int nodeDepth);
treeNode* loop(unsigned int nodeDepth);
treeNode* assign(unsigned int nodeDepth);
treeNode* RO(unsigned int nodeDepth);
treeNode* label(unsigned int nodeDepth);
treeNode* Goto(unsigned int nodeDepth);

void error1(tokens needed, Token current);
void error2(tokens needed1, tokens needed2, Token current);
void error3(tokens needed1, tokens needed2, tokens needed3, Token current);
void errorN(Token current);

void printTree(Node* node);

#endif

  
