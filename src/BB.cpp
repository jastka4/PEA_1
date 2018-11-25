//
// Created by jastka4 on 03.11.18.
//

#include "BB.h"
#include <climits> //int max

BB::~BB() {
    delete[] visited;
}

// Function to find the minimum edge cost
// having an end at the vertex i
int BB::firstMin(Graph *graph, int i)
{
    int min = INT_MAX;
    for (int k=0; k < graph->getVertexCount(); k++)
        if (graph->getPathWeight(i, k)<min && i != k)
            min = graph->getPathWeight(i, k);
    return min;
}

// function to find the second minimum edge cost
// having an end at the vertex i
int BB::secondMin(Graph *graph, int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j < graph->getVertexCount(); j++)
    {
        if (i == j)
            continue;

        if (graph->getPathWeight(i, j) <= first)
        {
            second = first;
            first = graph->getPathWeight(i,j);
        }
        else if (graph->getPathWeight(i, j) <= second &&
                graph->getPathWeight(i, j) != first)
            second = graph->getPathWeight(i, j);
    }
    return second;
}

// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//         space tree
// curr_path -> where the solution is being stored which
//                would later be copied to final_path
void BB::TSPRec(Graph *graph, int curr_bound, int curr_weight,
            int level, int *curr_path)
{
    // base case is when we have reached level N which
    // means we have covered all the nodes once
    if (level == graph->getVertexCount())
    {
        // check if there is an edge from last vertex in
        // path back to the first vertex
        if (graph->getPathWeight(curr_path[level-1], curr_path[0]) != 0)
        {
            // curr_res has the total weight of the
            // solution we got
            int curr_res = curr_weight +
                    graph->getPathWeight(curr_path[level-1], curr_path[0]);

            // Update final result and final path if
            // current result is better.
            if (curr_res < final_res)
            {
                final_path = new int[graph->getVertexCount() + 1];
                for (int i = 0; i < graph->getVertexCount(); i++)
                    final_path[i] = (curr_path)[i];
                final_path[graph->getVertexCount()] = curr_path[0];
                final_res = curr_res;
            }
        }
        return;
    }

    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (int i = 0; i < graph->getVertexCount(); i++)
    {
        // Consider next vertex if it is not same (diagonal
        // entry in adjacency matrix and not visited
        // already)
        if (graph->getPathWeight(curr_path[level-1], i) != 0 &&
            visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += graph->getPathWeight(curr_path[level-1], i);

            // different computation of curr_bound for
            // level 2 from the other levels
            if (level==1)
                curr_bound -= ((firstMin(graph, curr_path[level-1]) +
                                firstMin(graph, i))/2);
            else
                curr_bound -= ((secondMin(graph, curr_path[level-1]) +
                                firstMin(graph, i))/2);

            // curr_bound + curr_weight is the actual lower bound
            // for the node that we have arrived on
            // If current lower bound < final_res, we need to explore
            // the node further
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;

                // call TSPRec for the next level
                TSPRec(graph, curr_bound, curr_weight, level+1,
                       curr_path);
            }

            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound
            curr_weight -= graph->getPathWeight(curr_path[level-1], i);
            curr_bound = temp;

            // Also reset the visited array
            for (int j = 0; j < graph->getVertexCount(); ++j) {
                visited[j] = false;
            }
            for (int j = 0; j <= level-1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

// This function sets up final_path
int BB::getShortestRoute(Graph *graph, int start)
{
    final_res = INT_MAX;
    path_size = graph->getVertexCount() + 1;
    final_path = new int[path_size];

    visited = new bool(graph->getVertexCount());
    for (int i = 0; i < graph->getVertexCount(); ++i) {
        visited[i] = 0;
    }

    int curr_path[graph->getVertexCount() + 1];
    for (int i = 0; i < graph->getVertexCount() + 1; ++i)
    {
        curr_path[i] = -1;
    }

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;

    // Compute initial bound
    for (int i = 0; i < graph->getVertexCount(); i++)
        curr_bound += (firstMin(graph, i) +
                       secondMin(graph, i));

    // Rounding off the lower bound to an integer
    curr_bound = (curr_bound&1)? curr_bound/2 + 1 :
                 curr_bound/2;

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited[start] = true;
    curr_path[0] = start;

    // Call to TSPRec for curr_weight equal to
    // 0 and level 1
    TSPRec(graph, curr_bound, 0, 1, curr_path);

    return final_res;
}
