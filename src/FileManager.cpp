#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

#include "../include/Individual_Assignment/FileManager.h"

FileManager::FileManager(const std::string& fileName) {
    this->fileName = "../test-files/" + fileName;

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
    } else {
        std::cout << "Error occurred in stat(), value of -1 returned." << std::endl;
    }

    this->errorNumber = 0;
}

void FileManager::getFileName() {
    std::cout << this->fileName << std::endl;
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

int FileManager::getErrorNumber() {
    return this->errorNumber;
}
