#include <iostream>
#include <string>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    /*
     * TODO:
     * - argc must = 3
     * - check if argv[1] and argv[2] are valid files
     * - call compareFile()
     * - if return value is true print they are the same
     * - if return values is false print they are different
     */
    // Check if two arguments were passed into `mydiff`
    if (argc != 3) {
        std::cerr << "Error: `mydiff` takes in two arguments" << std::endl;
        std::cerr << "" << std::endl;
        exit(-1);
    } else {
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        FileManager fileManager1 = FileManager(file1);
        FileManager fileManager2 = FileManager(file2);
        if (fileManager1.compareFile(fileManager2))
            std::cout << "Files are the same." << std::endl;
        else
            std::cout << "Files are different." << std::endl;

        exit(1);
    }
}
