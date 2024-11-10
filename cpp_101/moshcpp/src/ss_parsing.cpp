#include <iostream>
#include <sstream>

using namespace std;


int main() {

    string str = "10 20";
    stringstream stream;

    stream.str(str);

    int first;
    stream >> first;

    int second;
    stream >> second;

    cout << first + second << endl;

    return 0;
}