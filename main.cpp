#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    //ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wypiszUzytkownikow();

    return 0;
}