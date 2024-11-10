#include <iostream>
#include <sstream>

using namespace std;

struct Movie {
    string title;
    int year;
};

Movie parseMovie(string str) {
    stringstream stream;
    stream.str(str);

    Movie movie;
    getline(stream, movie.title, ',');
    stream >> movie.year;

    return movie;
}


int main() {

    auto movie = parseMovie("Terminator 1, 1984");
    cout << movie.title << "\n";
    cout << movie.year << "\n";

    return 0;
}