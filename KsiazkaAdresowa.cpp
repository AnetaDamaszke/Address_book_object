#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"

KsiazkaAdresowa::KsiazkaAdresowa() {

    uzytkownikMenedzer.wczytajUzytkownikowZpliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszUzytkownikow() {

    uzytkownikMenedzer.wypiszUzytkownikow();
}
