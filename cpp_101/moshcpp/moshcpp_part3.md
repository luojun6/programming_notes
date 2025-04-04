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

```cpp
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Rectangle rectangle;
    rectangle.width = 10;
    rectangle.height = 20;

    cout << rectangle.getArea();

    return 0;
}
```

### 1.4 Access Modifiers

![classes_12](./images/classes_12.png)

```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

class Rectangle
{
public:
    Rectangle();
    ~Rectangle();

    void draw();
    int getArea();

private:
    int width;
    int height;

};

#endif
```

### 1.5 Getters and Setters

```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

class Rectangle {
  public:
    Rectangle();
    ~Rectangle();

    void draw();
    int getArea();

    int getWidth();
    void setWidth(int width);
    int getHeight();
    void setHeight(int height);

  private:
    int width;
    int height;


};

#endif
```

```cpp
#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() {

}

Rectangle::~Rectangle() {

}

void Rectangle::draw() {
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions: " << width << ", " << height << endl;
}

int Rectangle::getArea() {
    return width * height;
}

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(int width) {

    if(width < 0)
        throw invalid_argument("width");
    this->width = width;
}

int Rectangle::getHeight() {
    return height;
}

void Rectangle::setHeight(int height) {
    if(height < 0)
        throw invalid_argument("height");
    this->height = height;
}
```

### 1.6 Construtors

```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

class Rectangle {
  public:
    Rectangle();
    Rectangle(int width, int height);
    ~Rectangle();

    void draw();
    int getArea();

    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);

  private:
    int width = 0;
    int height = 0;


};

#endif
```

```cpp
Rectangle::Rectangle(int width, int height) {
    cout << "Constructing a rectangle object." << endl;
    setWidth(width);
    setHeight(height);
}
```

### 1.7 Member Initializer List

### 1.8 The Default Constructor

A default constructor is a constructor with no parameters. Note that just like functions, we can also overload constructors, so here we have 2 constructors with different signatures.

```cpp
class Rectangle {
  public:
    Rectangle() = default;
}
```

```cpp
Rectangle::Rectangle() {
    width = height = 0;
}
```

This cpp complier always automatically generates a default constructor for every class unless we provide a constructor, and that is the reason why earlier before we define this constructor, we could create instances of the rectangle class without initial values.

### 1.9 Using the Explicit Keyword

![classes_13](./images/classes_13.png)

![classes_14](./images/classes_14.png)

The reason of this works is because the compiler knows that in this class, we have a constructor that takes an integer, so when we pass an integer to this function, the complier is going to do an implict conversion.

So it's going to implictly convert this integer to a person object, so underflying is going to create a person object, and then it will pass that person object to this function.

But look at the syntax, in this case it doesn't really make sense to pass an integer to this function. This is where we can use the `explicit` keyword to prevent the complier from doing an implict conversion.

![classes_15](./images/classes_15.png)

![classes_16](./images/classes_16.png)

### 1.10 Constructor Delegation

```cpp
Rectangle::Rectangle(int width,
                     int height,
                     const string &color) : Rectangle(width, height) {
    // setWidth(width);
    // setHeight(height);
    cout << "Constructing a rectangle object with color." << endl;
    this->color = color;
}
```

### 1.11 The Copy Constructor

Now we have a special kind of constructor called the copy constructor which is used for copying objects.

```cpp
int main() {
    Rectangle first(10, 20);
    Rectangle second = first;

    return 0;
}
```

A copy of the `first` rectangle is taken and stored in the `second` rectangle object. So we have **2 independent** objects in memory.

The reason copying works is because, under the hood, the complier automatically generates a copy constructor in the rectangle class. This copy constructor takes a source object, in this case -> the `first` rectangle, and then it will copy all the values in this object into the `second` object.

This copy constructor works perfectly fine pretty much all the time, but there are special situations where we have to control over how objects are copied.

In these situations, we need to explicitly define a copy constructor to decide how objects are copied.

Back to the header file, let's declare a new constructor. This constructor should have a single parameter, the type of the parameter has to be the same as the class, because that is the object we're copying.

```cpp
Rectangle(Rectangle)
```

Now we have t omake this a reference parameter `&`, because if we don't do so, the complier doesn't know how to copy this object, because the copy operation is going to be defined in this constructor.

