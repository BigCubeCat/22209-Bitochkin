#ifndef CMDMANAGER_H
#define CMDMANAGER_H

#include <iostream>

typedef enum {
    GUI, CLI
} Mode;

class CmdManager {
private:
    Mode mode = GUI;
    std::string inputFile;
    std::string outputFile;
    std::string name;
    size_t countGeneration = 0; // For CLI mode

    void parseFile();
public:
    CmdManager(int argc, char *argv[]);
    void readFromFile(std::string fileName);
    std::string getName();
};

#endif
