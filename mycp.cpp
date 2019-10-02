#include <iostream>
#include <sys/stat.h>
#include <fstream>

#include "FileManager.h"

int main(int argc, char* argv[]) {
    // Check if there are two parameters passed in
    // Throw error if not
    /*
     * TODO:
     * - check if two params are passed, output cerr msg otherwise
     * - check if argv[1] and argv[2] are not directories, output cerr msg otherwise
     * - use argv[1] to create a new FileManager obj
     * - use argv[2] as a string to be passed into dump() function
     * - call dump()
     * - check FileManager obj's errorNumber var to see if any errors occured. Output cerr message if so.
     */
    if (argc != 3) {
        // Terminate program due to incorrect number of args
        std::cerr << "Error: `mymv` command takes 2 arguments." << std::endl;
        std::cerr << "" << std::endl; // ensure next command starts on newline
        exit(-1);
    } else {
        // Check first argument is not a directory
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        FileManager fileManager1 = FileManager(file1);
        if (S_ISDIR(fileManager1.getFileType()) != 0) {
            // Error argv[1] is a directory (cannot be copied)
            std::cerr << "Error: '" << file1 << "' is a directory (not copied)." << std::endl;
            std::cerr << "" << std::endl;
        } else {
            // Command is valid
            std::ofstream newFile(file2);
            fileManager1.dump(newFile);
        }
    }
}
