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