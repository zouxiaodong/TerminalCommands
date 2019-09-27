#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

class FileManager {
private:
    std::string fileName;
    int errorNumber;
public:
    FileManager(const std::string& fileName);
    void getFileName();
    int getErrorNumber();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
