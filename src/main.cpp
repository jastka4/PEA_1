//
// Created by jastka4 on 03.11.18.
//

#include "../include/Array.h"
#include "ATSP.h"
#include <iostream>

#define V 6
using namespace std;

int main()
{
//    Array *array = new Array();
//    array->insertAtBeginning(10);
//    array->display();
//    string message = "Hello World";
//    cout << message << endl;

    ATSP *atsp = new ATSP();

    // matrix representation of graph
    int graph[][V] = { { 0, 20, 30, 31, 28, 40 },
                       { 30, 0, 10, 14, 20, 44 },
                       { 40, 20, 0, 10, 22, 50 },
                       { 41, 24, 20, 0, 14, 42 },
                       { 38, 30, 32, 24, 0, 28 },
                       { 50, 54, 60, 52, 38, 0} };
    int s = 0;
    cout << atsp->getShortestRoute(graph, s) << endl;
    return 0;
}