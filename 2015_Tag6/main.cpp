#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string path = "./inputs.txt";
    ifstream file(path);

    if(!file.is_open()){
        cout << "nicht geöffnet" << endl;
        return 0;
    }

    int feld[1000][1000];
    int position = 0;
    int index_str;
    string zeile;
    string substring = "toggle";

    while (getline(file, zeile)) {
        cout << zeile << endl;
        if (index_str = zeile.find("toggle", 0) != string::npos) {
            cout << "Toggle existiert" << endl;
        }


        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                feld[i][j] = 0;
            }
        }

        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
}