#include <iostream>
#include <string>
using namespace std;

int main()
{
    char Ch;
    int count = 0;
    string Str;


    cout << "Enter String : ";
    while ((Ch = cin.get()) != '\n')
    {
        count++;
        Str += Ch;

        if (Ch == '.')
            break;
    }
    cout << "\nLength of string (" << Str << ") is ";
    cout << count << endl;


    cout << endl;
    system("pause");
    return(0);
}