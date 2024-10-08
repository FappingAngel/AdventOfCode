#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../headers/2016_d1.h"

using namespace std;

bool InputCheck(int x, int y, vector<pair<int, int>> *feld);

int solution_2016_d1() {

    string befehl;
    int richtung = 0, x = 0, y = 0;
    vector<pair<int, int>> feld;

    ifstream file("C:\\Users\\Max\\CLionProjects\\AdventOfCode\\2016_Tag1\\2016_d1_input.txt");
    if (!file.is_open()) {
        cerr << "Datei konnte nicht geöffnet werden" << endl;
    }

    while (file >> befehl) {
        cout << "Befehl: " << befehl << endl;

        // Drehrichtung bestimmen
        richtung = (befehl[0] == 'R' ? richtung + 90 : richtung - 90);
        if (richtung >= 360) {
            richtung -= 360;
        } else if (richtung < 0) {
            richtung += 360;
        }

        //Befehl auslesen
        int neu = stoi(befehl.substr(1, befehl.length() - 1));

        cout << "Richtung: " << richtung << ", Schrittweite: " << neu << endl;

        // Jedes Feld einzeln durchgehen
        for (int i = 0; i < neu; i++) {

            // überprüfen, ob Feld schon existiert
            if (InputCheck(x, y, &feld)) {
                return 0;
            } else {
                feld.push_back(pair<int, int>(x, y));
            }

            //Mit gesammelten Infos rechnen
            if (richtung == 0) {
                y += 1;
            } else if (richtung == 90) {
                x += 1;
            } else if (richtung == 180) {
                y -= 1;
            } else if (richtung == 270) {
                x -= 1;
            } else {
                cerr << "Richtungsfehler: " << richtung << endl;
                return 0;
            }
        }
        cout << " ergebnis: x, y: " << x << ", " << y << endl;
    }
    //Koordinaten alle positiv machen, denn es gibt keine negativen Abstände
    x = (x < 0) ? (-x) : x;
    y = (y < 0) ? (-y) : y;

    //errechnen und ausgeben lassen
    cout << "Distanz: " << (y + x) << endl;
    return 0;
}

bool InputCheck(int x, int y, vector<pair<int, int>> *feld) {

    for (int i = 0; i < feld->size(); i++) {
        int first = feld->at(i).first;
        int second = feld->at(i).second;
        if (first == x && second == y) {
            cout << "erstes doppeltes Feld:  (" << x << ", " << y << ")" << endl;
            return true;
        }
    }
    return false;
}