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