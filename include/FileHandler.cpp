//
// Created by jskalska on 23/11/2018.
//

#include "FileHandler.h"

bool FileHandler::getInputFile()
{
    system("clear");
    std::cout << "Name of the file with input data: ";
    std::cin >> inputData;

    inputFile.open("../data/" + inputData);

    if (!inputFile.is_open())
        throw FileNotFoundException("The file could not be opened", inputData.c_str());

    return true;
}

void FileHandler::getInitialFile()
{
    bool success = false;

    do
    {
        try
        {
            success = getInputFile();
        }
        catch (FileNotFoundException ex)
        {
            char key;
            std::cout << ex.what() << ": " << ex.getFile() << std::endl;
            std::cout << "Press a key to try again..." << std::endl;
            std::cin >> key;

            if (key == 'q')
                return;
        }
    } while (!success);
}

bool FileHandler::getOutputFile(std::string mainFolder)
{
    std::cout << "Name of the output file: ";
    std::cin >> outputData;

    outputFile.open("./output/" + mainFolder + "/" + outputData);

    if (!outputFile.is_open())
        throw FileNotFoundException("The file could not be created", outputData.c_str());

    return true;
}

void FileHandler::getUserInput(int &input, std::string type)
{
    std::cout << "Enter a " + type + ": ";
    std::cin >> input;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        std::cout << "Bad entry. Enter a NUMBER: ";
        std::cin >> input;
    }
}

Graph* FileHandler::loadFromFile()
{
    int dimension, startVertex, endVertex, vertexWeight;
    Graph* graph;

    if (inputFile.good())
    {
        inputFile >> dimension;
        graph = new Graph(dimension, false);

        startVertex = 1;
        endVertex = 1;

        while (inputFile >> vertexWeight)
        {
            if (vertexWeight == -1) vertexWeight = 0;
            graph->addEdge(startVertex - 1, endVertex - 1, vertexWeight);
            if (endVertex % dimension == 0)
            {
                startVertex++;
                endVertex = 0;
            }
            endVertex++;
        }
    }

    inputFile.close();
    return graph;
}