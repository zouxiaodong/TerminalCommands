#include <iostream>
#include "include/Individual_Assignment/FileManager.h"

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("file1.txt");
    fileManager.getFileName();
    std::cout << fileManager.getOwnerId() << std::endl;
    std::cout << fileManager.getOwnerName() << std::endl;

    return 0;
}