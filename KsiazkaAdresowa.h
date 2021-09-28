#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZuzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZuzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
    };
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wypiszUzytkownikow();
    void wylogujUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif
