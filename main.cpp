#include <iostream>
#include "include/Individual_Assignment/FileManager.h"

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("file1.txt");
    fileManager.getFileName();
    std::cout << fileManager.getGroupId() << std::endl;
    std::cout << fileManager.getGroupName() << std::endl;

    return 0;
}