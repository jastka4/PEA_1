//
// Created by jskalska on 12/11/2018.
//

#include "Timer.h"

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
    endTime = std::chrono::high_resolution_clock::now();
}

int64_t Timer::getTime()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}