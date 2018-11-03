//
// Created by jastka4 on 03.11.18.
//

#include "Array.h"

Array::Array()
{
    size = 0;
    array = nullptr;
}

Array::~Array()
{
    delete[] array;
    size = 0;
}

void Array::relocate(size_t newSize)
{
    int* temp = new int[newSize];
    if (newSize >= size)
    {
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
    }
    else
    {
        for (size_t i = 0; i < newSize; i++)
        {
            temp[i] = array[i];
        }
    }
    delete array;
    array = temp;
}

void Array::insertAtBeginning(int data)
{
    relocate(size + 1);
    size++;
    for (size_t i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = data;
}

void Array::insertAtEnd(int data)
{
    relocate(size + 1);
    array[++size - 1] = data;
}

void Array::insert(size_t index, int data)
{
    if (index >= size)
    {
        throw IndexOutOfBoundsException("Index is bigger than the size");
    }
    else
    {
        relocate(size + 1);
        size++;
        for (size_t i = size - 1; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = data;
    }
}

int Array::get(size_t index)
{
    return array[index];
}

int Array::getBeginning()
{
    return array[0];
}

int Array::getEnd()
{
    return array[size - 1];
}

void Array::remove(size_t index)
{
    if (size == 0)
        throw IndexOutOfBoundsException("Array is empty");
    else if (index >= size)
    {
        throw IndexOutOfBoundsException("Index is bigger than the size");
    }
    else
    {
        for (size_t i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        relocate(size - 1);
        size--;
    }
}

void Array::removeAtBeginning()
{
    if (size == 0)
        throw IndexOutOfBoundsException("Array is empty");
    else
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        relocate(size - 1);
        size--;
    }
}

void Array::removeAtEnd()
{
    if (size == 0)
        throw IndexOutOfBoundsException("Array is empty");
    else
    {
        array[size - 1] = 0;
        relocate(size - 1);
        size--;
    }
}

size_t Array::find(int data)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == data)
            return i;
    }
    return -1;
}

void Array::display()
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "[Index: " << i << " Value: " << array[i] << "]";
        if (i != size - 1)
            std::cout << "\n";
    }
    std::cout << std::endl;
}

size_t Array::getSize()
{
    return size;
}

int* Array::getArray()
{
    return array;
}

void Array::setArray(int *array)
{
    this->array = array;
}