#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#define Size 100


using namespace std;

//Zadania
//1. Dynamiczny rozmiar tablic
//2. Zapis i odczyt z pliku
//3. Struktura
//4. Poprawienie maskowanie hasła bo backspace czyta jako znak i mi sie to nie podoba (juz mam pomysł)
//5. Jeszcze nie wiem ale napewno cos sie znajdzie :-)


int  Counter=0;

struct CountStudent
{
    int *ID;
    string *Name,*LastName;

};

void AlDynamic()
{
    Name = new string[Size];
    LastName = new string[Size];
    ID = new int[Size];
}


void AddRecords()
{
    cin.ignore();// Jeśli to nie będzie pierwsza wczytywana zmienna, to najlepiej dodaj jeszcze przed getline instrukcję: cin.ignore();  //wyczyść strumień
    cout <<"Podaj Imie : ";
    getline(cin,Name[Counter]); // pobiera całą linie do pamieci
    cout <<"Podaj Nazwisko : ";
    getline(cin,LastName[Counter]);
    while(true)
    {
        cout <<"Podaj ID (6 znakow): ";
        cin.clear();
        cin.sync();
        cin >> ID[Counter];


        int IaD=ID[Counter];
        if((IaD<99999) || (IaD>999999))// id<99999 && id>999999
        {
            cout << "Wprowadziles nieprawidlowa ilosc znakow\n";
        }
        else
            break;
    }

    Counter++;
}

bool Replay()
{
    char Character;
    cout << "Czy chcesz dodac kolejny Rekord(T/N)? : ";
    cin >> Character;
    system("cls");
    if(Character=='T' || Character=='t')
    {

        return true;
    }
    else
        return false;
}

void ShowRecords()
{
    for(int i=0; i<Counter; i++)
    {
        cout <<i+1<<" | "<<Name[i]<<" | "<<LastName[i]<<" | "<<ID[i]<<endl;
    }
}

void RemoveRecords()
{
    int j = 0;
    cout<<"Podaj numer rekordu do usuniecia: ";
    cin>>j;

    for(int i = j; i<Counter; i++) // przepisywanie tablicy
    {
        Name[i-1] = Name[i];
        LastName[i-1] = LastName[i];
        ID[i-1] = ID[i];
    }
    Counter--;
}

void ChangeRecord()
{
    int j = 0;
    cout<<"Podaj numer rekordu do zmiany: ";
    cin>>j;
    if(j<=Counter)
    {
        int aCounter=j-1;
        cin.ignore();
        cout <<"Podaj Imie : ";
        getline(cin,Name[aCounter]);
        cout <<"Podaj Nazwisko : ";
        getline(cin,LastName[aCounter]);
        while(true)
        {
            cout <<"Podaj ID (6 znakow): ";
            cin >> ID[aCounter];

            int IaD=ID[aCounter];
            if((IaD<99999) || (IaD>999999))// id<99999 && id>999999
            {
                cout << "Wprowadziles nieprawidlowa ilosc znakow\n";
            }
            else
                break;
        }
    }
    else
    {
        cout<<"Nie ma takiego rekordu"<<endl;
    }
}