```cpp
Rectangle(Rectangle&)
```

Also we should make this constant parameter, so we don't accidentally modify the source object as part of the copy operaiton.

```cpp
Rectangle(const Rectangle&)
```

So let's call the parameter `source`.

```cpp
Rectangle(const Rectangle& source);
```

In the definition:

```cpp
Rectangle::Rectangle(const Rectangle& source) {
    cout << "Rectangle copied" << endl;
    this->width = source.width;
    this->height = source.height;
    this->color = source.color;
}
```

Now there is a problem with this approach, if tomorrow we decide to add a new member variable in the `Rectangle` class, we have to remember to come back and modify the copy constructor to copy that member variable as well. If we don't do so, we're going to create bugs tha tare hard to find. That's why it's always best to rely on the copy constructor that the compiler generates for us.

![classes_17](./images/classes_17.png)

Pass the object, it will be copied.

```cpp
void showRectangle(showRectangle rectangle) {}
```

Pass the reference, it will not be copied.

```cpp
void showRectangle(showRectangle& rectangle) {}
```

There are situations where we want to stop the copy operation, we want to prevent an object from being copied by value. In those situation, we can explicitly delete the copy constructor. And remove the definition.

```cpp
Rectangle(const Rectangle& source) = delete;
```

What we are doing here, is that we are telling the compiler to delete the copy constructor for us. Then we can not copy in the main file.

### 1.12 The Desctructor

We have another special function in our classes called a **desctructor**, desctructors are automatcially called when our objects are being desctroyed.

This is an opportunity for us to free system resources that an object is using. So if we allocate memory or open a file or network connection. Then we need to release resources and desctructors.

```cpp
~Rectangle();
```

### 1.13 Static Members

All the functions and variables we have declared as above are what we call instance members. These members belong to instances of the `Rectangle` class.

So each instance is going to have its own copy of these members. But we can also declare members that belong to the `Rectangle` class itself.

So we will have a single copy of these members in memory, and that single copy will be shared by all instances. We refer to members tha belong to the class as static members.

Added in `Rectangle.h`

```cpp
private:
    static int objectsCount;
public:
```

Whenever we declare a static variable in the class, we should always define it in our implementation file.

Back to our implementation file `Rectangle.cpp`

```cpp
Rectangle::Rectangle(int width, int height) {
    objectsCount++;
    cout << "Constructing a rectangle object." << endl;
    setWidth(width);
    setHeight(height);
}

...

int Rectangle::objectsCount = 0;

int Rectangle::getObjectsCount() {
    return this->objectsCount;
}
```

### 1.14 Constant Objects and Functions

![classes_18](./images/classes_18.png)

When we make an object constant, all its attributes become constant or read only as well.

In programming we say this objects becomes **immutable**. To mutate something means to change it, so mutable means changeable, and immutable means unchangeable.

![classes_19](./images/classes_19.png)

We only have `getters`, and we don't have any `setters`, but we have a few other methods that are missing here. We have the `draw` method and `getArea` method...where are those methods?

Look at the declaration of the `getHeight()` method, this method is declared as a constant, that means, in this method, we are not changing the state of this object.

```cpp
int Rectangle::getHeight() const {
    return height;
}
```

Added `const` in `Rectangle.h`

```cpp
    int getArea() const ;
    int getWidth() const;
```

Added `const` in `Rectangle.cpp`

```cpp
void Rectangle::draw() const {
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions: " << width << ", " << height << endl;
}

int Rectangle::getArea() const {
    return width * height;
}
```

### 1.15 Pointer to Objects

All the `Rectangle` objects we have created so far, we're on the **stack** which is a part of memory that automatically gets cleaned up, when our objects go out of scope.

So when the main function finishes execution, this `Rectangle` variable will go out of scope. So the desctructor of the `Rectangle` object gets called. And then after allocated to this object will be freed automatically.

So objects on the stack are useful when they are local to a function. So we don't need them outside of a function, but sometimes we need an object to stay in memory after a funciton finishes execution.

In those cases, we need to create that object on the heap, or the free store using the new operator.

```cpp
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    auto* rectangle = new Rectangle(10, 20);
    rectangle->draw();

    delete rectangle;
    rectangle = nullptr;

    return 0;
}
```

