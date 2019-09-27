#include <iostream>
#include "include/Individual_Assignment/FileManager.h"

int main() {
    // Test FileManager
    FileManager fileManager = FileManager("file1.txt");
    fileManager.getFileName();
    printf("Access time  = %d\n", fileManager.getLastAccess());
    printf("Modification time  = %d\n", fileManager.getLastModification());

    return 0;
}