#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;


class Uzytkownik
{
public:
    Uzytkownik(int=0, string="", string="", int=0, int=0);

    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    int iloscUzytkownikow;

    int rejestracjaUzytkownika(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow);
    int logowanieUzytkownika(vector<Uzytkownik> uzytkownicy);

    friend int zmianaHaslaUzytkownika(vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika);
    friend void zapisPlikuUzytkownicy(vector<Uzytkownik> uzytkownicy);
    friend void odczytPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &iloscUzytkownikow);
    friend Uzytkownik pobierzDaneUzytkownika(string daneUzytkownikaOddzielonePionowymiKreskami, int &iloscUzytkownikow);

    ~Uzytkownik();

private:
    int idUzytkownika;
    string nazwa;
    string haslo;
};
