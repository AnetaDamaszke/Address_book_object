#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZuzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {

    int idZalogowanegoUzytkownika;
    string nazwaPlikuZUzytkownikami;
    vector <Uzytkownik> uzytkownicy;
    PlikZuzytkownikami plikZuzytkownikami;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    void rejestracjaUzytkownika();
    void wypiszUzytkownikow();
    Uzytkownik podajDaneNowegoUzytkownika();
};

#endif
