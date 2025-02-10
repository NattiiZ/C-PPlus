#include <iostream>
using namespace std;

int main()
{
    int num1, num2, total = 0;


    cout << "Enter number 1 : ";
    cin >> num1;
    cout << "Enter number 2 : ";
    cin >> num2;
    cout << endl;


    for(int i = 1; i <= num2; i++)
    {
        cout << num1 << " x " << i << " = " << num1 * i << endl;
        total += (num1 * i);
    }
    cout << "Total = " << total << endl;
    cout << "Avg. = " << float(total)/num2 << endl;
    
    cout << endl;
    system("pause");
    return 0;
}