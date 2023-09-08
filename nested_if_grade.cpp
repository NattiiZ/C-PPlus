#include <iostream>
using namespace std;

int main()
{
    int score, year;   
    
    
    cout << "Enter Score : ";
    cin >> score;
    cout <<  "Enter year : ";
    cin >> year;


    cout << "You grade = ";
    if (score >= 80) cout << "A\n";
    else if (score >= 70) cout << "B\n";
    else if (score >= 60) cout << "C\n";
    else if (score >= 50) cout << "D\n";
    else 
    {
        cout << "F\n";
        cout << "Year = " << year << endl; 
    }


    system("pause");
    return 0;
}