#include "parser.h"
#include "scanner.h"
#include <iostream>

std::ifstream file;
unsigned int lineNumber = 1;
Token the_token;

std::string myTokens[] = {"BEGIN_KEYWORD","END_KEYWORD","LOOP_KEYWORD","WHILE_KEYWORD", "VOID_KEYWORD", "EXIT_KEYWORD", 
                        "GETTER_KEYWORD", "OUTTER_KEYWORD", "MAIN_KEYWORD", "IF_KEYWORD", "THEN_KEYWORD", "ASSIGN_KEYWORD", 
                        "DATA_KEYWORD", "PROC_KEYWORD", "EQUALS_OPERATOR", "EQUALS_LESS_OPERATOR", 
                        "EQUALS_GREATER_OPERATOR", "EQUALS_EQUALS_OPERATOR", "COLON_OPERATOR", "COLON_EQUALS_OPERATOR",
                        "ADD_OPERATOR", "SUBTRACT_OPERATOR", "ASTERISK_OPERATOR", "DIVIDE_OPERATOR", "MODULUS_OPERATOR", 
                        "PERIOD_OPERATOR", "LEFT_PARENT_DELIM", "RIGHT_PARENT_DELIM", "COMMA_DELIM", "LEFT_BRACE_DELIM", 
                        "RIGHT_BRACE_DELIM", "SEMICOLON_DELIM", "LEFT_BRACKET_DELIM", "RIGHT_BRACKET_DELIM", "IDENTIFIER", 
                        "INTEGER", "EOF_TOKEN", "ERROR"
};

Node* parser() {
    Node* rootNode;
    the_token = scanner(file, lineNumber);
  
    rootNode = program();
    if(the_token.tokenID == EOF_TOKEN) {
        std::cout << "Parser is done with its job!! You did it!!" << std::endl;
        return rootNode;
    }
    else
        error1(EOF_TOKEN, the_token);
}

Node* program() {
    int nodeDepth = 0;
    Node*progNode = new Node("<program", nodeDepth);
    progNode->child_1 = vars(nodeDepth);
    if(the_token.tokenID == MAIN_KEYWORD) {
        progNode->token_1 = the_token;
        the_token = scanner(file, lineNumber);
        progNode->child_2 = block(nodeDepth);
    }
    else
        error1(MAIN_KEYWORD, the_token);
    return progNode;
}

Node* block(unsigned int nodeDepth) {
    nodeDepth++;
    Node* blockNode = new Node("<block>", nodeDepth);
    if(the_token.tokenID == BEGIN_KEYWORD) {
        blockNode->token_1 = the_token;
        the_token = scanner(file, lineNumber);
        blockNode->child_1 = vars(nodeDepth);
        blockNode->child_2 = stats(nodeDepth);
      
        if(the_token.tokenID == END_KEYWORD) {
            blockNode->token_2 = the_token;
            the_token = scanner(file, lineNumber);
            return blockNode;
        }
        else
            error1(END_KEYWORD, the_token);
    }
    else
        error1(BEGIN_KEYWORD, the_token);
}

Node* vars(unsigned int nodeDepth) {
    nodeDepth++;
    Node* varNode = new Node("<vars>", nodeDepth);
  
    if(the_token.tokenID == DATA_KEYWORD) 
    {
          varNode->token_1 = the_token;
          the_token = scanner(file, lineNumber);
          if (the_token.tokenID == IDENTIFIER) 
          {
                varNode->token_2 = the_token;
                the_token = scanner(file, lineNumber);
                if (the_token.tokenID == COLON_EQUALS_OPERATOR)
                {
                      varNode->token_3 = the_token;
                      the_token = scanner(file, lineNumber);
                      if (the_token.tokenID == INTEGER)
                      {
                            varNode->token_4 = the_token;
                            the_token = scanner(file, lineNumber);
                            if (the_token.tokenID == SEMICOLON_DELIM)
                            {
                                  varNode->token_5 = the_token;
                                  the_token = scanner(file, lineNumber);
                                  varNode->chiild_1 = vars(nodeDepth);
                                  return varNode;
                            }
                            else {
                                error1(SEMICOLON_DELIM, the_token);
                            }
                      }
                      else
                          error1(INTERGER, the_token);
                }
                else
                    error1(COLON_EQUALS_OPERATOR, the_token);
          }
          else
              error1(IDENTIFIER, the_token);
    }
    else
        return NULL;
}



