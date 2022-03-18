#include <iostream>
#include <fstream>
#include <map>
#include <string>
// #include "gtest/gtest.h"

using namespace std;

map<string, unsigned short> Namen;

//Funktionen deklarieren

bool inputCheck(string);

void NOT(string);

void IS(string);

void AND(string);

void OR(string);

void RSHIFT(string);

void LSHIFT(string);

int main() {

    //Inputdatei öffnen
    ifstream file("C:\\Users\\Max\\CLionProjects\\AdventOfCode\\2015_Tag7\\input.txt");
    if (!file.is_open()) {
        cerr << "Fehler: Datei konnte nicht geöffnet werden" << endl;
        return 0;
    }
    int anzahl = 0, iteration;
    bool kondition = true;
    string zeile;
    while (kondition) {
        iteration = 0;
        anzahl ++;
        while (getline(file, zeile)) {

            // Modus finden
            if (zeile.find("NOT", 0) != string::npos) {
                NOT(zeile);
            } else if (zeile.find("AND", 0) != string::npos) {
                AND(zeile);
            } else if (zeile.find("OR", 0) != string::npos) {
                OR(zeile);
            } else if (zeile.find("RSHIFT", 0) != string::npos) {
                RSHIFT(zeile);
            } else if (zeile.find("LSHIFT", 0) != string::npos) {
                LSHIFT(zeile);
            } else {
                IS(zeile);
            }
            iteration ++;
        }
        if(inputCheck("a")){
           kondition = false;
        }
        file.clear();
        file.seekg(ios::beg);
        cout << "Anzahl:Iterationen =  " << anzahl << " : " << iteration<< endl;
    }
    //Ausgabe der Map
    for (map<string, unsigned short>::iterator itr = Namen.begin(); itr != Namen.end(); itr++) {
        cout << "Name: " << itr->first
             << " Wert: " << itr->second << endl;
    }
    file.close();
    return 0;
}

bool inputCheck(string name) {
    if (Namen.find(name) == Namen.end() && !isdigit(name[0]))
        return false;
    else return true;
}

void NOT(string zeile) {
    string substring, variable1, variable3;

    //Zeile aufteilen
    substring = zeile.substr(4);
    variable1 = substring.substr(0, substring.find(' '));
    substring = substring.substr(substring.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    //Inputs valide?
    if (!inputCheck(variable1)) {
        return;
    }

    //Überprüfen ob es Zahlen oder Strings sind, und dementsprechend rechnen
    if (isdigit(variable1[0])) {
        Namen[variable3] = (~stoi(variable1));
    } else {
        Namen[variable3] = (~Namen[variable1]);
    }

}

void IS(string zeile) {
    string substring, variable1, variable3;

    variable1 = zeile.substr(0, zeile.find(' '));
    substring = zeile.substr(zeile.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    if (!inputCheck(variable1)) {
        return;
    }

    if (isdigit(variable1[0])) {
        Namen[variable3] = (stoi(variable1));

    } else {
        Namen[variable3] = Namen[variable1];
    }
}

void AND(string zeile) {
    string substring, variable1, variable2, variable3;

    variable1 = zeile.substr(0, zeile.find(' '));
    substring = zeile.substr(zeile.find(' ') + 5);
    variable2 = substring.substr(0, substring.find(' '));
    substring = substring.substr(substring.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    if (!inputCheck(variable1) || !inputCheck(variable2)) {
        return;
    }

    if (isdigit(variable1[0])) {
        Namen[variable3] = (stoi(variable1) & Namen[variable2]);
    } else if (isdigit(variable2[0])) {
        Namen[variable3] = (Namen[variable1] & stoi(variable2));
    } else {
        Namen[variable3] = (Namen[variable1] & Namen[variable2]);
    }
}

void OR(string zeile) {
    string substring, variable1, variable2, variable3;

    variable1 = zeile.substr(0, zeile.find(' '));
    substring = zeile.substr(zeile.find(' ') + 4);
    variable2 = substring.substr(0, substring.find(' '));
    substring = substring.substr(substring.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    if (!inputCheck(variable1) || !inputCheck(variable2)) {
        return;
    }

    if (isdigit(variable1[0])) {
        Namen[variable3] = (stoi(variable1) | Namen[variable2]);
    } else if (isdigit(variable2[0])) {
        Namen[variable3] = (Namen[variable1] | stoi(variable2));
    } else {
        Namen[variable3] = (Namen[variable1] | Namen[variable2]);
    }
}

void RSHIFT(string zeile) {
    string substring, variable1, variable3;
    short anzahl;

    variable1 = zeile.substr(0, zeile.find(' '));
    substring = zeile.substr(zeile.find(' ') + 8);
    anzahl = stoi(substring.substr(0, substring.find(' ')));
    substring = substring.substr(substring.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    if (!inputCheck(variable1)) {
        return;
    }

    if (isdigit(variable1[0])) {
        Namen[variable3] = (stoi(variable1) >> anzahl);
    } else {
        Namen[variable3] = (Namen[variable1] >> anzahl);
    }
}

void LSHIFT(string zeile) {
    string substring, variable1, variable3;
    short anzahl;

    variable1 = zeile.substr(0, zeile.find(' '));
    substring = zeile.substr(zeile.find(' ') + 8);
    anzahl = stoi(substring.substr(0, substring.find(' ')));
    substring = substring.substr(substring.find(' ') + 4);
    variable3 = substring.substr(0, substring.find('\r'));

    if (!inputCheck(variable1)) {
        return;
    }

    if (isdigit(variable1[0])) {
        Namen[variable3] = (stoi(variable1)) << anzahl;
    } else {
        Namen[variable3] = (Namen[variable1]) << anzahl;
    }
}

//weiter machen, bis Zeile 7 wahr ist
//ifstream liest nicht neu aus?
//file.close() nach vorne verschieben

