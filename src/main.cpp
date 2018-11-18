//
// Created by jastka4 on 03.11.18.
//

#include "BF.h"
#include "../include/Timer.h"
#include "BB.h"

using namespace std;

int main()
{
    ATSP *atsp = new BF();
    ATSP *test = new BB();
    Timer *timer = new Timer();

    // matrix representation of graph
//    { 0, 10, 15, 20 }
//    { 10, 0, 35, 25 }
//    { 15, 35, 0, 30 }
//    { 20, 25, 30, 0 }

/*    Graph *graph = new Graph(4, false);
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
    graph->addEdge(3, 2, 30);*/

//    { 0, 20, 30, 31, 28, 40 }
//    { 30, 0, 10, 14, 20, 44 }
//    { 40, 20, 0, 10, 22, 50 }
//    { 41, 24, 20, 0, 14, 42 }
//    { 38, 30, 32, 24, 0, 28 }
//    { 50, 54, 60, 52, 38, 0 }

    Graph *graph = new Graph(6, false);

    graph->addEdge(0, 1, 20);
    graph->addEdge(0, 2, 30);
    graph->addEdge(0, 3, 31);
    graph->addEdge(0, 4, 28);
    graph->addEdge(0, 5, 40);

    graph->addEdge(1, 0, 30);
    graph->addEdge(1, 2, 10);
    graph->addEdge(1, 3, 14);
    graph->addEdge(1, 4, 20);
    graph->addEdge(1, 5, 44);

    graph->addEdge(2, 0, 40);
    graph->addEdge(2, 1, 20);
    graph->addEdge(2, 3, 10);
    graph->addEdge(2, 4, 22);
    graph->addEdge(2, 5, 50);

    graph->addEdge(3, 0, 41);
    graph->addEdge(3, 1, 24);
    graph->addEdge(3, 2, 20);
    graph->addEdge(3, 4, 14);
    graph->addEdge(3, 5, 42);

    graph->addEdge(4, 0, 38);
    graph->addEdge(4, 1, 30);
    graph->addEdge(4, 2, 32);
    graph->addEdge(4, 3, 24);
    graph->addEdge(4, 5, 28);

    graph->addEdge(5, 0, 50);
    graph->addEdge(5, 1, 54);
    graph->addEdge(5, 2, 60);
    graph->addEdge(5, 3, 52);
    graph->addEdge(5, 4, 38);

    int start = 0;
    timer->start();
    cout << atsp->getShortestRoute(graph, start) << endl;
    timer->stop();
    atsp->printFinalPath();
    std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;

    cout << test->getShortestRoute(graph, start) << endl;
    timer->stop();
    test->printFinalPath();
    std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;

    return 0;
}