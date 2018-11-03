//
// Created by jastka4 on 03.11.18.
//

#pragma once

#include "../include/Array.h"
#include <vector>

class ATSP
        {
public:
    int getShortestRoute(int[][6], int);

private:
    void swap(int*, int*);
    void permutation(int *array, int start, int end, std::vector<int*> *permutations);
};