#include <iostream>
#include <string>
#include <fstream>
#include "parseTree.h"

int main(int argc, char** argv) {
    std::string file;         // filename

    // File given on the command line
    if (argc == 2) {
        file = argv[1];
        file += ".sp21";

        std::ofstream outfile;
        outfile.open(file, std::ios_base::app);
        outfile << " ";
        in_file.open(file);
    }

    //no file given so take user input from the keyboard
    else if (argc == 1) {
        std::string input;
        std::ofstream tempFile;                 // TempFile for user input
        file = "stdin.temp";

        tempFile.open(file, std::ios::trunc); // trunc overwrites

        std::string string = "";                // empty string for reading input

        std::cout << "Pressing \"Enter\" is the same as EOF" << std::endl;

        do {
            std::cout << std::endl << "Type your input here: ";
            // read user input
            getline(std::cin, input);  
            // write input to temp file
            tempFile << input << "\n";  
        // Pressing "Enter" on empty line will sim EOF    
        } while (!input.empty());         
        // close file
        tempFile.close();                   
        in_file.open(file);
    }
    //if there is more than one argument, quit the program
    else {
        std::cout << "Only one argument supported, you entered " << argc << "arguments." << std::endl;
        exit(EXIT_FAILURE);
    }

    //Try to open the file to begin the parsing process
    if (!in_file) {
        std::cout << "ERROR: Could not open " << file << " for reading" << std::endl;
        in_file.close();
        exit(EXIT_FAILURE);
    }
    //parse the tokens in the file and then print the tree to the screen
    else { 
        std::cout << "Beginning to build the parse tree!" << std::endl;
        treeNode* root = parser(); // run parser
        printTree(root);      // print tree
        in_file.close(); // close file    
    }
    return 0;
}
