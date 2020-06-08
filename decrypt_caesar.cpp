#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

string decrypt_right(string str, int shift);
string decrypt_left(string str, int shift);

int main()
{
    fstream file;
    file.open("1.txt", ios::in);
    string str, encoded_string, decrypted_string; //deklaruje stringi na tekst wejsciowy i zakodowana wiadomosc
    int shift; //deklaruje int na wartosc przesuniecia
    int max;

    while(!file.eof())
    {
        getline(file, str);
        encoded_string=encoded_string+str;
    }
    file.close();

    for(shift=1;shift<24;shift++)
    {
        decrypted_string = decrypt_right(str, shift);
        cout << shift << "   " << decrypted_string << endl;
    }

    for(shift=(-1);shift>(-24);shift--)
    {
        decrypted_string = decrypt_left(str, shift);
        cout << shift << "   " << decrypted_string << endl;
    }
    cin >> shift;
    decrypted_string=decrypt_right(encoded_string, shift);
    cout << decrypted_string << endl;


    return 0;
}
    string decrypt_right(string str, int shift) //szyfrowanie przesuwajac w prawo
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
                temp[i]=' '; //kolejne iteracje przesuwaja cyfre o odpowiednia liczbe miejsc (shift)
            }
            }
        }

    return temp;
}

string decrypt_left(string str, int shift) //szyfrowanie przesuwajac w lewo
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
        else
        {
            temp[i]=' '; //przepisuje spacje
        }

            }

    return temp;
}
