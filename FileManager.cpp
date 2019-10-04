// Created by: Nikolas North
// Date: October 3, 2019
/*
 * FileManager takes in a file name and extracts various information about that file, if it is valid.
 */

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

/**
 * FileManager constructor.
 * @param std::string fileName
 */
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
            std::cout << "Error occurred in getpwuid()." << std::endl;
        }
        this->groupId = buf.st_gid;
        if ((grp = getgrgid(this->groupId)) != nullptr) {
            this->groupName = grp->gr_name;
        }
        this->filePermissions = buf.st_mode;
        /*
         * On UNIX based system run:
         * this->lastAccess = buf.st_atimespec;
         * this->lastModification = buf.st_mtimespec;
         * this->lastStatusChange = buf.st_ctimespec;
         */
        this->lastAccess = buf.st_atim;
        this->lastModification = buf.st_mtim;
        this->lastStatusChange = buf.st_ctim;
        this->blockSize = buf.st_blksize;
    } else {
        std::cerr << "Error: stat() could not process file. Check if '" << this->fileName << "' exists." << std::endl;
        this->errorNumber = (int) ENOENT;
        exit(-1);
    }
    this->errorNumber = 0;
}

/**
 * FileManager destructor.
 */
FileManager::~FileManager() = default;

/**
 * getFileName()
 * Returns this FileManager's file name.
 *
 * @return std::string fileName
 */
std::string FileManager::getFileName() { return this->fileName; }

/**
 * getFileType()
 * Returns this FileManager's file type.
 *
 * @return mode_t fileType
 */
mode_t FileManager::getFileType() { return this->fileType; }

/**
 * getFileSize()
 * Returns this FileManager's file size.
 *
 * @return off_t fileSize
 */
off_t FileManager::getFileSize() { return this->fileSize; }

/**
 * getOwnerId()
 * Returns this FileManager's owner ID.
 *
 * @return uid_t ownerId
 */
uid_t FileManager::getOwnerId() { return this->ownerId; }

/**
 * getOwnerName()
 * Returns this FileManager's owner name.
 *
 * @return const char ownerName
 */
const char *FileManager::getOwnerName() { return this->ownerName; }

/**
 * getGroupId()
 * Returns this FileManager's group ID.
 *
 * @return gid_t groupId
 */
gid_t FileManager::getGroupId() { return this->groupId; }

/**
 * getGroupName()
 * Returns this FileManager's group name.
 *
 * @return const char groupName
 */
const char *FileManager::getGroupName() { return this->groupName; }

/**
 * getFilePermissions()
 * Returns this FileManager's file permissions.
 *
 * @return mode_t filePermissions
 */
mode_t FileManager::getFilePermissions() { return this->filePermissions; }

/**
 * getLastAccess()
 * Returns this FileManager's last access time.
 *
 * @return timespec lastAccess
 */
timespec FileManager::getLastAccess() { return this->lastAccess; }

/**
 * getLastModification()
 * Returns this FileManager's last modification time.
 *
 * @return timespec lastModification
 */
timespec FileManager::getLastModification() { return this->lastModification; }

/**
 * getLastStatusChange()
 * Returns this FileManager's last status change time.
 *
 * @return timespec lastStatusChange
 */
timespec FileManager::getLastStatusChange() { return this->lastStatusChange; }

/**
 * getBlockSize()
 * Returns this FileManager's block size.
 *
 * @return blksize_t blockSize
 */
blksize_t FileManager::getBlockSize() { return this->blockSize; }

/**
 * getChildren()
 * Returns this FileManager's children.
 *
 * @return std::vector<FileManager> children
 */
std::vector<FileManager> FileManager::getChildren() {
    if (S_ISDIR(this->fileType) == 0) {
        // This file is not a directory
        this->errorNumber = (int) ENOTDIR;
        std::cerr << "Error: This file is not a directory, therefore it has no children.";

        exit(-1);
    } else {
        this->errorNumber = 0;

        return this->children;
    }
}

/**
 * getErrorNumber()
 * Returns this FileManager's error number.
 *
 * @return int errorNumber
 */
int FileManager::getErrorNumber() { return this->errorNumber; }

/**
 * setFileName()
 * Renames this FileManger object's file name.
 *
 * @param std::string newName
 */
void FileManager::setFileName(std::string &newName) { this->renameFile(newName); }

/**
 * dump()
 * Takes a file stream as a parameter and dump the contents of the named file to that file stream.
 *
 * @param std::ofstream outFile
 * @return int
 */
int FileManager::dump(std::ofstream &outFile) {
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

            return this->errorNumber;
        }
    }
}

/**
 * renameFile()
 * Changes the name of the file from its existing name to the new name provided as a parameter to this function.
 *
 * @param std::string newName
 * @return int
 */
int FileManager::renameFile(std::string &newName) {
    if (rename(this->fileName.c_str(), newName.c_str()) == -1) {
        std::cerr << "Error: File could not be renamed." << std::endl;
        this->errorNumber = (int) ENOENT;

        return this->errorNumber;
    } else {
        this->fileName = newName;
        this->errorNumber = 0;

        return this->errorNumber;
    }
}

/**
 * removeFile()
 * Removes the file from the file system.
 *
 * @return int
 */
int FileManager::removeFile() {
    std::cout << this->fileName << std::endl;
    if (unlink(this->fileName.c_str()) == -1) {
        std::cerr << "Error: File could not be deleted." << std::endl;
        this->errorNumber = (int) ENOENT;

        return this->errorNumber;
    } else {
//        // Reset attributes of this object
//        this->fileName = nullptr;
        this->fileType = 0;
        this->fileSize = 0;
        this->ownerId = 0;
//        this->ownerName = nullptr;
        this->groupId = 0;
//        this->groupName = nullptr;
        this->filePermissions = 0;
//        this->lastAccess = 0;
//        this->lastModification = 0;
//        this->lastStatusChange = 0;
        this->blockSize = 0;
        this->errorNumber = 0;
        this->errorNumber = 0;

        return this->errorNumber;
    }
}

/**
 * compareFile()
 * Takes another one of the file objects as a parameter and will compare the contents of the file object this function
 * was invoked upon to this other file object.
 *
 * @param FileManager fileManager
 * @return bool
 */
bool FileManager::compareFile(FileManager &fileManager) {
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

/**
 * expand()
 * Operates on directories only and is used to fill in the children of the file object this function was invoked upon.
 *
 * @return int
 */
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

        return this->errorNumber;
    }
}
