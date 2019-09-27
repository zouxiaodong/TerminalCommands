#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

class FileManager {
private:
    std::string fileName;
    mode_t fileType;
    off_t fileSize;
    uid_t ownerId;
    char *ownerName;
    int errorNumber;
public:
    FileManager(const std::string& fileName);
    void getFileName();
    mode_t getFileType();
    off_t getFileSize();
    uid_t getOwnerId();
    const char * getOwnerName();
    int getErrorNumber();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
