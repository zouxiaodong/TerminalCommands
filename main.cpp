#include <iostream>
#include "include/Individual_Assignment/FileManager.h"

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("file1.txt");
    fileManager.getFileName();
    printf("Access time  = %d\n", fileManager.getLastAccess());

    return 0;
}