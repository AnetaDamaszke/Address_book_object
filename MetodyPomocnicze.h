#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static int wczytajLiczbeCalkowita();
    static char wczytajZnak();
};

#endif
