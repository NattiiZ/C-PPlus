#include <iostream>
using namespace std;

int main()
{
    int year, maxDay;


    cout << "Enter year : ";
    cin >> year;


    if ((year % 400) == 0 || (year % 4) == 0 && (year % 100) != 0) 
    {
        maxDay = 29;
        cout << "In " << year << " is leap year!\n";
    }
    else 
    {
        maxDay = 28;
        cout << "In " << year << " is not leap year!\n"; 
    }     
    cout << "February has " << maxDay << " day.\n";


    system("pause");
    return 0;
}