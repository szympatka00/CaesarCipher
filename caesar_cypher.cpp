#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string encrypt_right(string str, int shift);
string encrypt_left(string str, int shift);

int main()
{
    string str, encoded_string; //deklaruje stringi na tekst wejsciowy i zakodowana wiadomosc
    int shift; //deklaruje int na wartosc przesuniecia

    cout << "Text: ";
    getline(cin, str); //podbieram tekst do zaszyfrowania od uzytkownika

    cout << endl <<"Shift value: " << endl;
    cin >> shift; //podbieram wartosc przesuniecia

    if (shift == 0) //w przypadku bezsensownej wartosci przesuniecia (0)
    {
        cout << "Your shift value is 0 - it's nonsense. Please write a reasonable number." << endl;
        cin >> shift;
    }

    if (shift>0) //gdy szyfruje przesuwajac w prawo
    {
        encoded_string = encrypt_right(str, shift);
    }
    else if (shift<0) //gdy szyfruje przesuwajac w lewo
    {
        encoded_string = encrypt_left(str, shift);
    }
    cout << endl <<"Encoded text: " << encoded_string << endl; //wyswietlanie zaszyfrowanego tekstu

    return 0;
}

string encrypt_right(string str, int shift) //szyfrowanie przesuwajac w prawo
{
    string temp = str;
    int length;

    length = (int)temp.length(); //dlugosc wprowadzonej wiadomosci - kazdy znak bedzie przesuwany o dana wartosc

    for (int i = 0; i < length; i++)
    {
        if (isalpha(temp[i])) //sprawdzam czy element stringu jest litera
        {
            for (int j = 0; j < shift; j++)
            {
                if (temp[i] == 'z') // przypadek, gdy w poczatkowym stringu jest element konczacy alfabet - przywracamy tablice do poczatku
                {
                    temp[i] = 'a';
                }
                else if (temp[i] == 'Z')
                {
                    temp[i] = 'A';
                }
                else
                {
                    temp[i]++; //przesuwanie kazdej litery o dana wartosc shift
                }
            }
        }
        else //przypadki, gdy element wprowadzonego tekstu nie jest litera
        {
            for (int j=0; j < shift; j++)
            {
                if (temp[i]== '9') // przypadek, gdy w poczatkowym stringu jest element koñczacy tablice numerów (9)- przywracamy tablice do poczatku (0). Z jakiegos powodu mi nie dziala, nie udalo mi sie dojsc czemu, ale moze to byc wina CodeBlocks.
                {
                    temp[i]='0';
                }
                else if (temp[i]==' ')
                {
                    temp[i]=' '; //przepisuje spacje
                }
                else
                {
                    temp[i]++; //kolejne iteracje przesuwaja cyfre o odpowiednia liczbe miejsc (shift)
                }
            }
        }
    }

    return temp;
}

string encrypt_left(string str, int shift) //szyfrowanie przesuwajac w lewo
{
    shift=abs(shift);
    string temp = str;
    int length;

    length = (int)temp.length();

    for (int i = 0; i < length; i++)
    {
        if (isalpha(temp[i])) //sprawdzam czy element stringu jest litera
        {
            for (int j = 0; j < shift; j++)
            {
                if (temp[i] == 'a') // przypadek, gdy w poczatkowym stringu jest element konczacy alfabet - przywracamy tablice do poczatku
                {
                    temp[i] = 'z';
                }
                else if (temp[i] == 'A')
                {
                    temp[i] = 'Z';
                }
                else
                {
                    temp[i]--;
                }
            }
        }
        else if (temp[i]==' ')
        {
            temp[i]=' '; //przepisuje spacje
        }
        else
        {
            for (int j=0; j < shift; j++)
            {
                if (temp[i]== 0) // przypadek, gdy w poczatkowym stringu jest element konczacy tablice numerów (9)- przywracamy tablice do poczatku (0). Z jakiegos powodu mi nie dziala, nie udalo mi siê dojsc czemu, ale moze to byc wina CodeBlocks.
                {
                    temp[i]= 9;
                }
                else
                {
                    temp[i]--; //kolejne iteracje przesuwaja cyfre o odpowiednia liczbe miejsc
                }
            }
        }
    }

    return temp;
}

