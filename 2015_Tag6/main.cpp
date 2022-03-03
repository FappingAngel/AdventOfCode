#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ifstream file("C:\\Users\\Max\\CLionProjects\\AdventOfCode\\2015_Tag6\\inputs.txt");
    if (!file.is_open()) {
        cout << "nicht geöffnet" << endl;
        return 0;
    }
    bool feld[1000][1000]; // mit pointer für den Heap
    bool (*p)[1000] = feld;
    int position = 0;
    int index_str;
    string zeile;
    int status;
    string test1;
    string substring;

    int koord11;
    int koord12;
    int koord21;
    int koord22;

    // Feld auf 0 setzen
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            feld[i][j] = 0;
        }
    }

    while (getline(file, zeile)) {
        // cout << zeile << endl;
        // Findet Modus, ob an, aus oder toggle
        if (index_str = zeile.find("toggle", 0) != string::npos) {
            // cout << "Toggle existiert" << endl;
            status = -1;
            substring = zeile.substr(7);
        } else if (index_str = zeile.find("on", 0) != string::npos) {
            //cout << "Turn on existiert" << endl;
            status = 1;
            substring = zeile.substr(8);
        } else if (index_str = zeile.find("off", 0) != string::npos) {
            // cout << "Turn off existiert" << endl;
            status = 0;
            substring = zeile.substr(9);
        } else {
            cout << "Fehler: " << zeile << endl;
        }

        // Sucht die Koordinatenpaare
        koord11 = stoi(substring.substr(0, substring.find(',')));
        substring = substring.substr(substring.find(',') + 1);
        koord12 = stoi(substring.substr(0, substring.find(' ')));
        substring = substring.substr(substring.find(' ') + 8);
        koord21 = stoi(substring.substr(0, substring.find(',')));
        substring = substring.substr(substring.find(',') + 1);
        koord22 = stoi(substring);

        // cout << "Koord11: " << koord11 << endl;
        // cout << "Koord12: " << koord12 << endl;
        // cout << "Koord21: " << koord21 << endl;
        // cout << "Koord22: " << koord22 << endl;
        // cout << "string: " << zeile << endl;
        // cout << "substring: "<< substring << endl;

        // Rechnet
        for (int i = koord11; i <= koord21; i++) {
            for (int j = koord12; j <= koord22; j++) {

                if (status == -1) {
                    if (feld[i][j] == 0) {
                        feld[i][j] = 1;
                    } else {
                        feld[i][j] = 0;
                    }
                } else if (status == 0) {
                    feld[i][j] = 0;
                } else if (status == 1) {
                    feld[i][j] = 1;
                } else {
                    cout << "Fehler: Status = " << status << endl;
                    return 0;
                }
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (feld[i][j] == 1)
                counter++;
        }
    }
    cout << "Felder an: " << counter << endl;

    file.close();

    return 0;
}