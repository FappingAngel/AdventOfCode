#include <iostream>
#include <vector>
#include <fstream>
#include "../headers/2015_d3.h"

using namespace std;

int solution_2015_d3() {
    string logo = "           ^7JYYJ7:           \n"
                  "         .JGBBGGBBGJ.         \n"
                  ":::::::. ?BGGGGGGGGB? .:::::::\n"
                  "PGGGGGGJ 7BGGGGGGGGB! JGGGGGGP\n"
                  "JBGGGGGG! !PGBBBBGP! !GGGGGGBJ\n"
                  ".5BGGGGGGY~:^!77!^:~YGGGGGGB5.\n"
                  " .YBGGGGGGGPYJ??JYPGGGGGGGBY. \n"
                  "   !5GBGGGGGGBBBGGGGGGGBG5!   \n"
                  "    .~JPGBBGGGGGGGGBBGPJ~.    \n"
                  "       .^!?Y555555Y?!^.       \n"
                  "                              \n"
                  "   BERUFSGENOSSENSCHAFT FÜR   \n"
                  "   HANDEL UND WARENLOGISTIK   \n";

    cout << logo << endl;

    vector<int> feld;
    char aktuell;
    int aktuellehoehe = 0;
    int aktuellebreite = 0;
    int robohoehe = 0;
    int robobreite = 0;
    int counter = -1;
    feld.push_back(0);
    feld.push_back(0);
    feld.push_back(2);
    string path = "C:\\Users\\Max\\CLionProjects\\advent-of-code-2015-d3\\anweisungen.txt";
    ifstream datei(path);

    while (datei >> aktuell) {
        counter += 1;
        // cout << "peep" << endl;
        // cout << "Aktuell: " << aktuell << endl;
        if (counter % 2 == 0) {
            switch (aktuell) {
                case '^': {
                    aktuellehoehe += 1;
                    break;
                }
                case '<': {
                    aktuellebreite -= 1;
                    break;
                }
                case '>': {
                    aktuellebreite += 1;
                    break;
                }
                case 'v': {
                    aktuellehoehe -= 1;
                    break;
                }
                default: {
                }
            }
            // Höhe u. Breite valid
            int zaehler = 0;
            for (int i = 0; i < feld.size(); i += 3) {

                if (feld[i] == aktuellehoehe) {
                    if (feld[i + 1] == aktuellebreite) {
                        feld[i + 2] += 1;
                        break;              // reicht das für die "for" schleife?
                    }

                }
                zaehler += 3;
                // cout << "Zähler: " << zaehler << endl;
                if (zaehler >= feld.size()) {
                    feld.push_back(aktuellehoehe);
                    feld.push_back(aktuellebreite);
                    feld.push_back(1);
                    break;
                }
            }
        } else {
            switch (aktuell) {
                case '^': {
                    robohoehe += 1;
                    break;
                }
                case '<': {
                    robobreite -= 1;
                    break;
                }
                case '>': {
                    robobreite += 1;
                    break;
                }
                case 'v': {
                    robohoehe -= 1;
                    break;
                }
                default: {
                }
            }
            // Höhe u. Breite valid
            int zaehler = 0;
            for (int i = 0; i < feld.size(); i += 3) {

                if (feld[i] == robohoehe) {
                    if (feld[i + 1] == robobreite) {
                        feld[i + 2] += 1;
                        break;              // reicht das für die "for" schleife?
                    }

                }
                zaehler += 3;
                // cout << "Zähler: " << zaehler << endl;
                if (zaehler >= feld.size()) {
                    feld.push_back(robohoehe);
                    feld.push_back(robobreite);
                    feld.push_back(1);
                    break;
                }
            }
        }
    }


    int neuerzaehler = 0;
    for (int i = 2; i < feld.size(); i += 3) {
        if (feld[i] >= 1) {
            neuerzaehler += 1;
        }
    }
    cout << "Häuser mit einem Geschenk: " << neuerzaehler << endl;

    /*for(int i = 0; i < feld.size(); i++){
        cout<< "Feld an " << i << ": "<< feld[i] << endl;
    }*/
    cout << "Feldgröße: " << feld.size() << endl;
    datei.close();
    return 0;
}