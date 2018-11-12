//
// Created by jskalska on 12/11/2018.
//

#pragma once
#include <iostream>
#include <chrono>

class Timer
{
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
public:
    void start();
    void stop();
    int64_t getTime();
};
