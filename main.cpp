#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>


using namespace std;

struct Adresat
{
    int ID;
    string imie, nazwisko, adres, email, telefon;
};

int zapisanie(vector<Adresat> &adresaci, int &rekord)
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
    osoba.ID=rekord;
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

void wyszukaniePoImieniu(vector<Adresat> adresaci)
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
        if (adresaci[i].imie==imie)
        {
            cout<<"ID: "<<adresaci[i].ID<<endl;
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

void wyszukaniePoNazwisku(vector<Adresat> adresaci)
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
        if (adresaci[i].nazwisko==nazwisko)
        {
            cout<<"ID: "<<adresaci[i].ID<<endl;
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


void wyswietlenieWszystkichAdresatow(vector<Adresat> adresaci)
{
    int i=0;
    while(i<adresaci.size())
    {
        cout<<"ID: "<<adresaci[i].ID<<endl;
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

int wyszukaniePoID(vector<Adresat> adresaci)
{
    int edytowaneID;
    int i=0;

    system("cls");
    cout<<"KSIAZKA ADRESOWA"<<endl;
    cout<<"0 - powrot do menu glownego"<<endl;
    cout<<"Podaj numer ID szukanego adresata."<<endl;
    cout<<"Numer ID:";
    cin>>edytowaneID;

    if (edytowaneID==0)
    {
        return 0;
    }
    while(i<adresaci.size())
    {
        if (adresaci[i].ID==edytowaneID)
        {
            cout<<"---"<<endl;
            cout<<"Adresat:"<<endl;
            cout<<"Imie: "<<adresaci[i].imie<<endl;
            cout<<"Nazwisko: "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].telefon<<endl;
            return edytowaneID;
        }
        else
        {
            i++;
        }
    }
    cout<<"Nie ma w ksiazce adresata o takim ID."<<endl;
    system("pause");
    return 0;
}

int usuniecieAdresata(vector<Adresat> &adresaci, int ID_znalezionegoAdresata)
{
    int i=0;
    int j=0;
    char wybor;

    while(i<adresaci.size())
    {
        if (adresaci[i].ID==ID_znalezionegoAdresata)
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
        return ID_znalezionegoAdresata;
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


void edycjaAdresata(vector<Adresat> &adresaci, int ID_znalezionegoAdresata)
{
    string imie, nazwisko, adres, email, telefon;
    int i=0;
    int j=0;
    char wybor;

    while(i<adresaci.size())
    {
        if (adresaci[i].ID==ID_znalezionegoAdresata)
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

int odczytPliku(vector<Adresat> &adresaci,  int &rekord)
{
    fstream plik;
    string linia, slowoTemp;
    vector<string> temp;
    plik.open("ksiazka_adresowa_z_danymi.txt", ios::in);
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
    else
    {
        cout<<"Nie mozna pobrac danych z pliku z adresami."<<endl;
        system("pause");
    }
    plik.close();

    Adresat osoba;
    for(int i=0; i<temp.size(); i=i+6)
    {
        osoba.ID=atoi(temp[i].c_str());
        osoba.imie=temp[i+1];
        osoba.nazwisko=temp[i+2];
        osoba.adres=temp[i+3];
        osoba.email=temp[i+4];
        osoba.telefon=temp[i+5];
        adresaci.push_back(osoba);
        rekord=atoi(temp[i].c_str());
    }
    temp.clear();
    return rekord;
}


void zapisPliku(vector<Adresat> &adresaci)
{
    fstream plik;
    plik.open("ksiazka_adresowa_z_danymi.txt", ios::out);
    if (plik.good())
    {
        int i=0;
        while(i<adresaci.size())
        {
            plik<<adresaci[i].ID<<'|';
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

int main()
{
    vector<Adresat> adresaci;
    int ID_znalezionegoAdresata=0;
    int rekord=0;
    char wybor;

    odczytPliku(adresaci, rekord);

    while(true)
    {
        system("cls");
        cout<<"KSIAZKA ADRESOWA"<<endl;
        cout<<"1.Dodaj adresata"<<endl;
        cout<<"2.Wyszukaj po imieniu"<<endl;
        cout<<"3.Wyszukaj po nazwisku"<<endl;
        cout<<"4.Wyswietl wszystkich adresatow"<<endl;
        cout<<"5.Usun adresata"<<endl;
        cout<<"6.Edytuj adresata"<<endl;
        cout<<"9.Zakoncz program"<<endl;
        cout<<"Twoj wybor:";
        cin>>wybor;

        if (wybor=='1')
        {
            rekord=zapisanie(adresaci, rekord);
            zapisPliku(adresaci);
        }
        else if (wybor=='2')
        {
            wyszukaniePoImieniu(adresaci);
        }
        else if (wybor=='3')
        {
            wyszukaniePoNazwisku(adresaci);
        }
        else if (wybor=='4')
        {
            wyswietlenieWszystkichAdresatow(adresaci);
        }
        else if (wybor=='5')
        {
            ID_znalezionegoAdresata=wyszukaniePoID(adresaci);
            if (ID_znalezionegoAdresata!=0)
            {
                ID_znalezionegoAdresata=usuniecieAdresata(adresaci, ID_znalezionegoAdresata);
                zapisPliku(adresaci);
            }
        }
        else if (wybor=='6')
        {
            ID_znalezionegoAdresata=wyszukaniePoID(adresaci);
            if (ID_znalezionegoAdresata!=0)
            {
                edycjaAdresata(adresaci, ID_znalezionegoAdresata);
                zapisPliku(adresaci);
            }
        }
        else if(wybor=='9')
        {
            exit(0);
        }
        else
        {
            cout<<"Nie ma takiej opcji w menu."<<endl;
            system("pause");
        }
    }
    return 0;
}
