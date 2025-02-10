#include <iostream>
using namespace std;

unsigned long Factorial1(int Number);
unsigned long Factorial2(int Number);

int main()
{
    int Value;

    cout << "Enter integer number (0-20) : ";
    cin >> Value;

    unsigned long Fac;

    Fac = Factorial1(Value);
    cout << "Factorial1 of " << Value << " is ";
    cout << Fac << endl;
    Fac = Factorial2(Value);
    cout << "Factorial2 of " << Value << " is ";
    cout << Fac << endl;
    
    cout << endl;
    system("pause");
    return 0;
}

unsigned long Factorial1(int Number)
{
    unsigned long Fac = 1;
    for( int N = 1 ; N <= Number ; N++)
    Fac *= N;
    return(Fac);
}

unsigned long Factorial2(int Number)
{
    unsigned long Fac = 1;
    cout << Number << endl;
    if (Number > 1) 
        return(Number * Factorial2(Number - 1));
    else 
        return 1;
}