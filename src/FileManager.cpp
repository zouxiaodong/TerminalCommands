#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <fstream>
#include <cstdio>

#include "../include/Individual_Assignment/FileManager.h"

FileManager::FileManager(const std::string& fileName) {
    this->fileName = fileName;

    struct stat buf;
    struct passwd *pwd;
    struct group *grp;
    if (stat(this->fileName.c_str(), &buf) != -1) {
        this->fileType = buf.st_mode;
        this->fileSize = buf.st_size;
        this->ownerId = buf.st_uid;
        if ((pwd = getpwuid(this->ownerId)) != nullptr) {
            this->ownerName = pwd->pw_name;
        } else {
            std::cout << "Error occurred in getpwuid(), NULL returned." << std::endl;
        }
        this->groupId = buf.st_gid;
        if ((grp = getgrgid(this->groupId)) != nullptr) {
            this->groupName = grp->gr_name;
        }
        this->filePermissions = buf.st_mode;
        this->lastAccess = buf.st_atimespec;
        this->lastModification = buf.st_mtimespec;
        this->lastStatusChange = buf.st_ctimespec;
        this->blockSize = buf.st_blksize;
    } else {
        std::cout << "Error occurred in stat(), value of -1 returned. Check if filename is valid." << std::endl;
    }
    this->errorNumber = 0;
}

FileManager::~FileManager() = default;

std::string FileManager::getFileName() {
    return this->fileName;
}

mode_t FileManager::getFileType() {
    return this->fileType;
}

off_t FileManager::getFileSize() {
    return this->fileSize;
}

uid_t FileManager::getOwnerId() {
    return this->ownerId;
}

const char * FileManager::getOwnerName() {
    return this->ownerName;
}

gid_t FileManager::getGroupId() {
    return this->groupId;
}

const char * FileManager::getGroupName() {
    return this->groupName;
}

mode_t FileManager::getFilePermissions() {
    return this->filePermissions;
}

timespec FileManager::getLastAccess() {
    return this->lastAccess;
}

timespec FileManager::getLastModification() {
    return this->lastModification;
}

timespec FileManager::getLastStatusChange() {
    return this->lastStatusChange;
}

blksize_t FileManager::getBlockSize() {
    return this->blockSize;
}

int FileManager::getErrorNumber() {
    return this->errorNumber;
}

int FileManager::dump(std::ofstream & outFile) {
    std::ifstream inFile;
    inFile.open(this->getFileName());

    if (inFile.fail()) {
        this->errorNumber = -1;
        std::cerr << "Error opening file." << std::endl;

        return -1;
    } else {
        std::string currentLine;
        while (std::getline(inFile, currentLine)) {
            std::cout << currentLine << std::endl;
            outFile << currentLine << std::endl;
        }
        inFile.close();
        outFile.close();

        return 0;
    }
}

void FileManager::renameFile(std::string& newName) {
    if (rename(this->fileName.c_str(), newName.c_str()) == -1) {
        std::cerr << "Error: File could not be renamed." << std::endl;
        this->errorNumber = -1;
        exit(1);
    } else {
        this->fileName = newName;
    }
}
