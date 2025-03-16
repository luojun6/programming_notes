#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    Array array{10};
    array[0] = 1;
    cout << array[0] << endl;

    return 0;
}