#include <iostream>
#include "include/Individual_Assignment/FileManager.h"

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("North");
    fileManager.getFileName();
    std::cout << fileManager.getErrorNumber() << std::endl;

    return 0;
}