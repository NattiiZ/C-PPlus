#include <iostream>
#include <string>
using namespace std;

void ParseName(string &FirstName,string &LastName, const string FullName);
void Check_Char(string FirstName);

int main()
{
    string Name = "Stroustrup, Bjarne";
    string LastName, FirstName;


    ParseName(FirstName,LastName,Name);
    Name = FirstName + " " + LastName;
    cout << "Name : " << Name << endl;
    Check_Char(FirstName);


    system ("pause");
    return 0;
}


void ParseName(string &FirstName,string &LastName, const string FullName)
{
    int I = FullName.find(",");
    LastName = FullName.substr(0,I);
    FirstName = FullName.substr(I+2,FullName.size());
}

void Check_Char(string FirstName)
{
    int lower=0, upper=0, special=0;

    for (int i=0; i<=FirstName.length()-1; i++)
    {
        cout << FirstName.at(i) << endl;
        if (islower(FirstName.at(i)))
            lower++;
        else if (isupper(FirstName.at(i)))
            upper++;
        else
            special++;
    }
    cout << "Lower Character = " << lower << endl;
    cout << "Upper Character = " << lower << endl;
    cout << "Special Character = " << lower << endl;
}