If we don't point `rectangle` to `nullptr`, we'll have a pointer pointing to a memory address that doesn't exist anymore. We refer to that as a **dangling** pointer.

If you forget to free up the memory and reset the pointer, our program will have a memory leak. So it's going to take up some memory, but it will never release that memory.

So in morden c++, we should never use the `new` and `delete` opertors anymore, instead we should use smart pointers.

The great thing about smart pointers is that they will take care of freeing up the memory using its desctructor. So we don't have to worry about doing this.

```cpp
#include "Rectangle.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto rectangle = make_unique<Rectangle>(10, 20);
    rectangle->draw();

    return 0;
}
```

![classes_20](./images/classes_20.png)

### 1.16 Object Array

## 2 Operator Overloading

### 2.1 Overloading the Equality Operator

The whole idea behind operator overloading is to implement the built-in operators for our classes.

```cpp
#ifndef LENGTH_H
#define LENGTH_H

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    ~Length();

  private:
    int value;
};

#endif
```

```cpp
#include "Length.h"

Length::Length(int value) {
    this->value = value;
}

bool Length::operator==(const Length& other) const {
    return value == other.value;
}

bool Length::operator==(int other) const {
    return value == other;
}

bool Length::operator!=(int other) const {

    // return value != other;
    return !(value == other);
}

Length::~Length() {

}
```

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {

    Length first{10};
    Length second{10};

    if(first == second)
        cout << "first == second" << endl;

    if(first == 10)
        cout << "first == 10" << endl;

    if(first != 20)
        cout << "first != 20" << endl;

    return 0;
}
```

In the `!=` implemtatation, we don't write `return value != other;`, because if in the future, we change the logic for comparing 2 length objects, we have to make changes to several functions.

We have to change both the equality and inequality. So the better to implement the ineqaulity operator, is to implement it in terms of the equality operator. We can rewrite the implementation like this `return !(value == other);`.

First we compared the value with other value in terms of Equality, at this point this function will get executed. Now whatever this funciton returns will simply invert the value.

```cpp
bool Length::operator!=(int other) const {

    // return value != other;
    return !(value == other);
}
```

### 2.2 Overloading the Comparison Operators

### 2.3 Overloading the Spaceship Operator

In C++, we have a new operator called the spaceship or three-way comparison operator.

```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int y = 20;

    if(x < y) {
        cout << "x < y" << endl;
    } else if(x > y) {
        cout << "x > y" << endl;
    } else {
        cout << "x == y" << endl;
    }

    return 0;
}
```

So here we're doing 2 comparisons to identify the relationship between x and y, now both x and y are integers, there are small primitive types, so the comparison are pretty cheap.

But sometimes we might be working with large complex objects, and these objects might have several attributes that we need to take into account as part of the comparison, in that case our comparisons are going to be expensive.

This is where we can use a new operator in modern C++ to identify the relationship between 2 objects using a single comparison instead of 2, so here we can type x less than equal to greater than y.

```cpp
#include <iostream>
#include <compare>

using namespace std;

int main() {
    int x = 10;
    int y = 20;
    auto result = x <=> y;


    // if(x < y) {
    if(result == strong_ordering::less) {
        cout << "x < y" << endl;
        // } else if(x > y) {
    } else if(result == strong_ordering::greater) {
        cout << "x > y" << endl;
    } else {
        cout << "x == y" << endl;
    }

    return 0;
}
```

```sh
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ g++-10 -std=c++20 ./src/spaceship_main.cpp -o ./bin/spaceship
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ ./bin/spaceship 
x < y
```

So we still have 2 comparisons, but this comparisons could potentially be cheaper than comparing these 2 objects, so now using a single comparison, we're identifying the relationship between x and y.

There is another reason to use the spaceship operator, with a modern C++ compiler, if you overload the spaceship operator, the compiler will automatically generate all the relational operators for us.

```cpp
#ifndef LENGTH_H
#define LENGTH_H
#include <compare>

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    // bool operator>(const Length& other) const;
    // bool operator<(const Length& other) const;
    // bool operator>=(const Length& other) const;
    // bool operator<=(const Length& other) const;
    std::strong_ordering operator<=>(const Length& other) const;
    ~Length();

  private:
    int value;
};

#endif
```

```cpp
#include "Length.h"

Length::Length(int value) {
    this->value = value;
}

