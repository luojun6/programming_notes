#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app);
    // Manipulate the file
    file.close();

    return 0;
}