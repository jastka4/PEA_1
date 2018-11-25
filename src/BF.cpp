//
// Created by jastka4 on 03.11.18.
//

#include "BF.h"
#include <climits> //int max

// implementation of traveling Salesman Problem (Brute Force algorithm)
int BF::getShortestRoute(Graph *graph, int start)
{
    // store all vertex apart from source vertex
    Array *vertex = new Array();

    for (int i = 0; i < graph->getVertexCount(); i++)
    {
        if (i != start)
        {
            vertex->insertAtEnd(i);
        }
    }

    path_size = graph->getVertexCount() + 1;
    final_path = new int[path_size];

    std::vector<int*> permutations;
    permutation(vertex->getArray(), 0, vertex->getSize() - 1, &permutations);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    while (permutations.size() > 0) {
        // store current Path weight(cost)
        int current_pathweight = 0;
        vertex->setArray(permutations.back());
        permutations.pop_back();

        // compute current path weight
        int k = start;
        final_path[0] = start;
        for (int i = 0; i < vertex->getSize(); i++)
        {
            current_pathweight += graph->getPathWeight(k, vertex->get(i));
            k = vertex->get(i);
        }
        current_pathweight += graph->getPathWeight(k, start);

        // update minimum
        if (min_path > current_pathweight)
        {
            min_path = current_pathweight;
            for (int i = 0; i < vertex->getSize(); i++)
            {
                k = vertex->get(i);
                final_path[i + 1] = k;
            }
            final_path[vertex->getSize() + 1] = start;
        }
    }

    delete vertex;

    return min_path;
}

void BF::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BF::permutation(int *array, int start, int end, std::vector<int*> *permutations)
{
    if (start == end)
    {
        int *permutation = new int[end + 1];
        for (int i = 0; i <= end; ++i)
        {
            permutation[i] = array[i];
        }
        (*permutations).push_back(permutation);
        return;

    }
    for (int i = start; i <= end ; i++)
    {
        swap((array + i), (array + start));
        permutation(array, start + 1, end, permutations);
        swap((array + i), (array + start));
    }
}
