#include <iostream>
#include <sys/stat.h>
#include <string>

#include "FileManager.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        // Terminate program due to incorrect number of args
        std::cerr << "Error: `mymv` command takes 2 arguments." << std::endl;
        std::cerr << "" << std::endl; // ensure next command starts on newline
        exit(-1);
    } else {
        FileManager newFileManager = FileManager(argv[1]);
        // Check if first arg is a directory
        if (S_ISDIR(newFileManager.getFileType()) != 0) {
            // File is a directory, therefore invalid command
            std::cerr << "Error: '" << newFileManager.getFileName() << "' is a directory.";
            std::cerr << "" << std::endl; // ensure next command starts on newline
            exit(-1);
        } else {
            // Command is valid
            std::string newName = argv[2];
            newFileManager.renameFile(newName);
        }
    }
}
