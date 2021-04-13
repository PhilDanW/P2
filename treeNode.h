#ifndef TREENODE_H
#define TREENODE_H

#include "token.h"

struct Node {
  
    std::string label;
    int nodeDepth;
    
    Token token1;
    Token token2;
    Token token3;
    Token token4;
    Token token5;
    Token token6;
  
    Node* leaf1; 
    Node* leaf2;
    Node* leaf3;
    Node* leaf4;
  
    Node() {
      
        this->label = "";
        this->nodeDepth = 0;
        this->token1 = Token();
        this->token2 = Token();
        this->token3 = Token();
        this->token4 = Token();
        this->token5 = Token();
        this->token6 = Token();
      
        this->leaf1 = nullptr;
        this->leaf2 = nullptr;
        this->leaf3 = nullptr;
        this->leaf4 = nullptr;
    }
  
    Node(std::string label, int nodeDepth) {
          this->label = label;
          this->nodeDepth = nodeDepth;
          this->nodeDepth = 0;
          this->token1 = Token();
          this->token2 = Token();
          this->token3 = Token();
          this->token4 = Token();
          this->token5 = Token();
          this->token6 = Token();

          this->leaf1 = nullptr;
          this->leaf2 = nullptr;
          this->leaf3 = nullptr;
          this->leaf4 = nullptr;
    }
};

#endif
          
      
  
