#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


bool part2(string line) {
    int doppeltGefunden = 0;
    int eingeschlossen = 0;
    string stringProbe;
    for (int i = 0; i < line.length() - 2; i++) {
        stringProbe.push_back(line.at(i));
        stringProbe.push_back(line.at(i + 1));
        if (doppeltGefunden < 1)
            for (int j = i + 2; j < line.length(); j++) {
                if (stringProbe.at(0) == line.at(j) && stringProbe.at(1) == line.at(j + 1)) {
                    cout << "Equal: " << stringProbe << " = " << line.at(j) << line.at(j + 1) << endl;
                    doppeltGefunden += 1;
                    break;
                }
            }
        if (line.at(i) == line.at(i + 2)) {
            eingeschlossen += 1;
        }
        stringProbe = "";
    }
    return doppeltGefunden >= 1 && eingeschlossen >= 1;
}


int main() {

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

    string path = "C:\\Users\\Max\\CLionProjects\\AdventOfCode_2015_d5\\strings.txt";
    ifstream datei(path);


    int vokale = 0;
    char aktuellerBuchstabe;
    char vorherigerBuchstabe = '0';
    int gleich = 0;
    int nett = 0;
    int neuesNett = 0;
    string av[4] = {"ab", "cd", "pq", "xy"};
    string line;
    int counter = 0;
    while (getline(datei, line)) {
        // Part2
        if (part2(line)) neuesNett += 1;

        // Part 1

        vokale = 0;
        gleich = 0;
        for (int i = 0; i < line.length(); i++) {
            aktuellerBuchstabe = line[i];
            if (aktuellerBuchstabe == 'a' || aktuellerBuchstabe == 'e' || aktuellerBuchstabe == 'i' ||
                aktuellerBuchstabe == 'o' || aktuellerBuchstabe == 'u') {
                vokale += 1;
            }
            if (vorherigerBuchstabe == aktuellerBuchstabe) {
                gleich += 1;
            }
            for (int j = 0; j < 4; j++) {
                if (vorherigerBuchstabe == av[j][0] && aktuellerBuchstabe == av[j][1]) {
                    vokale = -500;
                    gleich = -500;
                    counter += 1;
                }
            }
            vorherigerBuchstabe = aktuellerBuchstabe;
        }
        if (vokale >= 3 && gleich >= 1) {
            nett += 1;
        }
    }
    cout << "counter : " << counter << endl;
    cout << "Nette Strings: " << nett << endl;
    cout << "Neues Nett: " << neuesNett << endl;
    return 0;
}