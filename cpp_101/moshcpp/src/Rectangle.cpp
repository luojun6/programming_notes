#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() {
    width = height = 0;
}

// Rectangle::Rectangle(const Rectangle& source) {
//     cout << "Rectangle copied" << endl;
//     this->width = source.width;
//     this->height = source.height;
//     this->color = source.color;
// }

Rectangle::Rectangle(int width, int height) {
    objectsCount++;
    cout << "Constructing a rectangle object." << endl;
    setWidth(width);
    setHeight(height);
}

Rectangle::Rectangle(int width,
                     int height,
                     const string &color) : Rectangle(width, height) {
    // setWidth(width);
    // setHeight(height);
    cout << "Constructing a rectangle object with color." << endl;
    this->color = color;
}

// Rectangle::Rectangle(int width, int height) :
//     width{width},
//     height{height} {}

Rectangle::~Rectangle() {
    cout << "Desctructor called" << endl;
}

void Rectangle::draw() const {
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions: " << width << ", " << height << endl;
}

int Rectangle::getArea() const {
    return width * height;
}

int Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(int width) {

    if(width < 0)
        throw invalid_argument("width");
    this->width = width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(int height) {
    if(height < 0)
        throw invalid_argument("height");
    this->height = height;
}

int Rectangle::objectsCount = 0;

int Rectangle::getObjectsCount() {
    return this->objectsCount;
}
