#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <string.h>

#include "FileManager.h"

int main(int argc, char* argv[]) {
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
        // Check if two directories were passed as arguments
        if (argc == 3) {
            std::cerr << "Error: Directories can only be listed one at a time." << std::endl;
            std::cerr << "" << std::endl;
            exit(-1);
        }
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
        // Check if directory was passed in as parameter
        if (argc == 2) {
            // No directory therefore, list current directory
            std::string cd = "./";
            FileManager currentDir = FileManager(cd);
            currentDir.expand();
            // Iterate through children and print fileName's
            for (int i = 0; i < currentDir.getChildren().size(); ++i) {
                FileManager currentChild = currentDir.getChildren()[i];
                std::cout << currentChild.getFileType() << "\t" << currentChild.getOwnerName() << "\t" << currentChild.getGroupName() << "\t" << currentChild.getFileSize() << "\t" << currentChild.getLastModification().tv_sec << "\t" << currentChild.getFileName() << std::endl;
            }
            std::cout << "" << std::endl;
        }
        std::string dirName = argv[2];
        FileManager fileManager = FileManager(dirName);
        // Check if fileManager is a directory
        if (S_ISDIR(fileManager.getFileType()) == 0) {
            // Not a directory
            std::cerr << "Error: '" << fileManager.getFileName() << "' is not a directory." << std::endl;
            std::cerr << "" << std::endl;
        } else {
            // Is a directory
            fileManager.expand();
            for (int i = 0; i < fileManager.getChildren().size(); ++i) {
                FileManager currentChild = fileManager.getChildren()[i];
                std::cout << currentChild.getFileType() << "\t" << currentChild.getOwnerName() << "\t" << currentChild.getGroupName() << "\t" << currentChild.getFileSize() << "\t" << currentChild.getLastModification().tv_sec << "\t" << currentChild.getFileName() << std::endl;
            }
            std::cerr << "" << std::endl;
        }
    }
}
