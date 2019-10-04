// Created by: Nikolas North
// Date: October 3, 2019
/*
 * Implements the `mydiff` terminal command, which compares two given files.
 */

#include <iostream>
#include <string>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    // Check if two arguments were passed into `mydiff`
    if (argc != 3) {
        std::cerr << "Error: `mydiff` takes in two arguments" << std::endl;
        std::cerr << "" << std::endl;
        exit(-1);
    } else {
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        FileManager fileManager1 = FileManager(file1);
        FileManager fileManager2 = FileManager(file2);
        if (fileManager1.compareFile(fileManager2))
            std::cout << "Files are the same." << std::endl;
        else
            std::cout << "Files are different." << std::endl;

        exit(1);
    }
}
