#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

struct Adresat
{
    int idAdresata, idUzytkownika;
    string imie, nazwisko, adres, email, telefon;
};

int rejestracja(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;
    Uzytkownik osoba;
    int i=0;

    cout<<"Podaj nazwe uzytkownika:"<<endl;
    cin>>nazwa;

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

int logowanie(vector<Uzytkownik> uzytkownicy)
{
    string nazwa, haslo;
    cout<<"Podaj nazwe:"<<endl;
    cin>>nazwa;
    int i=0;
    while (i<uzytkownicy.size())
    {
        if (uzytkownicy[i].nazwa==nazwa)
        {
            for (int proby=0; proby<3; proby++)
            {
                cout<<"Podaj haslo. Pozostalo "<<3-proby<<" proby."<<endl;
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

void zmianaHasla(vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
    string haslo;
    cout<<"Podaj nowe haslo:"<<endl;
    cin>>haslo;
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo=haslo;
            cout<<"Haslo zostalo zminione.";
            Sleep(1000);
        }
    }
}

int zapisanieAdresata(vector<Adresat> &adresaci, int &rekord,  int idZalogowanegoUzytkownika)
{
    string imie, nazwisko, adres, email, telefon;
    Adresat osoba;

    cout<<"Podaj imie osoby: ";
    cin.clear();
    cin.sync();
    getline(cin, imie);
    cout<<"Podaj nazwisko osoby:";
    cin.clear();
    cin.sync();
    getline(cin, nazwisko);
    cout<<"Podaj adres osoby: ";
    cin.clear();
    cin.sync();
    getline(cin, adres);
    cout<<"Podaj email osoby: ";
    cin.clear();
    cin.sync();
    getline(cin, email);
    cout<<"Podaj numer telefonu osoby: ";
    cin.clear();
    cin.sync();
    getline(cin, telefon);

    rekord+=1;
    osoba.idAdresata=rekord;
    osoba.idUzytkownika=idZalogowanegoUzytkownika;
    osoba.imie=imie;
    osoba.nazwisko=nazwisko;
    osoba.adres=adres;
    osoba.email=email;
    osoba.telefon=telefon;
    adresaci.push_back(osoba);

    cout<<"Adresat zapisany."<<endl;
    system("pause");

    return rekord;
}

void wyszukanieAdresataPoImieniu(vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    string imie;
    int i=0;
    int ileImion=0;

    cout<<"Podaj imie szukanej osoby:"<<endl;
    cin.clear();
    cin.sync();
    getline(cin, imie);

    while(i<adresaci.size())
    {
        if (adresaci[i].imie==imie && adresaci[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            cout<<"id Adresata: "<<adresaci[i].idAdresata<<endl;
            cout<<"id Uzytkownika: "<<adresaci[i].idUzytkownika<<endl;
            cout<<"Imie: "<<adresaci[i].imie<<endl;
            cout<<"Nazwisko: "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].telefon<<endl;
            cout<<"---"<<endl;
            i++;
            ileImion++;
        }
        else
        {
            i++;
        }
    }
    if (ileImion==0)
    {
        cout<<"Nie ma w ksiazce osoby o podanym imieniu."<<endl;
    }
    system("pause");
}

void wyszukanieAdresataPoNazwisku(vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    string nazwisko;
    int i=0;
    int ileNazwisk=0;

    cout<<"Podaj nazwisko szukanej osoby:"<<endl;
    cin.clear();
    cin.sync();
    getline(cin, nazwisko);

    while(i<adresaci.size())
    {
        if (adresaci[i].nazwisko==nazwisko && adresaci[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            cout<<"id Adresata: "<<adresaci[i].idAdresata<<endl;
            cout<<"id Uzytkownika: "<<adresaci[i].idUzytkownika<<endl;
            cout<<"Imie: "<<adresaci[i].imie<<endl;
            cout<<"Nazwisko: "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].telefon<<endl;
            cout<<"---"<<endl;
            i++;
            ileNazwisk++;
        }
        else
        {
            i++;
        }
    }
    if (ileNazwisk==0)
    {
        cout<<"Nie ma w ksiazce osoby o podanym nazwisku."<<endl;
    }
    system("pause");
}

void wyswietlenieWszystkichAdresatow(vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    int i=0;
    while(i<adresaci.size())
    {
        if (adresaci[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            cout<<"id Adresata: "<<adresaci[i].idAdresata<<endl;
            cout<<"id Uzytkownika: "<<adresaci[i].idUzytkownika<<endl;
            cout<<"Imie: "<<adresaci[i].imie<<endl;
            cout<<"Nazwisko: "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].telefon<<endl;
            cout<<"---"<<endl;
            i++;
        }
        else
        {
            i++;
        }
    }
    system("pause");
}

int wyszukanieAdresataPo_idAdresata(vector<Adresat> adresaci, int idZalogowanegoUzytkownika)
{
    int wprowadzone_idAdresata;
    int i=0;

    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    cout<<"Podaj identyfikator szukanego adresata."<<endl;
    cout<<"Identyfikator numer:";
    cin>>wprowadzone_idAdresata;

    if (wprowadzone_idAdresata==0)
    {
        return 0;
    }
    while(i<adresaci.size())
    {
        if (adresaci[i].idAdresata==wprowadzone_idAdresata && adresaci[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            cout<<"---"<<endl;
            cout<<"Adresat:"<<endl;
            cout<<"Imie: "<<adresaci[i].imie<<endl;
            cout<<"Nazwisko: "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].telefon<<endl;
            return wprowadzone_idAdresata;
        }
        else
        {
            i++;
        }
    }
    cout<<"Nie ma w Ksiazce adresata o takim identyfikatorze."<<endl;
    system("pause");
    return 0;
}

int usuniecieAdresata(vector<Adresat> &adresaci, int znalezione_idAdresata)
{
    int i=0;
    int j=0;
    char wybor;

    while(i<adresaci.size())
    {
        if (adresaci[i].idAdresata==znalezione_idAdresata)
        {
            j=i;
            break;
        }
        else
        {
            i++;
        }
    }
    cout<<"Czy na pewno chcesz usunac tego adresata? <T/N>";
    cin>>wybor;
    if (wybor=='T'||wybor=='t')
    {
        adresaci.erase(adresaci.begin()+j);
        cout<<"Adresat usuniety."<<endl;
        system("pause");
        return znalezione_idAdresata;
    }
    else if (wybor=='N'||wybor=='n')
    {
        cout<<"Powrot do menu glownego..."<<endl;
        Sleep(2000);
        return 0;
    }
    else
    {
        cout<<"Nie ma takiej opcji w menu."<<endl;
        system("pause");
        return 0;
    }
}

void edycjaAdresata(vector<Adresat> &adresaci, int znalezione_idAdresata)
{
    string imie, nazwisko, adres, email, telefon;
    int i=0;
    int j=0;
    char wybor;

    while(i<adresaci.size())
    {
        if (adresaci[i].idAdresata==znalezione_idAdresata)
        {
            j=i;
            break;
        }
        else
        {
            i++;
        }
    }
    cout<<"---"<<endl;
    cout<<"Wybierz dane do edycji:"<<endl;
    cout<<"1 - imie"<<endl;
    cout<<"2 - nazwisko"<<endl;
    cout<<"3 - adres"<<endl;
    cout<<"4 - email"<<endl;
    cout<<"5 - numer telefonu"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    while(true)
    {
        cout<<"Twoj wybor:";
        cin>>wybor;
        if (wybor=='1')
        {
            cout<<"Podaj nowe imie osoby:";
            cin.clear();
            cin.sync();
            getline(cin, imie);
            adresaci[j].imie=imie;
            cout<<"Zmiana wprowadzona"<<endl;
        }
        else if (wybor=='2')
        {
            cout<<"Podaj nowe nazwisko osoby:";
            cin.clear();
            cin.sync();
            getline(cin, nazwisko);
            adresaci[j].nazwisko=nazwisko;
            cout<<"Zmiana wprowadzona"<<endl;
        }
        else if (wybor=='3')
        {
            cout<<"Podaj nowy adres osoby:";
            cin.clear();
            cin.sync();
            getline(cin, adres);
            adresaci[j].adres=adres;
            cout<<"Zmiana wprowadzona"<<endl;
        }
        else if (wybor=='4')
        {
            cout<<"Podaj nowy email osoby:";
            cin.clear();
            cin.sync();
            getline(cin, email);
            adresaci[j].email=email;
            cout<<"Zmiana wprowadzona"<<endl;
        }
        else if (wybor=='5')
        {
            cout<<"Podaj nowy numer telefonu osoby:";
            cin.clear();
            cin.sync();
            getline(cin, telefon);
            adresaci[j].telefon=telefon;
            cout<<"Zmiana wprowadzona"<<endl;
        }
        else if (wybor=='0')
        {
            break;
        }
        else cout<<"Nie ma takiej opcji w menu."<<endl;
    }
}

int odczytPlikuAdresaci(vector<Adresat> &adresaci,  int &rekord)
{
    fstream plik;
    string linia, slowoTemp;
    vector<string> temp;
    plik.open("Adresaci.txt", ios::in);
    if(plik.good())
    {
        while(getline(plik,linia))
        {
            istringstream input;
            input.str(linia);
            for(slowoTemp; getline(input, slowoTemp,'|');)
                temp.push_back(slowoTemp);
        }
    }
    plik.close();

    Adresat osoba;
    for(int i=0; i<temp.size(); i=i+7)
    {
        osoba.idAdresata=atoi(temp[i].c_str());
        osoba.idUzytkownika=atoi(temp[i+1].c_str());
        osoba.imie=temp[i+2];
        osoba.nazwisko=temp[i+3];
        osoba.adres=temp[i+4];
        osoba.email=temp[i+5];
        osoba.telefon=temp[i+6];
        adresaci.push_back(osoba);
        rekord=atoi(temp[i].c_str());
    }
    temp.clear();
    return rekord;
}

void zapisPlikuAdresaci(vector<Adresat> adresaci)
{
    fstream plik;
    plik.open("Adresaci.txt", ios::out);
    if (plik.good())
    {
        int i=0;
        while(i<adresaci.size())
        {
            plik<<adresaci[i].idAdresata<<'|';
            plik<<adresaci[i].idUzytkownika<<'|';
            plik<<adresaci[i].imie<<'|';
            plik<<adresaci[i].nazwisko<<'|';
            plik<<adresaci[i].adres<<'|';
            plik<<adresaci[i].email<<'|';
            plik<<adresaci[i].telefon<<'|'<<endl;
            i++;
        }
        plik.close();
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku z adresami."<<endl;
        system("pause");
    }
}

int odczytPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &iloscUzytkownikow)
{
    fstream plik;
    string linia, slowoTemp;
    vector<string> temp;
    plik.open("Uzytkownicy.txt", ios::in);
    if(plik.good())
    {
        while(getline(plik,linia))
        {
            istringstream input;
            input.str(linia);
            for(slowoTemp; getline(input, slowoTemp,'|');)
                temp.push_back(slowoTemp);
        }
    }
    plik.close();

    Uzytkownik osoba;
    for(int i=0; i<temp.size(); i=i+3)
    {
        osoba.idUzytkownika=atoi(temp[i].c_str());
        osoba.nazwa=temp[i+1];;
        osoba.haslo=temp[i+2];
        uzytkownicy.push_back(osoba);
        iloscUzytkownikow=atoi(temp[i].c_str());
    }
    temp.clear();
    return iloscUzytkownikow;
}

void zapisPlikuUzytkownicy(vector<Uzytkownik> uzytkownicy)
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good())
    {
        int i=0;
        while(i<uzytkownicy.size())
        {
            plik<<uzytkownicy[i].idUzytkownika<<'|';
            plik<<uzytkownicy[i].nazwa<<'|';
            plik<<uzytkownicy[i].haslo<<'|'<<endl;
            i++;
        }
        plik.close();
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku z adresami."<<endl;
        system("pause");
    }
}

