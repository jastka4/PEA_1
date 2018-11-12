#include "Graph.h"

Graph::Graph(int vertexCount, bool isDirected)
    : edgesCount(0), vertexCount(vertexCount), isDirected(isDirected)
{
    matrix = new int*[vertexCount];

    for (size_t i = 0; i < vertexCount; i++)
    {
        matrix[i] = new int[vertexCount];

        for (size_t j = 0; j < vertexCount; j++)
            matrix[i][j] = 0;
    }
}

Graph::~Graph()
{
    for (size_t i = 0; i < vertexCount; i++)
        delete[] matrix[i];

    delete[] matrix;
}


void Graph::print()
{
    std::cout << "Incidence matrix representation: " << std::endl;

    size_t i, j;

    for (i = 0; i < vertexCount; i++)
    {
        for (j = 0; j < vertexCount; j++)
            std::cout << std::setw(4) << matrix[i][j] << "  ";

        std::cout << std::endl;
    }
}

void Graph::addEdge(int origin, int destination, int weight)
{
    if (origin >= 0 && origin < vertexCount && destination >= 0 && destination < vertexCount)
    {
        matrix[origin][destination] = 1 * weight;
//        if (isDirected)
//            matrix[destination][origin] = -1 * weight;
//        else
//            matrix[destination][origin] = 1 * weight;

        edgesCount++;
    }
    // else throws error
}

int Graph::getPathWeight(int i, int j)
{
    return matrix[i][j];
}

int Graph::getVertexCount() const
{
    return vertexCount;
}
