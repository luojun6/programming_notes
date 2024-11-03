#include <iostream>
#include <fstream>

using namespace std;

struct Movie {
    int id;
    string title;
    int year;
};

int main() {
    ifstream file;
    file.open("data.csv");

    if (file.is_open()) {
        string str;
        // file >> str;
        getline(file, str); // To fetch out the headers
        while (!file.eof())
        {
            getline(file, str, ',');
            if(str.empty()) continue;

            Movie movie;
            movie.id = stoi(str);

            getline(file, str, ',');
            movie.title = str;

            getline(file, str, '\n');
            movie.year = stoi(str);

            // cout << str << endl;;
            cout << movie.title << endl;
        }
        
        file.close();
    }

    return 0;
}