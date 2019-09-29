#include <iostream>
#include "include/Individual_Assignment/FileManager.h"
#include <fstream>

int main() {
    // Test FileManager

    // Create new instance of FileManager
    // File name should be relative to the FileManager.cpp file (i.e. beginning with '../test-files/')
    FileManager fileManager1 = FileManager("../test-files/file1.txt");
    FileManager fileManager3 = FileManager("../test-files/file3.txt");
//    FileManager fileManager4 = FileManager("../test-files/file4.txt");

//    // Test getFileType()
//    std::cout << "File Name:" << std::endl;
//    std::cout << fileManager1.getFileName() << std::endl;
//    std::cout << fileManager3.getFileName() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getFileType()
//    std::cout << "File Type:" << std::endl;
//    std::cout << fileManager1.getFileType() << std::endl;
//    std::cout << fileManager3.getFileType() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getFileSize()
//    std::cout << "File Size:" << std::endl;
//    std::cout << fileManager1.getFileSize() << std::endl;
//    std::cout << fileManager3.getFileSize() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getOwnerId()
//    std::cout << "Owner ID:" << std::endl;
//    std::cout << fileManager1.getOwnerId() << std::endl;
//    std::cout << fileManager3.getOwnerId() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getOwnerName()
//    std::cout << "Owner Name:" << std::endl;
//    std::cout << fileManager1.getOwnerName() << std::endl;
//    std::cout << fileManager3.getOwnerName() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getGroupId()
//    std::cout << "Group ID:" << std::endl;
//    std::cout << fileManager1.getGroupId() << std::endl;
//    std::cout << fileManager3.getGroupId() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getGroupName()
//    std::cout << "Group Name:" << std::endl;
//    std::cout << fileManager1.getGroupName() << std::endl;
//    std::cout << fileManager3.getGroupName() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getFilePermissions()
//    std::cout << "File Permissions:" << std::endl;
//    std::cout << fileManager1.getFilePermissions() << std::endl;
//    std::cout << fileManager3.getFilePermissions() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getLastAccess()
//    std::cout << "Last Access:" << std::endl;
//    printf("%d\n", fileManager1.getLastStatusChange());
//    printf("%d\n", fileManager3.getLastStatusChange());
//    std::cout << "" << std::endl;
//
//    // Test getLastModification()
//    std::cout << "Last Modification:" << std::endl;
//    printf("%d\n", fileManager1.getLastStatusChange());
//    printf("%d\n", fileManager3.getLastStatusChange());
//    std::cout << "" << std::endl;
//
//    // Test getLastStatusChange()
//    std::cout << "Last Status Change:" << std::endl;
//    printf("%d\n", fileManager1.getLastStatusChange());
//    printf("%d\n", fileManager3.getLastStatusChange());
//    std::cout << "" << std::endl;
//
//    // Test getBlockSize()
//    std::cout << "Block Size:" << std::endl;
//    std::cout << fileManager1.getBlockSize() << std::endl;
//    std::cout << fileManager3.getBlockSize() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test getErrorNumber
//    std::cout << "Error Number:" << std::endl;
//    std::cout << fileManager1.getErrorNumber() << std::endl;
//    std::cout << fileManager3.getErrorNumber() << std::endl;
//    std::cout << "" << std::endl;
//
//    // Test dump()
//    // Create instance of ofstream
//    std::ofstream outFile1("../test-files/outfile1.txt");
//    std::ofstream outFile2("../test-files/outfile3.txt");
//    // Copy file contents into helloWorld.txt file stream
//    fileManager1.dump(outFile1);
//    fileManager3.dump(outFile2);
//
//    // Test renameFile()
//    std::string newFileName = "../test-files/newfile1.txt";
//    fileManager1.renameFile(newFileName);

    // Test removeFile()
//    fileManager4.removeFile();

    return 0;
}