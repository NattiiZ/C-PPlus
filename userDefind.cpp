#include <iostream>
using namespace std;

// ----------- Function Prototype -----------
// void Add(int n1, int n2);
int Sum(int n1, int n2);
// void Sub(int n1, int n2);
int Sub(int n1, int n2);
// void Mul(int n1, int n2);
int Mul(int n1, int n2);


int main()
{
    int num1, num2;

    for (int i=1; i<=3; i++)
    {
        cout << "Input number 1 : ";
        cin >> num1;
        cout << "Input number 2 : ";
        cin >> num2;

        // ----------- Function Calling -----------
        int sum, sub, mul;

        sum = Sum(num1, num2);
        sub = Sub(num1, num2);
        mul = Mul(num1, num2);

        cout << "Result of Sum = " << sum << endl;
        cout << "Result of Sub = " << sub << endl;
        cout << "Result of Mul = " << mul << endl;
        cout << endl;
    }


    cout << endl;
    system("pause");
    return 0;
}

// ----------- Function Definition -----------
// void Add(int n1, int n2)
int Sum(int n1, int n2)
{
    int sum;
    sum = n1+n2;
    // cout << "Result of Sum = " << sum << endl;
    return(sum);
}

int Sub(int n1, int n2)
{
    int sub;
    sub = n1-n2;
    // cout << "Result of Sub = " << sub << endl;
    return(sub);
}

int Mul(int n1, int n2)
{
    int mul;
    mul = n1*n2;
    // cout << "Result of Mul = " << mul << endl;
    return(mul);
}