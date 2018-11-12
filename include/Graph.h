#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class Graph
{
protected:
    int vertexCount;
    int edgesCount;
    bool isDirected;
    Node** adjacencyList;

public:
    Graph();
    Graph(int, bool);
    virtual ~Graph();

    void print();
    void addEdge(int, int, int);
    int getPathWeight(int, int);
    int getVertexCount() const;
};