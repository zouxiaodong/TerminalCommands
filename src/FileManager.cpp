#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/Individual_Assignment/FileManager.h"

FileManager::FileManager(const std::string& fileName) {
    this->fileName = "../test-files/" + fileName;

    struct stat buf;
    if (stat(this->fileName.c_str(), &buf) != -1) {
        this->fileType = buf.st_mode;
        this->fileSize = buf.st_size;
    } else {
        std::cout << "Error occurred in stat(), value of -1 returned." << std::endl;
    }

    this->errorNumber = 0;
}

void FileManager::getFileName() {
    std::cout << this->fileName << std::endl;
}

int FileManager::getErrorNumber() {
    return this->errorNumber;
}

mode_t FileManager::getFileType() {
    return this->fileType;
}

off_t FileManager::getFileSize() {
    return this->fileSize;
}