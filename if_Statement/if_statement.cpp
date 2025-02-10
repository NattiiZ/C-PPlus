#include <iostream>
using namespace std;

int main()
{
    int score, year;


    cout << "Enter score : ";
    cin >> score;
    cout <<  "Enter year : ";
    cin >> year;


    if ((score >= 50) && (year < 4)) 
    {
        cout << "Passed!\n";
        cout << "Year = " << year << endl; 
    }
    else 
    {
        cout << "Failed!\n";
        cout << "Year = " << year << endl; 
    }     


    system("pause");
    return 0;
}