#include <iostream>
#include <string>
#include "../include/Individual_Assignment/FileManager.h"

FileManager::FileManager(const std::string& fileName) {
    this->fileName = fileName;
}

void FileManager::getFileName() {
    std::cout << this->fileName << std::endl;
}