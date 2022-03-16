#include <iostream>
#include <fstream>
#include <map>
#include <string>
// #include "gtest/gtest.h"

using namespace std;

/*short LShift(short a, int b){
    return (short)(a<<b);
} */

int main() {
    ifstream file("C:\\Users\\Max\\CLionProjects\\AdventOfCode\\2015_Tag7\\input.txt");
    if (!file.is_open()) {
        cerr << "Fehler: Datei konnte nicht geöffnet werden" << endl;
        return 0;
    }

    string zeile;
    map<string, unsigned short> Namen;
    //map <string, short> Namen;
    while (getline(file, zeile)) {
        string substring;
        string variable1, variable2, variable3;
        short anzahl;

        // Modus finden
        if (zeile.find("NOT", 0) != string::npos) {

            //String aufbrechen
            substring = zeile.substr(4);
            variable1 = substring.substr(0, substring.find(' '));
            substring = substring.substr(substring.find(' ') + 4);
            variable2 = substring.substr(0, substring.find('\r'));

            //Überprüfen ob es Zahlen oder Strings sind, und dementsprechend rechnen
            if (isdigit(variable1[0])) {
                Namen[variable2] = (~stoi(variable1));
            } else {
                Namen.insert({variable1,0});
                Namen[variable2] = (~Namen[variable1]);
            }

        } else if (zeile.find("AND", 0) != string::npos) {

            variable1 = zeile.substr(0, zeile.find(' '));
            substring = zeile.substr(zeile.find(' ') + 5);
            variable2 = substring.substr(0, substring.find(' '));
            substring = substring.substr(substring.find(' ') + 4);
            variable3 = substring.substr(0, substring.find('\r'));

            if (isdigit(variable1[0])) {
                Namen.insert({variable2,0});
                Namen[variable3] = (stoi(variable1) & Namen[variable2]);
            } else if (isdigit(variable2[0])) {
                Namen.insert({variable1,0});
                Namen[variable3] = (Namen[variable1] & stoi(variable2));
            } else {
                Namen.insert({variable1,0});
                Namen.insert({variable2,0});
                Namen[variable3] = (Namen[variable1] & Namen[variable2]);
            }

        } else if (zeile.find("OR", 0) != string::npos) {

            variable1 = zeile.substr(0, zeile.find(' '));
            substring = zeile.substr(zeile.find(' ') + 4);
            variable2 = substring.substr(0, substring.find(' '));
            substring = substring.substr(substring.find(' ') + 4);
            variable3 = substring.substr(0, substring.find('\r'));

            if (isdigit(variable1[0])) {
                Namen.insert({variable2,0});
                Namen[variable3] = (stoi(variable1) | Namen[variable2]);
            } else if (isdigit(variable2[0])) {
                Namen.insert({variable1,0});
                Namen[variable3] = (Namen[variable1] | stoi(variable2));
            } else {
                Namen.insert({variable1,0});
                Namen.insert({variable2,0});
                Namen[variable3] = (Namen[variable1] | Namen[variable2]);
            }

        } else if (zeile.find("RSHIFT", 0) != string::npos) {

            variable1 = zeile.substr(0, zeile.find(' '));
            substring = zeile.substr(zeile.find(' ') + 8);
            anzahl = stoi(substring.substr(0, substring.find(' ')));
            substring = substring.substr(substring.find(' ') + 4);
            variable3 = substring.substr(0, substring.find('\r'));

            if (isdigit(variable1[0])) {
                Namen[variable3] = (stoi(variable1) >> anzahl);
            } else {
                Namen.insert({variable1,0});
                Namen[variable3] = (Namen[variable1] >> anzahl);
            }

        } else if (zeile.find("LSHIFT", 0) != string::npos) {

            variable1 = zeile.substr(0, zeile.find(' '));
            substring = zeile.substr(zeile.find(' ') + 8);
            anzahl = stoi(substring.substr(0, substring.find(' ')));
            substring = substring.substr(substring.find(' ') + 4);
            variable3 = substring.substr(0, substring.find('\r'));

            if (isdigit(variable1[0])) {
                Namen[variable3] = (stoi(variable1)) << anzahl;
            } else {
                Namen.insert({variable1,0});
                Namen[variable3] = (Namen[variable1]) << anzahl;
            }

        } else {

            variable1 = zeile.substr(0, zeile.find(' '));
            substring = zeile.substr(zeile.find(' ') + 4);
            variable2 = substring.substr(0, substring.find('\r'));

            if (isdigit(variable1[0])) {

                Namen[variable2] = (stoi(variable1));

            } else {

                Namen.insert({variable1,0});
                Namen[variable2] = Namen[variable1];

            }

        }

    }

     for (map<string, unsigned short>::iterator itr = Namen.begin(); itr != Namen.end(); itr++) {
        cout <<"Name: "<< itr->first
       <<" Wert: "<< itr->second << endl;
    }

}

// Was ist a?

// werte werden überschrieben -->


//if(Namen.find(variable1) == Namen.end()){
// nicht gefunden
// }else{
// gefunden
// }


// Auseinander bröseln
// pair<>({});???
// Bitweise short oder int?
// Was wenn beide Variablen sind (and/Or)?