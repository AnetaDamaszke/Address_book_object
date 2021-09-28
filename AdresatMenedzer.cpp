#include "AdresatMenedzer.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

int AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawIdAdresata(idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(wczytajLinie());
    //adresat.imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(wczytajLinie());
    //adresat.nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNrTelefonu(wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(wczytajLinie());

    return adresat;
}

string AdresatMenedzer::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    Adresat adresat;

    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i=0; i < adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresat);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:         " << adresat.pobierzIdAdresata() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNrTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
