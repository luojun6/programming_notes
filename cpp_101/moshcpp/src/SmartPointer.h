#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#pragma once

class SmartPointer
{
public:
    explicit SmartPointer(int *ptr);
    ~SmartPointer();
    int& operator*();

private:
    int* ptr;
};

#endif