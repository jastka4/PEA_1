#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class Graph
{
public:
	Graph();
	Graph(int, bool);
	virtual ~Graph();

	void print();
	void addEdge(int, int, int);
	void removeEdge(int, int);
	int getVertexCount() const;
	int getPathWeight(int start, int end);

protected:
	int vertexCount;
	int edgesCount;
	bool isDirected;
	int **matrix;
};
