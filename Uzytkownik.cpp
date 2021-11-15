#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik(int idUz, string naz, string has, int idZal, int iloscUzyt)
{
    idUzytkownika=idUz;
    nazwa=naz;
    haslo=has;
    idZalogowanegoUzytkownika=idZal;
    iloscUzytkownikow=iloscUzyt;
}

Uzytkownik::~Uzytkownik()
{
}

int Uzytkownik::rejestracjaUzytkownika(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;
    Uzytkownik osoba;
    int i=0;

    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    cout<<"Podaj nazwe nowego uzytkownika:"<<endl;
    cin>>nazwa;

    if (nazwa=="0")
    {
        return 0;
    }

    while (i<iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa==nazwa)
        {
            cout<<"Taka nazwa uzytkownika juz istnieje. Wpisz inna nazwe."<<endl;
            cin>>nazwa;
            i=0;
        }
        else
        {
            i++;
        }
    }

    cout<<"Podaj haslo uzytkownika:"<<endl;
    cin>>haslo;
    iloscUzytkownikow+=1;
    osoba.idUzytkownika=iloscUzytkownikow;
    osoba.nazwa=nazwa;
    osoba.haslo=haslo;
    uzytkownicy.push_back(osoba);
    cout<<"Konto zalozone."<<endl;
    system("pause");
    return iloscUzytkownikow;
}

int Uzytkownik::logowanieUzytkownika(vector<Uzytkownik> uzytkownicy)
{
    string nazwa, haslo;

    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    cout<<"Podaj nazwe:"<<endl;
    cin>>nazwa;

    if (nazwa=="0")
    {
        return 0;
    }

    int i=0;
    while (i<uzytkownicy.size())
    {
        if (uzytkownicy[i].nazwa==nazwa)
        {
            for (int proby=0; proby<3; proby++)
            {
                cout<<"Podaj haslo."<<endl<<"Pozostalo "<<3-proby<<" proby."<<endl;
                cin>>haslo;
                if (uzytkownicy[i].haslo==haslo)
                {
                    cout<<"Zalogowales sie.";
                    Sleep(1000);
                    return uzytkownicy[i].idUzytkownika;
                }
            }
            cout<<"Podales bledne haslo 3 razy. Poczekaj trzy sekundy."<<endl;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout<<"Nie ma uzytkownika o takiej nazwie."<<endl;
    Sleep(1000);
    return 0;
}
