#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "PlikZuzytkownikami.h"
#include "Uzytkownik.h"


void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZuzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {

    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {

    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;

}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for(int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
           cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszUzytkownikow() {

    for(int i=0; i<uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }

}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << "Podaj login: ";
    login = wczytajLinie();

    for(int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

string UzytkownikMenedzer::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    int idZalogowanegoUzytkownika;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = wczytajLinie();

    for(int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    plikZuzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    adresaci.clear();
}
