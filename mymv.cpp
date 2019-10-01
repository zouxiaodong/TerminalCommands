#include <iostream>
#include <sys/stat.h>
#include <string>

#include "FileManager.h"

int main(int argc, char *argv[]) {
    /*
     * TODO:
     *  - used to move and rename files around
     *  - use the rename method
     *  ============
     *  [] insert a condition checking if the second param passed into the command is already a pre-existing file.
     *      in this case, the program should terminate because the file already exists.
     *  [] figure out a way to check for the errors mentioned in the project description
     */
    if (argc != 3) {
        // Error
        std::cerr << "Error: `mymv` command takes 2 arguments." << std::endl;
        std::cerr << "" << std::endl; // ensure next command starts on newline
        exit(-1);
    } else {
        // Continue with program
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
            std::cout << newFileManager.getFileName() << std::endl;
            newFileManager.renameFile(newName);
            std::cout << newFileManager.getFileName() << std::endl;
        }
    }
}
