//
// Created by jskalska on 25/11/2018.
//

#pragma once

#include "ATSP.h"
#include <vector>
#include <iostream>
#include <climits> //int max

class DP: public ATSP
{
public:
    int getShortestRoute(Graph *graph, int start);
    void printFinalPath() override;

private:
    std::vector<std::vector<int>> state;

    int tsp(Graph* graph, int pos, int visited);
};
