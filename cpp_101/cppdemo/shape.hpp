#ifndef shape_hpp
#define shape_hpp

#include <stdio.h>

enum class shape_type
{
  Circle,
  Triangle,
  Rectangle
};

class Shape
{
public:
    virtual ~Shape() {};
};

class Circle : public Shape
{
public:
//    Circle() { puts("Circle"); };
//    ~Circle() { puts("~Circle"); };
};

class Triangle : public Shape
{
public:
    Triangle() { puts("Triangle"); };
    ~Triangle() { puts("~Triangle"); };
};

class Rectangle : public Shape
{
public:
    Rectangle() { puts("Rectangle"); };
    ~Rectangle() { puts("~Rectangle"); };
};

class ShapeWrapper {
public:
    explicit ShapeWrapper(
        Shape *ptr = nullptr) : ptr_(ptr) {};
    ~ShapeWrapper() { delete ptr_;  };

    Shape *get() const { return ptr_; };

private:
    Shape *ptr_;
};

Shape *create_shape(shape_type type);

void foo();

#endif /* shape_hpp */
