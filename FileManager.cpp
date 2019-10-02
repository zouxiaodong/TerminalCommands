#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include <string.h>

#include "FileManager.h"

FileManager::FileManager(const std::string &fileName) {
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
//        this->lastAccess = buf.st_atimespec;
        this->lastAccess = buf.st_atim;
//        this->lastModification = buf.st_mtimespec;
        this->lastModification = buf.st_mtim;
//        this->lastStatusChange = buf.st_ctimespec;
        this->lastStatusChange = buf.st_ctim;
        this->blockSize = buf.st_blksize;
    } else {
        std::cerr << "Error: stat() could not process file. Check if '" << this->fileName << "' exists." << std::endl;
        exit(-1);
    }

    // TODO: Look into (1) http://www.cplusplus.com/reference/system_error/errc/ and (2) http://www.cplusplus.com/reference/cerrno/errno/
    this->errorNumber = 0;
}

FileManager::~FileManager() = default;

std::string FileManager::getFileName() { return this->fileName; }

void FileManager::setFileName(std::string &newName) { this->renameFile(newName); }

mode_t FileManager::getFileType() { return this->fileType; }

off_t FileManager::getFileSize() { return this->fileSize; }

uid_t FileManager::getOwnerId() { return this->ownerId; }

const char *FileManager::getOwnerName() { return this->ownerName; }

gid_t FileManager::getGroupId() { return this->groupId; }

const char *FileManager::getGroupName() { return this->groupName; }

mode_t FileManager::getFilePermissions() { return this->filePermissions; }

timespec FileManager::getLastAccess() { return this->lastAccess; }

timespec FileManager::getLastModification() { return this->lastModification; }

timespec FileManager::getLastStatusChange() { return this->lastStatusChange; }

blksize_t FileManager::getBlockSize() { return this->blockSize; }

std::vector<FileManager> FileManager::getChildren() {
    if (S_ISDIR(this->fileType) == 0) {
        // This file is not a directory
        this->errorNumber = (int) ENOTDIR;
        std::cerr << "Error: This file is not a directory, therefore it has no children.";

        exit(-1);
    } else
        return this->children;
}

int FileManager::getErrorNumber() { return this->errorNumber; }

int FileManager::dump(std::ofstream &outFile) {
    // TODO: Figure out block size part of this function
    if (S_ISREG(this->fileType) == 0) {
        // Not a regular file
        std::cerr << "Error: File is not a regular file." << std::endl;
        this->errorNumber = (int) ENOTSUP;

        return this->errorNumber;
    } else {
        // Regular file
        std::ifstream inFile;
        inFile.open(this->getFileName());
        if (inFile.fail()) {
            std::cerr << "Error opening file." << std::endl;
            this->errorNumber = (int) ENOENT;

            return this->errorNumber;
        } else {
            std::string currentLine;
            while (std::getline(inFile, currentLine)) {
                outFile << currentLine << std::endl;
            }
            inFile.close();
            outFile.close();
            this->errorNumber = 0;

            return 0;
        }
    }
}

int FileManager::renameFile(std::string &newName) {
    if (rename(this->fileName.c_str(), newName.c_str()) == -1) {
        std::cerr << "Error: File could not be renamed." << std::endl;
        this->errorNumber = (int) ENOENT;

        return this->errorNumber;
    } else {
        this->fileName = newName;
        this->errorNumber = 0;

        return 0;
    }
}

int FileManager::removeFile() {
    // TODO: Figure out how to reset the lastAccess, lastModification and lastStatusChange attributes
    // TODO: Segmentation fault when running on rasp pi virtual machine?
    if (unlink(this->fileName.c_str()) == -1) {
        std::cerr << "Error: File could not be deleted." << std::endl;
        this->errorNumber = (int) ENOENT;

        return this->errorNumber;
    } else {
        std::cout << "File deleted." << std::endl;
//        // Reset attributes of this object
//        this->fileName = nullptr;
//        this->fileType = 0;
//        this->fileSize = 0;
//        this->ownerId = 0;
//        this->ownerName = nullptr;
//        this->groupId = 0;
//        this->groupName = nullptr;
//        this->filePermissions = 0;
////        this->lastAccess = 0;
////        this->lastModification = 0;
////        this->lastStatusChange = 0;
//        this->blockSize = 0;
//        this->errorNumber = 0;

        return 0;
    }
}

bool FileManager::compareFile(FileManager &fileManager) {
    // TODO: Figure out error part of this function
    // TODO: Figure out block size part of this function
    // Compare data attributes between the two FileManager objects
    if (fileManager.getFileName() != this->fileName)
        return false;
    else if ((int) fileManager.getFileType() != (int) this->fileType)
        return false;
    else if ((int) fileManager.getFileSize() != (int) this->fileSize)
        return false;
    else if ((int) fileManager.getOwnerId() != (int) fileManager.getOwnerId())
        return false;
    else if (strcmp(fileManager.getOwnerName(), this->ownerName) != 0)
        return false;
    else if ((int) fileManager.getGroupId() != (int) this->groupId)
        return false;
    else if (strcmp(fileManager.getGroupName(), this->groupName) != 0)
        return false;
    else if ((int) fileManager.getFilePermissions() != (int) this->filePermissions)
        return false;
    else if ((int) fileManager.getLastAccess().tv_sec != (int) this->lastAccess.tv_sec)
        return false;
    else if (((int) fileManager.getLastModification().tv_sec != (int) this->lastModification.tv_sec))
        return false;
    else if ((int) fileManager.getLastStatusChange().tv_sec != (int) this->lastStatusChange.tv_sec)
        return false;
    else if ((int) fileManager.getBlockSize() != (int) this->blockSize)
        return false;
    else if (fileManager.getErrorNumber() != this->errorNumber)
        return false;

    return true;
}

int FileManager::expand() {
    if (S_ISDIR(this->fileType) == 0) {
        // Not a directory
        std::cerr << "Error: File is not a directory." << std::endl;
        this->errorNumber = (int) ENOTDIR;

        return this->errorNumber;
    } else {
        // Is a directory
        DIR *dir;
        if ((dir = opendir(this->fileName.c_str())) != nullptr) {
            struct dirent *filep;
            while ((filep = readdir(dir)) != nullptr) {
                FileManager newFileManager = FileManager(this->fileName + filep->d_name);
                // Append newFileManager to this object's children vector
                this->children.push_back(newFileManager);
            }
            closedir(dir);
        } else {
            std::cerr << "Directory is not found." << std::endl;
            this->errorNumber = (int) ENOTSUP;

            return this->errorNumber;
        }
        this->errorNumber = 0;

        return 0;
    }
}