bool Length::operator==(const Length& other) const {
    return value == other.value;
}

bool Length::operator==(int other) const {
    return value == other;
}

bool Length::operator!=(int other) const {

    // return value != other;
    return !(value == other);
}

// bool Length::operator>(const Length &other) const {
//     return value > other.value;
// }

// bool Length::operator<(const Length &other) const {
//     return value < other.value;
// }

// bool Length::operator>=(const Length &other) const {
//     return !(value < other.value);
// }

// bool Length::operator<=(const Length &other) const {
//     return !(value > other.value);
// }

std::strong_ordering Length::operator<=>(const Length &other) const
{
    return value <=> other.value;
}

Length::~Length()
{
}
```

```cpp
#include <iostream>
#include <compare>
#include "Length.h"

using namespace std;

int main() {
    Length first{10};
    Length second{20};

    if (first < second)
        cout << "First is smaller" << endl; 

    return 0;
}
```

### 2.4 Overloading the Stream Insertion Operator

```cpp
#ifndef LENGTH_H
#define LENGTH_H
#include <compare>
#include <ostream>

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    // bool operator>(const Length& other) const;
    // bool operator<(const Length& other) const;
    // bool operator>=(const Length& other) const;
    // bool operator<=(const Length& other) const;
    std::strong_ordering operator<=> (const Length& other) const;
    ~Length();

    int getValue() const;

  private:
    int value;
};

std::ostream& operator<<(std::ostream& stream, const Length& length);

#endif
```

```cpp
int Length::getValue() const
{
    return this->value;
}

std::ostream &operator<<(std::ostream &stream, const Length &length)
{
    
    stream << length.getValue();
    return stream; 
}
```
The reason we return the `stream` here is so we can chain the insertion operator multiple types. So over here, we should be able to write code like `cout << 1 << 2 << 3;`

### 2.5 Overloading the Stream Extraction Operator

```cpp
#ifndef LENGTH_H
#define LENGTH_H
#include <compare>
#include <ostream>
#include <istream>

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    // bool operator>(const Length& other) const;
    // bool operator<(const Length& other) const;
    // bool operator>=(const Length& other) const;
    // bool operator<=(const Length& other) const;
    std::strong_ordering operator<=> (const Length& other) const;
    ~Length();

    int getValue() const;
    void setValue(int value);

  private:
    int value;
};

std::ostream& operator<<(std::ostream& stream, const Length& length);
std::istream& operator>>(std::istream& stream, Length& length);

#endif
```

```cpp
#include "Length.h"

Length::Length(int value) {
    this->value = value;
}

bool Length::operator==(const Length& other) const {
    return value == other.value;
}

bool Length::operator==(int other) const {
    return value == other;
}

bool Length::operator!=(int other) const {

    // return value != other;
    return !(value == other);
}

// bool Length::operator>(const Length &other) const {
//     return value > other.value;
// }

// bool Length::operator<(const Length &other) const {
//     return value < other.value;
// }

// bool Length::operator>=(const Length &other) const {
//     return !(value < other.value);
// }

// bool Length::operator<=(const Length &other) const {
//     return !(value > other.value);
// }

std::strong_ordering Length::operator<=>(const Length &other) const
{
    return value <=> other.value;
}

Length::~Length()
{
}

int Length::getValue() const
{
    return this->value;
}

void Length::setValue(int value)
{
    this->value = value;
}

std::ostream &operator<<(std::ostream &stream, const Length &length)
{
    
    stream << length.getValue();
    return stream; 
}

std::istream &operator>>(std::istream &stream, Length &length)
{
    int value;
    stream >> value;
    length.setValue(value);
    return stream;
}
```

### 2.6 Friends of Classes

In the last operators we implementd, we are using the `getter()` and `setter()` we generated to access the value attribute, but sometimes these operators that we define outside of a class need to access certain attributes that don't have a public `getter()` or a `setter()`.

```cpp
#ifndef LENGTH_H
#define LENGTH_H
#include <compare>
#include <ostream>
#include <istream>

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    std::strong_ordering operator<=> (const Length& other) const;
    ~Length();

    int getValue() const;
    void setValue(int value);

  private:
    int value;
    int x;

    // Declare this function as friend, then this function can access the private attributes
    friend std::ostream& operator<<(std::ostream& stream, const Length& length);
};
std::ostream& operator<<(std::ostream& stream, const Length& length);

