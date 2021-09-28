#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "Adresat.h"
#include "PlikZuzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    vector <Adresat> adresaci;
    PlikZuzytkownikami plikZuzytkownikami;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    string wczytajLinie();

public:
    UzytkownikMenedzer(string nazwaPlikuZuzytkownikami) : plikZuzytkownikami(nazwaPlikuZuzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZuzytkownikami.wczytajUzytkownikowZpliku();
    };
    void rejestracjaUzytkownika();
    void wypiszUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
