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

int rejestracjaUzytkownika(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
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

int logowanieUzytkownika(vector<Uzytkownik> uzytkownicy)
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

int zmianaHaslaUzytkownika(vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
    string haslo;

    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    cout<<"Podaj nowe haslo:"<<endl;
    cin>>haslo;

    if (haslo=="0")
    {
        return 0;
    }

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo=haslo;
            cout<<"Haslo zostalo zmienione.";
            Sleep(1000);
        }
    }
    return idZalogowanegoUzytkownika;
}

int zapisanieAdresata(vector<Adresat> &adresaci, int &idOstatniegoAdresata,  int idZalogowanegoUzytkownika)
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

    idOstatniegoAdresata++;
    osoba.idAdresata=idOstatniegoAdresata;
    osoba.idUzytkownika=idZalogowanegoUzytkownika;
    osoba.imie=imie;
    osoba.nazwisko=nazwisko;
    osoba.adres=adres;
    osoba.email=email;
    osoba.telefon=telefon;
    adresaci.push_back(osoba);

    cout<<"Adresat zapisany."<<endl;
    system("pause");
    return idOstatniegoAdresata;
}

void wyszukanieAdresataPoImieniu(vector<Adresat> adresaci)
{
    string imie;
    int i=0;
    int ileImion=0;

    cout<<"Podaj imie szukanego adresata: ";
    cin.clear();
    cin.sync();
    getline(cin, imie);

    while(i<adresaci.size())
    {
        if (adresaci[i].imie==imie)
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
        cout<<"Nie ma w ksiazce adresata o podanym imieniu."<<endl;
    }
    system("pause");
}

void wyszukanieAdresataPoNazwisku(vector<Adresat> adresaci)
{
    string nazwisko;
    int i=0;
    int ileNazwisk=0;

    cout<<"Podaj nazwisko szukanego adresata: ";
    cin.clear();
    cin.sync();
    getline(cin, nazwisko);

    while(i<adresaci.size())
    {
        if (adresaci[i].nazwisko==nazwisko)
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
        cout<<"Nie ma w ksiazce adresata o podanym nazwisku."<<endl;
    }
    system("pause");
}