std::istream& operator>>(std::istream& stream, Length& length);

#endif
```

### 2.7 Overloading the Arithmetic Operators

```cpp
Length operator+(const Length& other) const;
Length operator+(int _value) const;
```

```cpp
std::strong_ordering Length::operator<=>(const Length &other) const
{
    return value <=> other.value;
}

Length Length::operator+(int _value) const
{
    return Length(this->value + _value);
}
```

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {

    Length first{10};
    Length second{10};

    if(first == second)
        cout << "first == second" << endl;

    if(first == 10)
        cout << "first == 10" << endl;

    if(first != 20)
        cout << "first != 20" << endl;

    cout << "Change the first: ";
    cin >> first;
    cout << first << endl;

    Length third = first + second;
    cout << "third: " << third << endl; 
    cout << "third + 10 = " << third + 10 << endl;

    return 0;
}
```

```sh
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ g++-10 -std=c++20 ./src/operator_main.cpp ./src/Length.cpp -o ./bin/main 
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ ./bin/main 
first == second
first == 10
first != 20
Change the first: 20
20
third: 30
third + 10 = 40
```

### 2.8 Overloading Compound Assignment operators

Here we are adding something to an existing object, so we are not creating a brand new length object, we are modifying an existing object. So the return type should be `Length&` meaning an existing length object.

We are not going to declare this funciton as `const`, because in this funciton, we'll be modifying the current length object. So `this` is a pointer to the current object, but `this` is just a point, it holds a memory address, but here we need an actual length object. Now how can we get that object => by de-referencing this pointer.

```cpp
Length& operator+=(const Length& other);
```

What shall we return in the implementation function, we need a refrence to the current object,

```cpp
Length& Length::operator+=(const Length &other)
{
    value += other.value;
    return *this;
}
```

### 2.9 Overloading the Assignment Operator

If you have two `Length` objects, we can always assign one to another. The reason this works is because under the hood, the compiler generate a default assignment operator for us. This default assignment operator copies all the member variables of the source object to the target object.

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {

    Length first{10};
    Length second{20};
    first = second;

    return 0;
}
```

That this works perfectly fine pretty much all the time, but there are situations where we need to have control over how objects are assigned. 

```cpp
Length& operator=(const Length& other);
```

```cpp
#include <iostream>

...

Length& Length::operator=(const Length &other)
{
    std::cout << "Object assigned" << std::endl;
    value = other.value;
    return *this;
}
```

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {

    Length first{10};
    Length second{20};
    first = second;

    return 0;
}
```

```sh
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ g++-10 -std=c++20 ./src/operator_main.cpp ./src/Length.cpp -o ./bin/main 
jun@luo:~/projects/programming_notes/cpp_101/moshcpp$ ./bin/main 
Object assigned
```

Let's create a default constructor for the `Length` class, so we can create a `Length` object with supplying a value.

```cpp
class Length {
  public:
    explicit Length(int value);
    Length() = default;

...
...
}
```

```cpp
int main() {

    Length first{10};
    Length second = first;

    return 0;
}
```

Now if we're on tihs program, we are not going to see the "Object assign" message. Because this `=` sign has different meanings depending on how we use it.

If we use it to initialize a new object, it reprensents the copy operation, so in this case, the **copy constructor** is called. Because we're initializing a new object. 

However on the next line, if we set the `second = first`, because we have an existing object, this `=` sign represents the assignment operator, so here we have the assignment operator and this used when we assign to an existing object.

```cpp
int main() {

    Length first{10};

    // Copy constructor (NEW)
    Length second = first;

    // Assignment operator (EXISTING)
    second = first;

    return 0;
}
```

Sometimes we want to prevent an object from being copied. We can create a copy constructor that takes a constant length as a reference, now we `delete` this.

```cpp
Length(const Length& other) = delete;
```

![operator_0.png](./images/operator_0.png)

```cpp
Length& operator=(const Length& other) = delete;
```

### 2.10 Overloading Unary Operators

```cpp
    Length& operator++();   // prefix
    Length operator++(int); // postfix
```

```cpp
Length &Length::operator++()
{
    value++;
    return *this;
}

Length Length::operator++(int)
{
    Length copy = *this;
    operator++();
    return copy;
}
```

