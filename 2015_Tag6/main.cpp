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

    // Für Teil 1/2 ggf. Bool Array besser

    // bool feld[1000][1000];
    int (*feld)[1000] = new int[1000][1000];
    int index_str;
    int status;

    string zeile;
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


        // Rechnet Teil 1/2 aus
      /*  for (int i = koord11; i <= koord21; i++) {
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
    } */
      
    // Rechnet Teil 2/2 aus
    for (int i = koord11; i <= koord21; i++) {
        for (int j = koord12; j <= koord22; j++) {

            if (status == -1) {
                    feld[i][j] += 2;
            } else if (status == 0) {
                feld[i][j] > 0 ? feld[i][j] -= 1 : feld[i][j] = 0;
            } else if (status == 1) {
                feld[i][j] += 1;
            } else {
                cout << "Fehler: Status = " << status << endl;
                return 0;
            }
        }
    }
    }



    //richtig für Teil 2/2
    //Für Teil 1/2: gegen if-Abfrage und counter++ ersetzen
    int counter = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            counter += feld[i][j];
        }
    }
    cout << "Felder Helligkeit: " << counter << endl;

    file.close();
    delete [] feld;
    return 0;
}