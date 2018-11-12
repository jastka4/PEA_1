#include "Graph.h"

Graph::Graph(int vertexCount, bool isDirected)
    : edgesCount(0), vertexCount(vertexCount), isDirected(isDirected)
{
    adjacencyList = new Node*[vertexCount];

    for (int i = 0; i < vertexCount; i++)
        adjacencyList[i] = nullptr;
}

Graph::~Graph()
{
    for (int i = 0; i < vertexCount; i++)
        delete adjacencyList[i];

    delete[] adjacencyList;
}


void Graph::print()
{
    Node* node;

    std::cout << "\nList representation:" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < vertexCount; i++)
    {
        std::cout << "[" << i << "] =";
        node = adjacencyList[i];

        while (node)
        {
            std::cout << std::setw(3) << node->vertex;
            node = node->next;
        }
        std::cout << std::endl;
    }
}

void Graph::addEdge(int origin, int destination, int weight)
{
    Node* newNode = new Node();
    newNode->vertex = destination;
    newNode->weight = weight;
    newNode->next = adjacencyList[origin];
    adjacencyList[origin] = newNode;

    if (!isDirected)
    {
        newNode = new Node();
        newNode->vertex = origin;
        newNode->weight = weight;
        newNode->next = adjacencyList[destination];
        adjacencyList[destination] = newNode;
    }

    edgesCount++;
}

int Graph::getPathWeight(int i, int j)
{
    return adjacencyList[i][j].weight;
}

int Graph::getVertexCount() const
{
    return vertexCount;
}
