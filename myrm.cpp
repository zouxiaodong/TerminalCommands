// Created by: Nikolas North
// Date: October 3, 2019
/*
 * Implements the `myrm` terminal command, which deletes given file(s).
 */

#include <iostream>
#include <vector>
#include <string>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // No arguments provided to `myrm` command
        std::cerr << "Error: Provide file(s) to delete." << std::endl;
        std::cerr << "" << std::endl;
    } else {
        // Iterate through arguments provided and verify all files are valid
        for (int i = 1; i < argc; i++) {
            std::string fileName = argv[i];
            FileManager fileManager = FileManager(fileName);
            fileManager.removeFile();
        }
    }
}
