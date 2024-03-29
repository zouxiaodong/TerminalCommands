#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

#include <vector>

class FileManager {
private:
    std::string fileName;
    mode_t fileType;
    off_t fileSize;
    uid_t ownerId;
    char *ownerName;
    gid_t groupId;
    char *groupName;
    mode_t filePermissions;
    timespec lastAccess;
    timespec lastModification;
    timespec lastStatusChange;
    blksize_t blockSize;
    std::vector<FileManager> children;
    int errorNumber;
public:
    FileManager(const std::string &fileName);

    ~FileManager();

    std::string getFileName();

    mode_t getFileType();

    off_t getFileSize();

    uid_t getOwnerId();

    const char *getOwnerName();

    gid_t getGroupId();

    const char *getGroupName();

    mode_t getFilePermissions();

    timespec getLastAccess();

    timespec getLastModification();

    timespec getLastStatusChange();

    blksize_t getBlockSize();

    std::vector<FileManager> getChildren();

    int getErrorNumber();

    void setFileName(std::string &newName);

    int dump(std::ofstream &outFile);

    int renameFile(std::string &newName);

    int removeFile();

    bool compareFile(FileManager &fileManager);

    int expand();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
