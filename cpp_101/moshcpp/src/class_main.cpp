#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Rectangle first(10, 20);
    Rectangle second{30, 40};

    // cout << Rectangle::objectsCount << endl;
    cout << first.getObjectsCount() << endl;

    return 0;
}