#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wybor;

    while (true)
    {
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //edytujAdresata(adresaci);
                break;
            case '7':
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }
    }

    return 0;
}


//-----TESTY
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

int __main()
{
    AdresatMenedzer adresatMenedzer("Adresaci.txt", 1);
    PlikZAdresatami plikZAdresatami("Adresaci.txt");

    plikZAdresatami.usunWybranaLinieWPliku(3);

}