void SortByID(int *tab,string *tab1,string *tab2, int n)
{

    for(int i=1; i<n; i++)    //od 1 bo nie istnieje liczba 0  //powtarza tyle razy ile jest liczb
    {
        for(int j=n-1; j>=1; j--)  // jednorazowe przejscie przez tablice
        {
            if(tab[j]<tab[j-1])// wybiera który jest mniejszy
            {
                int bufor;
                string bufor1;
                string bufor2;
                bufor=tab[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                tab[j-1]=tab[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                tab[j]=bufor;//konczymy zamiane mijescami w tablicy
                bufor1=tab1[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                tab1[j-1]=tab1[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                tab1[j]=bufor1;//konczymy zamiane mijescami w tablicy
                bufor2=tab2[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                tab2[j-1]=tab2[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                tab2[j]=bufor2;//konczymy zamiane mijescami w tablicy

            }
        }
    }

}

void SortByName(int *tab1,string *tab,string *tab2,int n )
{
    {
        for(int i=1; i<n; i++)
        {
            for(int j=n-1; j>=1; j--)
            {
                if(tab[j]<tab[j-1])
                {
                    int bufor1;
                    string bufor;
                    string bufor2;
                    bufor=tab[j-1];
                    tab[j-1]=tab[j];
                    tab[j]=bufor;
                    bufor1=tab1[j-1];
                    tab1[j-1]=tab1[j];
                    tab1[j]=bufor1;
                    bufor2=tab2[j-1];
                    tab2[j-1]=tab2[j];
                    tab2[j]=bufor2;
                }
            }
        }
    }
}

void SortByLastName(int *tab1,string *tab,string *tab2,int n )
{
    {
        for(int i=1; i<n; i++)    //od 1 bo nie istnieje liczba 0  //powtarza tyle razy ile jest liczb
        {
            for(int j=n-1; j>=1; j--)  // jednorazowe przejscie przez tablice
            {
                if(tab[j]<tab[j-1])// wybiera który jest mniejszy
                {
                    int bufor1;
                    string bufor;
                    string bufor2;
                    bufor=tab[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                    tab[j-1]=tab[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                    tab[j]=bufor;//konczymy zamiane mijescami w tablicy
                    bufor1=tab1[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                    tab1[j-1]=tab1[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                    tab1[j]=bufor1;//konczymy zamiane mijescami w tablicy
                    bufor2=tab2[j-1];//jesli tab[j-1] jest mniejszy to przey³any jest do bufra
                    tab2[j-1]=tab2[j];//tu przekazuje wartosc z tab[j-1] do tab[j]
                    tab2[j]=bufor2;//konczymy zamiane mijescami w tablicy
                }
            }
        }
    }
}



void Sorting()
{

    char Character;
    while(true)
    {
        cout << "1.Sortowanie po imieniu\n";
        cout << "2.Sortowanie po Nazwisku\n";
        cout << "3.Sortowanie po ID\n";
        cout << "4.Wyjdz z sortowania\n";
        cout << "Dokonaj wyboru : ";
        cin >> Character;

        system("cls");

        switch(Character)
        {
        case '1':
            SortByName(ID,Name,LastName,Counter);
            break;
        case '2':
            SortByLastName(ID,Name,LastName,Counter);
            break;
        case '3':
            SortByID(ID,Name,LastName,Counter);
            break;
        case '4':
            goto TheEnd;

        default:
            cout << "Zle wybrales\n";
            break;
        }
TheEnd:
        break; // wychodzenie z petli
    }
}

void Menu()
{
    char Znak;
    while(true)
    {
        cout <<"\tMENU\n";
        cout <<"1.Dodaj rekord\n";//gotowe
        cout <<"2.Wyswietl rekordy\n";//gotowe
        cout <<"3.Usun rekord\n";//gotowe
        cout <<"4.Sortowanie\n";//gotowe
        cout <<"5.Zmiana rekordu\n";//gotowe
        cout <<"6.Wyjscie z bazy\n";//gotowe
        cout <<"Dokonaj wyboru : ";
        cin >> Znak;
        system("cls");
        switch(Znak)
        {
        case '1':
            AddRecords();
            while(true)
            {
                if(Replay()== true)
                    AddRecords();
                else
                    break;
            }
            break;
        case '2':
            ShowRecords();
            break;
        case '3':
            RemoveRecords();
            break;
        case '4':
            Sorting();
            break;
        case '5':
            ChangeRecord();
            system("cls");
            break;
        case '6':
            delete [] ID;
            delete [] Name;
            delete [] LastName;
            exit(0);
            break;
        default:
            system("cls");

            cout << "Zle wybrales\n";
            break;
        }
    }
}



void SysLog() //bacsapce zle dziala
{
    string Login;
    string Paswd;
    char c;
repeat:

    cout <<" Login : ";
    cin.clear();
    cin.sync();
    cin >> Login;
    cout <<" Password : ";
    cin.clear();
    cin.sync();
    for(int i=0; i<20; i++)
    {
        c=getch();
        if(c=='\r')
            break;
        cout<<"*";
        Paswd+=c;
    }

    if(Login=="Admin" && Paswd=="1234")
    {
        cout<<endl;
        cout << "Witaj uzytkowniku!!!";
        Sleep(2000);
    }
    else
    {
        system("cls");
        cout<<" Niepoprawne haslo lub login\n";
        goto repeat;
    }
}

int main()
{


    cout << "Witaj w studenckiej bazie danych." << endl;
    Sleep(2000);
    system("cls");
    SysLog();
    system("cls");
    AlDynamic();
    Menu();

    return 0;
}



