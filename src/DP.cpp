//
// Created by jskalska on 25/11/2018.
//

#include "DP.h"

/**
    \brief Given a complete, undirected, weighted graph in the form of an adjacency matrix,
           returns the smallest tour that visits all nodes and starts and ends at the same
           node. This dynamic programming solution runs in O(n * 2^n).
    \return the minimum cost to complete the tour
*/

int DP::getShortestRoute(Graph *graph, int start)
{
    final_path = new int[graph->getVertexCount() + 1];
    path_size = graph->getVertexCount() + 1;

    state = std::vector<std::vector<int>>(graph->getVertexCount());
    for (int i = 0; i < graph->getVertexCount(); ++i)
    {
        state[i] = std::vector<int>((1 << state.size()) - 1, INT_MAX);
    }

    int test = tsp(graph, start, 1);
    return test;
}

int DP::tsp(Graph *graph, int start, int visited)
{
    if (visited == ((1 << graph->getVertexCount()) - 1))
    {
        return graph->getPathWeight(start, 0); // return to starting city
    }

    if (state[start][visited] != INT_MAX)
    {
        return state[start][visited];
    }

    for (int i = 0; i < graph->getVertexCount(); ++i)
    {
        // can't visit ourselves unless we're ending & skip if already visited
        if(i == start || (visited & (1 << i)))
        {
            continue;
        }

        int distance = graph->getPathWeight(start, i) + tsp(graph, i, visited | (1 << i));
        if(distance < state[start][visited])
        {
            state[start][visited] = distance;
        }
    }

    return state[start][visited];
}

void DP::printFinalPath()
{
    for (int i = 0; i < state.size(); ++i)
    {
        int temp = INT_MAX;
        for (int j = 0; j < ((1 << state.size()) - 1); ++j)
        {
            if (state[i][j] != INT_MAX && temp > state[i][j])
            {
                temp = state[i][j];
            }
        }
        final_path[i] = temp;
    }

    ATSP::printFinalPath();
}
