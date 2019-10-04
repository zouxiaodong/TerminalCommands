// Created by: Nikolas North
// Date: October 3, 2019
/*
 * Implements the `mycp` terminal command, which copies a given file.
 */

#include <iostream>
#include <sys/stat.h>
#include <fstream>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        // Terminate program due to incorrect number of args
        std::cerr << "Error: `mymv` command takes 2 arguments." << std::endl;
        std::cerr << "" << std::endl; // ensure next command starts on newline
        exit(-1);
    } else {
        // Check first and second arguments are not directories
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        FileManager fileManager1 = FileManager(file1);
        FileManager fileManager2 = FileManager(file2);
        if ((S_ISDIR(fileManager1.getFileType()) != 0) || (S_ISDIR(fileManager2.getFileType()) != 0)) {
            // Error
            std::cerr << "Error: Directories cannot be used." << std::endl;
            std::cerr << "" << std::endl;
        } else {
            // Command is valid
            std::ofstream newFile(file2);
            fileManager1.dump(newFile);
        }
    }
}
