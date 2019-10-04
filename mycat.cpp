// Created by: Nikolas North
// Date: October 3, 2019
/*
 * Implements the `mycat` terminal command, which outputs the contents of a file to the terminal.
 */

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <fstream>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: `cat` command takes one argument" << std::endl;
        std::cerr << "" << std::endl;
        exit(-1);
    } else {
        // Check if argv[1] is a valid file and not a directory
        std::string fileName = argv[1];
        FileManager fileManager = FileManager(fileName);
        if (S_ISDIR(fileManager.getFileType() != 0)) {
            // Is a directory
            std::cerr << "Error: Directory passed in as argument for `cat`" << std::endl;
            std::cerr << "" << std::endl;
        } else {
            // Not a directory
            std::ofstream tempFile("tempFile.txt");
            fileManager.dump(tempFile);
            std::ifstream inFile;
            inFile.open("tempFile.txt");
            if (inFile.fail()) {
                std::cerr << "Error opening tempFile." << std::endl;
                std::cerr << "" << std::endl;
            } else {
                std::string currentLine;
                while (std::getline(inFile, currentLine)) {
                    std::cout << currentLine << std::endl;
                }
                inFile.close();
                tempFile.close();
            }
        }
    }
}