```cpp
int main() {

    Length first{10};
    Length second = first++;
    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;

    return 0;
}
```

### 2.11 Overloading the Subscript Operator

Subscript operator is the square bracket we use for accessing individual elements in an array using an index.

So if you have a class that behaves like an array, we can define the subscript operator to provide access to individual elements in that class.

Add a constructor that takes the initial size of the array, and for that we're going to use `size_t` which is a type or a data type that represents the size of the largest object the system can handle, oftenly translates to `unsigned int` or `unsigned long long` depending on the compiler, like `Array(size_t size);` and it needs to include `<cstddef>`.

In this class, we need an integer array for storing a bunch of integers, but we cannot declare an integer array like `int values[size];` because the size is determined at runtime, so at compile time, the compiler doesn't know how many elements it should allocate for this array.

So to solve this problem, we need to allocate memory dynamically, so let's generate the definition for the constructor, Clang is suggesting to make this constructor `explicit` which is a great idea.

![operator_1.png](./images/operator_1.png)

And we should also store the initial size, because an array should always know its size.

```cpp
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

#pragma once

class Array
{
public:
    explicit Array(size_t size);
    ~Array();

private:
    int* values;
    size_t size;
};

#endif
```

```cpp
#include "Array.h"


Array::Array(size_t size)
{
    values = new int[size];
    this->size = size;
}

Array::~Array()
{
    delete[] values;
}
```

Because we have allocated memory dynamically in the constructor, we should release it in the destructor. 

Then let's add the subscript operator, now the return type has to be an integer reference, because with this operator, will be accessing an existing integer in this array.

What about the parameter => has to be an index, and the largest index we can have is `size_t`. So the parameter should be type `size_t` called `index`.

```cpp
int& operator[](size_t index);
```

```cpp
int &Array::operator[](size_t index)
{   
    // size: 10, index: 9
    if (index >= size)
        throw std::invalid_argument("index");

    return values[index];
}
```

```cpp
#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    Array array{10};
    array[0] = 1;
    cout << array[0] << endl;

    return 0;
}
```

### 2.12 Overloading the Indirection Operator

In the manual practice `SmartPoint` class, that takes an integer pointer in its constructor and releases it in the desctrutor, similar to smart pointers in the standard libray.

```cpp
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#pragma once

class SmartPointer
{
public:
    explicit SmartPointer(int *ptr);
    ~SmartPointer();

private:
    int* ptr;
};

#endif
```

```cpp
#include "SmartPointer.h"

SmartPointer::SmartPointer(int *ptr)
{
    this->ptr = ptr;
}

SmartPointer::~SmartPointer()
{
    delete ptr;
}
```

But how to access the actual integer that this pointer `ptr` points to. So we ave an integer pointer `ptr`, but there is no way to access that underlying integer in memory. So we can not read or modify it. To solve this problem, we need to overload the interaction operator.

So here we add a new operator in direction without any parameters, and the return type has to be integer as a reference `int&`, because we will be accessing and existing integer in memory.

```cpp
int& operator*();
```

```cpp
int &SmartPointer::operator*()
{
    return *ptr;
}
```

### 2.13 Overloading Type Conversions

If we declare an integer and assign this `length` object, our code doesn't get complied, because the compiler doesn't know how to converter a `length` object to an integer.

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {
    Length length{10};
    int x = length;

    return 0;

}
```

We can easily solve this problem by defining a conversion function in the length class. We are going to add a function which doesn't have any parameters or a return type. It only has a name, and the name is operator follow by a space and the target type.

```cpp
operator int() const;
```

```cpp
Length::operator int() const
{
    return value;
}
```

We can use the `explict` keyword then the compiler will no longer implictly convert a length object to integer. 

```cpp
explicit operator int() const;
```

Then in the invoking we have to explictly cast a `length` object to the integer.

```cpp
#include <iostream>
#include "Length.h"

using namespace std;

int main() {
    Length length{10};
    int x = static_cast<int>(length);

    cout << length << endl;

    return 0;

}
```

### 2.14 Inline Functions

So far we have defined all the functions of the `Length` class in the cpp or implementaiton file. Or we can also define these functions in the heder file, for example:

```cpp
...
...
...
    explicit operator int() const;
    // Inline function
    int getValue() const {
      return value;
    };
    void setValue(int value);
