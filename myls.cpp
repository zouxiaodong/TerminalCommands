#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <string.h>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    /*
     * TODO: implement -l flag
     */
    if (argc > 3) {
        // Invalid number of arguments
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "" << std::endl;
    }
    else if (argc == 1) {
        // No arguments
        std::string cd = "./";
        FileManager currentDir = FileManager(cd);
        currentDir.expand();
        // Iterate through children and print fileName's
        for (int i = 0; i < currentDir.getChildren().size(); ++i) {
            std::cout << currentDir.getChildren()[i].getFileName() << std::endl;
        }
    }
    else if (strcmp(argv[1], "-l") != 0) {
        // -l flag is not set
        std::string dirName = argv[1];
        FileManager fileManager = FileManager(dirName);
        // Check if fileManager is a directory
        if (S_ISDIR(fileManager.getFileType()) == 0) {
            // Not a directory
            std::cerr << "Error: '" << fileManager.getFileName() << "' is not a directory." << std::endl;
            std::cerr << "" << std::endl;
        } else {
            // Is a directory
            fileManager.expand();
            // Iterate through children and print fileName's
            for (int i = 0; i < fileManager.getChildren().size(); ++i) {
                std::cout << fileManager.getChildren()[i].getFileName() << std::endl;
            }
        }
    } else {
        // -l flag is set

    }
}