void wyswietlenieWszystkichAdresatow(vector<Adresat> adresaci)
{
    int i=0;
    while(i<adresaci.size())
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
    cout<<endl<<"Czy na pewno chcesz usunac tego adresata? <T/N>";
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
    cout<<"1 - Imie"<<endl;
    cout<<"2 - Nazwisko"<<endl;
    cout<<"3 - Adres"<<endl;
    cout<<"4 - Email"<<endl;
    cout<<"5 - Telefon"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    while(true)
    {
        cout<<endl<<"Twoj wybor:";
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

string pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int pobierzIdUzytkownikaZLiniiAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    int pozycjaIdUzytkownika = daneAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = stoi(pobierzLiczbe(daneAdresataOddzielonePionowymiKreskami, pozycjaIdUzytkownika));
    return idUzytkownika;
}

int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = stoi(pobierzLiczbe(daneAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat osoba;
    string jednaInformacjaAdresata;
    int numerInformacjiAdresata=1;

    for (int i=0; i<daneAdresataOddzielonePionowymiKreskami.length(); i++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[i]!='|')
        {
            jednaInformacjaAdresata+=daneAdresataOddzielonePionowymiKreskami[i];
        }
        else
        {
            switch(numerInformacjiAdresata)
            {
            case 1:
                osoba.idAdresata=atoi(jednaInformacjaAdresata.c_str());
                break;
            case 2:
                osoba.idUzytkownika=atoi(jednaInformacjaAdresata.c_str());
                break;
            case 3:
                osoba.imie=jednaInformacjaAdresata;
                break;
            case 4:
                osoba.nazwisko=jednaInformacjaAdresata;
                break;
            case 5:
                osoba.adres=jednaInformacjaAdresata;
                break;
            case 6:
                osoba.email=jednaInformacjaAdresata;
                break;
            case 7:
                osoba.telefon=jednaInformacjaAdresata;
                break;
            }
            jednaInformacjaAdresata = "";
            numerInformacjiAdresata++;
        }
    }
    return osoba;
}

int odczytPlikuAdresaci(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    fstream plik;
    string daneAdresataOddzielonePionowymiKreskami;
    string daneOstaniegoAdresataWPliku = "";
    Adresat osoba;
    int idOstatniegoAdresata=0;

    plik.open("Adresaci.txt", ios::in);
    if(plik.good()==true)
    {
        while(getline(plik,daneAdresataOddzielonePionowymiKreskami))
        {
            if (idZalogowanegoUzytkownika==pobierzIdUzytkownikaZLiniiAdresata(daneAdresataOddzielonePionowymiKreskami))
            {
                osoba = pobierzDaneAdresata(daneAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(osoba);
            }
            daneOstaniegoAdresataWPliku=daneAdresataOddzielonePionowymiKreskami;
        }
    }
    plik.close();

    if (daneOstaniegoAdresataWPliku!="")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

void usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void dodanieAdresataDoPliku(vector<Adresat> adresaci)
{
    fstream plik, plikTymczasowy;
    string wczytanaLinia = "";
    int i=0;

    plik.open("Adresaci.txt", ios::in);
    plikTymczasowy.open("Adresaci_tymczasowy.txt", ios::out | ios::app);

    if (plik.good()==true)
    {
        while (getline(plik, wczytanaLinia))
        {
            plikTymczasowy<<wczytanaLinia<<endl;
        }

        i=adresaci.size()-1;
        plikTymczasowy<<adresaci[i].idAdresata<<'|';
        plikTymczasowy<<adresaci[i].idUzytkownika<<'|';
        plikTymczasowy<<adresaci[i].imie<<'|';
        plikTymczasowy<<adresaci[i].nazwisko<<'|';
        plikTymczasowy<<adresaci[i].adres<<'|';
        plikTymczasowy<<adresaci[i].email<<'|';
        plikTymczasowy<<adresaci[i].telefon<<'|'<<endl;

        plik.close();
        plikTymczasowy.close();
        usunPlik("Adresaci.txt");
        zmienNazwePliku("Adresaci_tymczasowy.txt", "Adresaci.txt");
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku z adresami."<<endl;
        system("pause");
    }
}

void zapisPlikuAdresaciPoUsunieciuAdresata(int znalezione_idAdresata, vector<Adresat> &adresaci)
{
    fstream plik, plikTymczasowy;
    string wczytanaLinia = "";

    plik.open("Adresaci.txt", ios::in);
    plikTymczasowy.open("Adresaci_tymczasowy.txt", ios::out | ios::app);

    if (plik.good()==true)
    {
        while (getline(plik, wczytanaLinia))
        {
            if (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)==znalezione_idAdresata)
            {
                continue;
            }
            else
            {
                plikTymczasowy<<wczytanaLinia<<endl;
            }
        }
        plik.close();
        plikTymczasowy.close();
        usunPlik("Adresaci.txt");
        zmienNazwePliku("Adresaci_tymczasowy.txt", "Adresaci.txt");
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku z adresami."<<endl;
        system("pause");
    }
}

void zapisPlikuAdresaciPoEdycjiAdresata(int znalezione_idAdresata, vector<Adresat> &adresaci)
{
    fstream plik, plikTymczasowy;
    string wczytanaLinia = "";
    int i = 0;

    plik.open("Adresaci.txt", ios::in);
    plikTymczasowy.open("Adresaci_tymczasowy.txt", ios::out | ios::app);

    if (plik.good()==true)
    {
        while (getline(plik, wczytanaLinia))
        {
            if (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)==znalezione_idAdresata)
            {
                while(i<adresaci.size())
                {
                    if (adresaci[i].idAdresata==znalezione_idAdresata)
                    {
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
                plikTymczasowy<<adresaci[i].idAdresata<<'|';
                plikTymczasowy<<adresaci[i].idUzytkownika<<'|';
                plikTymczasowy<<adresaci[i].imie<<'|';
                plikTymczasowy<<adresaci[i].nazwisko<<'|';
                plikTymczasowy<<adresaci[i].adres<<'|';
                plikTymczasowy<<adresaci[i].email<<'|';
                plikTymczasowy<<adresaci[i].telefon<<'|'<<endl;
            }
            else
            {
                plikTymczasowy<<wczytanaLinia<<endl;
            }
        }
        plik.close();
        plikTymczasowy.close();
        usunPlik("Adresaci.txt");
        zmienNazwePliku("Adresaci_tymczasowy.txt", "Adresaci.txt");
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku z adresami."<<endl;
        system("pause");
    }
}

Uzytkownik pobierzDaneUzytkownika(string daneUzytkownikaOddzielonePionowymiKreskami, int &iloscUzytkownikow)
{
    Uzytkownik osoba;
    string jednaInformacjaUzytkownika;
    int numerInformacjiUzytkownika=1;

    for (int i=0; i<daneUzytkownikaOddzielonePionowymiKreskami.length(); i++)
    {
        if (daneUzytkownikaOddzielonePionowymiKreskami[i]!='|')
        {
            jednaInformacjaUzytkownika+=daneUzytkownikaOddzielonePionowymiKreskami[i];
        }
        else
        {
            if (numerInformacjiUzytkownika==1)
            {
                osoba.idUzytkownika=atoi(jednaInformacjaUzytkownika.c_str());
                iloscUzytkownikow=atoi(jednaInformacjaUzytkownika.c_str());
            }
            else if (numerInformacjiUzytkownika==2)
            {
                osoba.nazwa=jednaInformacjaUzytkownika;
            }
            else if (numerInformacjiUzytkownika==3)
            {
                osoba.haslo=jednaInformacjaUzytkownika;
            }
            jednaInformacjaUzytkownika="";
            numerInformacjiUzytkownika++;
        }
    }
    return osoba;
}

void odczytPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &iloscUzytkownikow)
{
    fstream plik;
    string daneUzytkownikaOddzielonePionowymiKreskami;
    Uzytkownik osoba;
    plik.open("Uzytkownicy.txt", ios::in);
    if(plik.good()==true)
    {
        while(getline(plik,daneUzytkownikaOddzielonePionowymiKreskami))
        {
            osoba=pobierzDaneUzytkownika(daneUzytkownikaOddzielonePionowymiKreskami, iloscUzytkownikow);
            uzytkownicy.push_back(osoba);
        }
    }
    plik.close();
}

void zapisPlikuUzytkownicy(vector<Uzytkownik> uzytkownicy)
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good()==true)
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
        cout<<"Nie mozna zapisac danych do pliku z uzytkownikami."<<endl;
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
    cout<<"---"<<endl;
    cout<<"Twoj wybor:";
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
    int idOstatniegoAdresata=0;
    int iloscUzytkownikow=0;

    vector<Adresat> adresaci;
    int znalezione_idAdresata=0;
    char wybor;

    odczytPlikuUzytkownicy(uzytkownicy, iloscUzytkownikow);

    while(true)
    {
        if (idZalogowanegoUzytkownika==0)
        {
            wyswietlenieMenuLogowania(wybor);

            if (wybor=='1')
            {
                iloscUzytkownikow=rejestracjaUzytkownika(uzytkownicy, iloscUzytkownikow);
                zapisPlikuUzytkownicy(uzytkownicy);
            }
            else if (wybor=='2')
            {
                idZalogowanegoUzytkownika=logowanieUzytkownika(uzytkownicy);
            }
            else if(wybor=='9')
            {
                exit(0);
            }
        }
        else
        {
            if (adresaci.empty() == true)
            {
                idOstatniegoAdresata = odczytPlikuAdresaci(adresaci, idZalogowanegoUzytkownika);
            }

            wyswietlenieMenuKsiazkiAdresowej(wybor);

            if (wybor=='1')
            {
                idOstatniegoAdresata=zapisanieAdresata(adresaci, idOstatniegoAdresata, idZalogowanegoUzytkownika);
                dodanieAdresataDoPliku(adresaci);
            }
            else if (wybor=='2')
            {
                wyszukanieAdresataPoImieniu(adresaci);
            }
            else if (wybor=='3')
            {
                wyszukanieAdresataPoNazwisku(adresaci);
            }
            else if (wybor=='4')
            {
                wyswietlenieWszystkichAdresatow(adresaci);
            }
            else if (wybor=='5')
            {
                znalezione_idAdresata=wyszukanieAdresataPo_idAdresata(adresaci, idZalogowanegoUzytkownika);
                if (znalezione_idAdresata!=0)
                {
                    znalezione_idAdresata=usuniecieAdresata(adresaci, znalezione_idAdresata);
                    zapisPlikuAdresaciPoUsunieciuAdresata(znalezione_idAdresata, adresaci);
                }
            }
            else if (wybor=='6')
            {
                znalezione_idAdresata=wyszukanieAdresataPo_idAdresata(adresaci, idZalogowanegoUzytkownika);
                if (znalezione_idAdresata!=0)
                {
                    edycjaAdresata(adresaci, znalezione_idAdresata);
                    zapisPlikuAdresaciPoEdycjiAdresata(znalezione_idAdresata, adresaci);
                }
            }
            else if(wybor=='7')
            {
                zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                zapisPlikuUzytkownicy(uzytkownicy);
            }
            else if(wybor=='8')
            {
                idZalogowanegoUzytkownika=0;
                adresaci.clear();
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
