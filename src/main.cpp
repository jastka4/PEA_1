//
// Created by jastka4 on 03.11.18.
//

#include "ATSP.h"
#include "../include/Graph.h"
#include <iostream>

using namespace std;

int main()
{
    ATSP *atsp = new ATSP();

    // matrix representation of graph
//    { 0, 10, 15, 20 }
//    { 10, 0, 35, 25 }
//    { 15, 35, 0, 30 }
//    { 20, 25, 30, 0 }

    Graph *graph = new Graph(4, false);
    graph->addEdge(0, 1, 10);
    graph->addEdge(0, 2, 15);
    graph->addEdge(0, 3, 20);

    graph->addEdge(1, 0, 10);
    graph->addEdge(1, 2, 35);
    graph->addEdge(1, 3, 25);

    graph->addEdge(2, 0, 15);
    graph->addEdge(2, 1, 35);
    graph->addEdge(2, 3, 30);

    graph->addEdge(3, 0, 20);
    graph->addEdge(3, 1, 25);
    graph->addEdge(3, 2, 30);

    int start = 0;
    cout << atsp->getShortestRoute(graph, start) << endl;
    return 0;
}