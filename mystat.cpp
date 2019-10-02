#include <iostream>
#include <string>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    /*
     * TODO:
     * - check if argc = 2
     * - create a new instance of FileManager
     * - print out all the attributes of that instance to the terminal in a readable format (line by line?)
     */
    if (argc != 2) {
        std::cerr << "Error: `mystat` takes one argument." << std::endl;
        std::cerr << "" << std::endl;
    } else {
        std::string fileName = argv[1];
        FileManager fileManager = FileManager(fileName);
        std::cout << "File Name:" << std::endl;
        std::cout << fileManager.getFileName() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "File Type:" << std::endl;
        std::cout << fileManager.getFileType() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "File Size:" << std::endl;
        std::cout << fileManager.getFileSize() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Owner ID:" << std::endl;
        std::cout << fileManager.getOwnerId() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Owner Name:" << std::endl;
        std::cout << fileManager.getOwnerName() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Group ID:" << std::endl;
        std::cout << fileManager.getGroupId() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Group Name:" << std::endl;
        std::cout << fileManager.getGroupName() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "File Permissions:" << std::endl;
        std::cout << fileManager.getFilePermissions() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Last Access:" << std::endl;
        std::cout << fileManager.getLastAccess().tv_sec << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Last Modification:" << std::endl;
        std::cout << fileManager.getLastModification().tv_sec << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Last Status Change:" << std::endl;
        std::cout << fileManager.getLastStatusChange().tv_sec << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Block Size:" << std::endl;
        std::cout << fileManager.getBlockSize() << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Error Number:" << std::endl;
        std::cout << fileManager.getErrorNumber() << std::endl;
        std::cout << "" << std::endl;
    }
}
