#ifndef INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
#define INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H

class FileManager {
private:
    std::string fileName;
public:
    FileManager(const std::string& fileName);
    void getFileName();
};

#endif //INDIVIDUAL_ASSIGNMENT_FILEMANAGER_H
