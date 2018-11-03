//
// Created by jastka4 on 03.11.18.
//

#pragma once
#include "IndexOutOfBoundsException.h"
#include <iostream>

class Array
{
    size_t size;
    int *array;
    void relocate(size_t);
public:
    Array();
    ~Array();

    void insert(size_t, int);
    void insertAtBeginning(int);
    void insertAtEnd(int);
    int get(size_t);
    int getBeginning();
    int getEnd();
    void remove(size_t);
    void removeAtBeginning();
    void removeAtEnd();
    size_t find(int);
    void display();

    size_t getSize();
    int* getArray();
    void setArray(int*);
};

