//
// Created by jskalska on 23/11/2018.
//

#pragma once
#include "FileNotFoundException.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>

class FileHandler
{
protected:
    std::string inputData, outputData;

    std::ofstream outputFile;
    std::ifstream inputFile;

    bool getInputFile();
    bool getOutputFile(std::string);

public:
    void getUserInput(int&, std::string);
    void getInputOutputFiles(std::string);
    void getInitialFile();
    Graph* loadFromFile();
};
