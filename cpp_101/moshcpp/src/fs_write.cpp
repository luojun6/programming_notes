#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ofstream file;
    file.open("data.csv");

    if (file.is_open()) {
        file << "id,title,year\n";
        file << "1,movie_a,1984\n";
        file << "2,movie_b,1985\n";
        file << "3,movie_c,1986\n";

        file.close();
    }

    return 0;
}