...
...
...
```
Now we refer to this funciton as an `inline` function, by making this function `inline`, we are asking the compiler to replace the function call with the code inside the function.

Back to our main file, if you call `length.getValue()`, the compiler will replace this function call with the code inside the function, and this can result in a slight performance boost, because calling functions involves a bit of overhead.

So when we call a function, the compiler has to do some magic, so the control goes inside this function `length.getValue()` and then goes back to the `main()` function. Now this kind of movement has a tiny of overhead and `inline` functions allow us to remove that overhead.

So does it mean we should define all of our functions here? Defintely and absolutely **NOT**! Because this header file represents the interface of our class, now we should keep this interface as stable as possible, because otherwise every time we change this file, this file as well as all the files that are dependent on this and their dependencies have to be recompanied.

So to reduse the compilation time, we should move all the details all the logic all the algorithms in the cpp or implementation file.

The other reason for not defining these functions in as `inline` is that doing so causes clutter, so we cannot look at this class and tell what features it provides, will be distracted by so much detail by so much complexity.

So as a best practice, we should keep the header file as simple and as stable as possible.

But what if we want to declare a function as `inline`?  Well we can still do so using the `inline` keyword in the cpp or implementation file, instead of declaring the details in header file.

```cpp
inline int Length::getValue() const
{
    return this->value;
}
```

With this, we are asking the compiler to replace all the costs to this function with the code inside this function. 

Just note that there is no guarantee that this will happen, this is up to the compiler to decide, if this should happen or not.

Also you should use this technique only with really simple functions that don't change, preferable one liners like this function. Because if your function has more than one line, let's say 3 lines, every time you have a call to that function, that call is going to be replaced by 3 lines. So this can increse the size ofthe executable, the size of your application.

Now as the size of the executable increases, the performace might suffer. So don't blindly make your functions in line. In fact most modern cpp compilers will automatically decide whether they should inline functions or not, without you do anything.

So my advice is stay away from this technique unless you know what you're doing.

## 3 Inheritance and Polymorphism

### 3.1 Inheritance

Inheritance is a mechanism for reusing code. So we can implement all these common features once in a class like `Widget`, and then have other classes inherit these features.

![inheritance_0.png](./images/inheritance_0.png)

In this scenario, we refer the widget class as the base or and the textbox class as the derived or child class. And this arrwo between these 2 classes reprsents the inheritance relationship. We say a text box is a widget.

```cpp
#ifndef WIDGET_H
#define WIDGET_H

#pragma once

class Widget
{
public:
    void enable();
    void disable();
    bool isEnabled() const;

private:
    bool enabled;
};

#endif
```

```cpp
#include "Widget.h"

void Widget::enable()
{
    enabled = true;
}

void Widget::disable()
{
    enabled = false;
}

bool Widget::isEnabled() const
{
    return enabled;
}
```

```cpp
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <string>
#include "Widget.h"

#pragma once
using namespace std;

class TextBox : public Widget
{
public:
    TextBox() = default;
    explicit TextBox(const string& value);
    string getValue();
    void setValue(const string& value);
private:
    string value;
};

#endif
```

```cpp
#include "TextBox.h"

TextBox::TextBox()
{
    value = "";
}


TextBox::TextBox(const string &value)
{
    this->value = value;
}

string TextBox::getValue()
{
    return value;
}

void TextBox::setValue(const string &value)
{
    this->value = value;
}
```

Now when we use `public` here to inherit from `Widget`, that means the public members of this class will be inherited as ***public***, so we can acccess them outside of the `TextBox` class.

```cpp
#include <iostream>
#include "TextBox.h"

using namespace std;

int main(int argc, char const *argv[])
{
    TextBox box;
    box.enable();    
    cout << box.isEnabled() << endl;

    return 0;
}
```

What if we use `private` here, that means the public members of this class will become ***private*** in the `TextBox` class. So the inherited members are not visible outside of the `TextBox` class. But we can still access them inside the `TextBox` class.

Most of the time I would say, 99% of the fime, we would use the `public` modifier here, because the public members of the `Widget` class represent the interface of this class. 

So if you want to inherit all these features in a derivative class, we still want to have those features. Thay's why most of the time, we use the `public` keyword here.

### 3.2 Protected Members



## 4 Exceptions

## 5 Tempates
