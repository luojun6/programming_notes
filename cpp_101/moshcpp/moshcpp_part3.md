# CodeWithMosh C++ - Part 3

## 1 Classes

### 1.1 What is Object-oriented Programming?

Why shall we learn the object-oriented programming, well, just like we have different ways to bake a cake. We also have different ways to write software. These are called programming paradigms.

![classes_0](./images/classes_0.png)

So a programming paradigm is a way of writing software, now we have many differnt programming paradigms, procedural, **Functional**, **Object-oriented**, even-driven, ... and many many more.

![classes_1](./images/classes_1.png)

Out of these, **Functional** and **Object-oriented** programming are the 2 most popular paradigms these days. With each paradigm, we think of building software in a different way.

For example, in **Functional** programming, we build software by creating and composing functions. In **Object-oriented** programming, we write software by creating objects rather than functions.

![classes_2](./images/classes_2.png)

Now each paradigm has its pros and cons, and should be used to solve certain problems. So there is no such a thing as the best program in paradigm. Just like there is no best way to bake a cake.

![classes_3](./images/classes_3.png)

In a real application, we can use multiple paradigms to solve different kinds of problems. So these paradigms are not mutually exclusive.

In **Object-oriented** programming, we build applications in terms of objects that work together to solve a problem. Each object has a clear responsibility.

![classes_4](./images/classes_4.png)

An object is a software entity or a building block that contains some attributes or properties as well as some functions or methods.

![classes_5](./images/classes_5.png)

A good example is a dialog box, a dialog box has attributes like size and posiiton on the screen, as well as funcitons like show height resize and move.

![classes_6](./images/classes_6.png)

But objects are not always about viusal things, in a real application, we have tons of objects that power the user interface, we have objects for

- storing and retrieving data
- sending emails and notifications
- performing computations

Now to create an object we need a class, a class is a blueprint or a recipe for creating objects, so just like we can use a recipe to bake many cakes of the same kind.

![classes_7](./images/classes_7.png)

We can use a class to create many objects of the same type.

**UML**

![classes_8](./images/classes_8.png)

These variables and functions are called the **members** of the class.

Quite often we use structures as simple data containers, and classes for creating objects that can do things.

![classes_9](./images/classes_9.png)

So a class combines data and functions that operate on the data together, this is one of the core principles of object oriented programming, and is called **encapsulation**.

![classes_10](./images/classes_10.png)

### 1.2 Defining a Class

![classes_11](./images/classes_11.png)

**Rectangle.h**

```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

class Rectangle
{
public:
    Rectangle();
    ~Rectangle();

    int width;
    int height;
    void draw();
    int getArea();

private:

};

#endif
```

**Rectangle.cpp**

```cpp
#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::draw()
{
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions: " << width << ", " << height << endl;
}

int Rectangle::getArea()
{
    return width * height;
}
```

### 1.3 Creating Objects

In the `class_main.cpp` file, first on the top we have to `#include "Rectangle.h"` -> include the header or the interface file of the **_Rectangle_** class.

We are not going to include the cpp or the implementaiton file. Only the header file. Now the reason we have this separation, the reason we have 2 files per class, is to reduce the compilation times.

So currently our `class_main.cpp` file is dependent on `Rectangle.h`, and that means if we go to this file, and make any changes here, as well as every file is dependent on this file, has to be recompiled.

However if we go to our implementation file, and make any change here, only this file has to be re-compiled, and then it will be linked with other compiled files. So the other files are not going to be re-compiled.

This is the reason, we need to separate the implementaiton of a class from its interface. Because most of the time, the changes are in the implementation or in algorithms.

But sometimes as part of building a new feature or changing an existent one, we also have to change the interface o a class. In that cause, `Rectangle.h`.

## 2 Operator Overloading

## 3 Inheritance

## 4 Polymorphism

## 5 Exceptions

## 6 Tempates
