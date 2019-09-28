#include <iostream>
#include "include/Individual_Assignment/FileManager.h"
#include <fstream>

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("file1.txt");
    std::cout << fileManager.getFileName() << std::endl;
    std::cout << fileManager.getBlockSize() << std::endl;
    std::ofstream outFile("../test-files/helloWorld.txt");
    fileManager.dump(outFile);

    return 0;
}