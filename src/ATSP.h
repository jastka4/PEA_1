//
// Created by jskalska on 12/11/2018.
//

#pragma once

#include "../include/Graph.h"

class ATSP
{
public:
    virtual int getShortestRoute(Graph *graph, int start) = 0;

    virtual void printFinalPath()
    {
        // print min path
        for (size_t i = 0; i < path_size; ++i)
        {
            std::cout << final_path[i];

            if (i < path_size - 1)
            {
                std::cout << " - ";
            }
        }
        std::cout << std::endl;
    }

    virtual ~ATSP()
    {
        delete[] final_path;
    }

protected:
    int *final_path;
    int path_size;
};
