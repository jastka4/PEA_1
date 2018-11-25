//
// Created by jskalska on 12/11/2018.
//

#pragma once

#include "ATSP.h"

class BB : public ATSP
{
public:
    int getShortestRoute(Graph *graph, int start);
    virtual ~BB();

private:
    bool *visited;
    int final_res;

    int firstMin(Graph *graph, int i);
    int secondMin(Graph *graph, int i);
    void TSPRec(Graph *graph, int curr_bound, int curr_weight, int level, int *curr_path);

};
