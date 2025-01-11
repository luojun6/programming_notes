#include "Rectangle.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto rectangle = make_unique<Rectangle>(10, 20);
    rectangle->draw();

    return 0;
}