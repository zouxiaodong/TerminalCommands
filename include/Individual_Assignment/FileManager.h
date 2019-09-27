#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

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
    int errorNumber;
public:
    FileManager(const std::string& fileName);
    void getFileName();
    mode_t getFileType();
    off_t getFileSize();
    uid_t getOwnerId();
    const char * getOwnerName();
    gid_t getGroupId();
    const char *getGroupName();
    mode_t getFilePermissions();
    timespec getLastAccess();
    int getErrorNumber();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
