#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszUzytkownikow() {

    uzytkownikMenedzer.wypiszUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {

    uzytkownikMenedzer.wylogujUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {

    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {

    adresatMenedzer.wyswietlWszystkichAdresatow();
}
