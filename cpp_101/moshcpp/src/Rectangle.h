#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<string>
using namespace std;

#pragma once

class Rectangle {
  public:


    Rectangle();
    Rectangle(const Rectangle& source) = delete;
    Rectangle(int width, int height);
    Rectangle(int width, int height, const string& color);
    ~Rectangle();

    void draw() const;
    int getArea() const ;
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    int getObjectsCount();

  private:
    int width = 0;
    int height = 0;
    string color;

    static int objectsCount;
};

#endif