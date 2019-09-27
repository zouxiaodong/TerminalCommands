#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

class FileManager {
private:
    std::string fileName;
    mode_t fileType;
    int errorNumber;
public:
    FileManager(const std::string& fileName);
    void getFileName();
    mode_t getFileType();
    int getErrorNumber();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
