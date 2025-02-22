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