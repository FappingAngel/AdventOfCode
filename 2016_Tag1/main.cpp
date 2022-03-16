#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

int main() {

    string befehl;
    int richtung = 0, x = 0, y = 0;


    ifstream file("C:\\Users\\Max\\CLionProjects\\AdventOfCode\\2016_Tag1\\input.txt");
    if (!file.is_open()) {
        cerr << "Datei konnte nicht geöffnet werden" << endl;
    }

    while (file >> befehl) {
        cout << "Befehl: " << befehl << endl;

        richtung = (befehl[0] == 'R' ? richtung + 90 : richtung - 90);
        if (richtung >= 360) {
            richtung -= 360;
        } else if (richtung < 0) {
            richtung += 360;
        }
        // soweit richtig
        cout << "Richtung: " << richtung << ", Schrittweite: " << befehl[1];
        string neu(1, befehl[1]);
        if (richtung == 0) {
            y += stoi(neu);
        } else if (richtung == 90) {
            x += stoi(neu);
        } else if (richtung == 180) {
            y -= stoi(neu);
        } else if (richtung == 270) {
            x -= stoi(neu);
        } else {
            cerr << "Richtungsfehler2: " << richtung << endl;
            return 0;
        }
        cout << " ergebnis: x, y: " << x << ", " << y << endl;

    }
    x = x < 0 ? x * -1 : x;
    y = y < 0 ? y * -1 : y;
    cout << "Distanz: " << (y + x) << endl;
    return 0;
}


// char