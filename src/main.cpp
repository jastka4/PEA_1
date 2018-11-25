//
// Created by jastka4 on 03.11.18.
//

#include "BF.h"
#include "../include/Timer.h"
#include "BB.h"
#include "../include/FileHandler.h"
#include "DP.h"

using namespace std;

int main()
{
    ATSP *bf = new BF();
    ATSP *bb = new BB();
    DP *dp = new DP();

    Timer *timer = new Timer();
    FileHandler *fileHandler = new FileHandler();

    fileHandler->getInitialFile();
    Graph *graph = fileHandler->loadFromFile();

    int start = 0;
    timer->start();
    cout << bf->getShortestRoute(graph, start) << endl;
    timer->stop();
    bf->printFinalPath();
    std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;

    timer->start();
    cout << bb->getShortestRoute(graph, start) << endl;
    timer->stop();
    bb->printFinalPath();
    std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;

    timer->start();
    cout << dp->getShortestRoute(graph, start) << endl;
    timer->stop();
    dp->printFinalPath();
    std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;

    return 0;
}