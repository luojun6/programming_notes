#include <iostream>
#include "Length.h"

using namespace std;

int main() {

    Length first{10};

    // Copy constructor (NEW)
    Length second = first;

    // Assignment operator (EXISTING)
    second = first;

    return 0;
}