//
// Created by jastka4 on 03.11.18.
//

#pragma once

#include "../include/Array.h"
#include "../include/Graph.h"
#include <vector>

class ATSP
        {
public:
    int getShortestRoute(Graph *graph, int start);

private:
    void swap(int* a, int* b);
    void permutation(int *array, int start, int end, std::vector<int*> *permutations);
};