#include <iostream>
#include <string>

using namespace std;

int Summation(int StartNumber=1 ,int EndNumber=10);

int main()
{
    int Start, End;
    
    cout << "Enter start number : ";
    cin >> Start;
    cout << "Enter end number : ";
    cin >> End;
    cout << endl;
    cout << "Summation of Number " << Start << " to " << End;
    cout << " = " << Summation(Start,End) << endl;
    cout << "Summation of Number " << 5 << " to " << 10;
    cout << " = " << Summation(5) << endl;
    cout << "Summation of Number " << 1 << " to " << 10;
    cout << " = " << Summation() << endl;

    cout << endl;
    system("pause");
    return 0;
}

int Summation(int StartNumber, int EndNumber)
{
    long Sum = 0;
    for(int N = StartNumber ; N < EndNumber ; N++)
    Sum += N;
    return Sum;
}