char wyswietlenieMenuLogowania(char &wybor)
{
    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"1.Rejestracja uzytkownika"<<endl;
    cout<<"2.Logowanie uzytkownika"<<endl;
    cout<<"9.Zakoncz program"<<endl;
    cin>>wybor;
    return wybor;
}

char wyswietlenieMenuKsiazkiAdresowej(char &wybor)
{
    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"1.Dodaj adresata"<<endl;
    cout<<"2.Wyszukaj po imieniu"<<endl;
    cout<<"3.Wyszukaj po nazwisku"<<endl;
    cout<<"4.Wyswietl wszystkich adresatow"<<endl;
    cout<<"5.Usun adresata"<<endl;
    cout<<"6.Edytuj adresata"<<endl;
    cout<<"---"<<endl;
    cout<<"7.Zmiana hasla uzytkownika"<<endl;
    cout<<"8.Wylogowanie uzytkownika"<<endl;
    cout<<"---"<<endl;
    cout<<"Twoj wybor:";
    cin>>wybor;
    return wybor;
}

int main()
{
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika=0;
    int iloscUzytkownikow = 0;

    vector<Adresat> adresaci;
    int znalezione_idAdresata=0;
    int rekord=0;
    char wybor;

    odczytPlikuUzytkownicy(uzytkownicy, iloscUzytkownikow);
    odczytPlikuAdresaci(adresaci, rekord);

    while(true)
    {
        if (idZalogowanegoUzytkownika==0)
        {
            wyswietlenieMenuLogowania(wybor);

            if (wybor=='1')
            {
                iloscUzytkownikow=rejestracja(uzytkownicy, iloscUzytkownikow);
                zapisPlikuUzytkownicy(uzytkownicy);
            }
            else if (wybor=='2')
            {
                idZalogowanegoUzytkownika=logowanie(uzytkownicy);
            }
            else if(wybor=='9')
            {
                exit(0);
            }
        }
        else
        {
            wyswietlenieMenuKsiazkiAdresowej(wybor);

            if (wybor=='1')
            {
                rekord=zapisanieAdresata(adresaci, rekord, idZalogowanegoUzytkownika);
                zapisPlikuAdresaci(adresaci);
            }
            else if (wybor=='2')
            {
                wyszukanieAdresataPoImieniu(adresaci, idZalogowanegoUzytkownika);
            }
            else if (wybor=='3')
            {
                wyszukanieAdresataPoNazwisku(adresaci, idZalogowanegoUzytkownika);
            }
            else if (wybor=='4')
            {
                wyswietlenieWszystkichAdresatow(adresaci, idZalogowanegoUzytkownika);
            }
            else if (wybor=='5')
            {
                znalezione_idAdresata=wyszukanieAdresataPo_idAdresata(adresaci, idZalogowanegoUzytkownika);
                if (znalezione_idAdresata!=0)
                {
                    znalezione_idAdresata=usuniecieAdresata(adresaci, znalezione_idAdresata);
                    zapisPlikuAdresaci(adresaci);
                }
            }
            else if (wybor=='6')
            {
                znalezione_idAdresata=wyszukanieAdresataPo_idAdresata(adresaci, idZalogowanegoUzytkownika);
                if (znalezione_idAdresata!=0)
                {
                    edycjaAdresata(adresaci, znalezione_idAdresata);
                    zapisPlikuAdresaci(adresaci);
                }
            }
            else if(wybor=='7')
            {
                zmianaHasla(uzytkownicy, idZalogowanegoUzytkownika);
                zapisPlikuUzytkownicy(uzytkownicy);
            }
            else if(wybor=='8')
            {
                idZalogowanegoUzytkownika=0;
            }
            else
            {
                cout<<"Nie ma takiej opcji w menu."<<endl;
                system("pause");
            }
        }
    }
    return 0;
}
