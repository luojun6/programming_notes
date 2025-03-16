#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

#pragma once

class Array
{
public:
    explicit Array(size_t size);
    ~Array();
    int& operator[](size_t index);

private:
    int* values;
    size_t size;
};

#endif