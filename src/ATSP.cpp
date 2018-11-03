//
// Created by jastka4 on 03.11.18.
//

#include "ATSP.h"
#include <bits/stdc++.h> //int max

// implementation of traveling Salesman Problem
int ATSP::getShortestRoute(int graph[][6], int s)
{
    // store all vertex apart from source vertex
    Array *vertex = new Array();
    for (int i = 0; i < 6; i++)
    {
        if (i != s)
        {
            vertex->insertAtEnd(i);
        }
    }

    vertex->display();

    std::vector<int*> permutations;
    std::vector<int*> *permutations_ptr = &permutations;
    permutation(vertex->getArray(), 0, vertex->getSize() - 1, permutations_ptr);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
        // store current Path weight(cost)
        int current_pathweight = 0;
        vertex->setArray(permutations.back());
        permutations.pop_back();

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex->getSize(); i++)
        {
            current_pathweight += graph[k][vertex->get(i)];
            k = vertex->get(i);
            std::cout << "K: " << k << " S: " << s << std::endl;
        }
        //std::cout << graph[k][s] << std::endl;
        current_pathweight += graph[k][s];

        // update minimum
        min_path = std::min(min_path, current_pathweight);
    } while (permutations.size() != 0);

    return min_path;
}

void ATSP::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//int** ATSP::permutation(int *array, int start, int end)
//{
//    int number_of_permutations = 1;
//    for (int i = 1; i <= end - start + 1 ; i++)  number_of_permutations *= i;
//
//    int **permutations = new int*[number_of_permutations];
//
//    std::cout << "perms: " << number_of_permutations << std::endl;
//
//    permutation(array, start, end, permutations);
//    for (int j = 0; j <  number_of_permutations; j++) {
//        for (int i = 0; i < end-start; i++) {
//            std:: cout << "perm[" << j << "][" << i << "] = " << permutations[j][i] << std::endl;
//        }
//    }
//}

void ATSP::permutation(int *array, int start, int end, std::vector<int*> *permutations)
{
    if (start == end)
    {
        int *permutation = new int[end - start];
        for (int i = 0; i <= end; ++i)
        {
            permutation[i] = array[i];
            std::cout << array[i] << "";
        }
        std::cout << std::endl;
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
