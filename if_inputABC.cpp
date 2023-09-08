#include <iostream>
using namespace std;

int main()
{   
    char ch1, ch2, ch3, a = 'A', b = 'B', c = 'C';
    int chA, chB, chC , result;


    cout << "Enter character 1 (A,B,C) : ";
    cin >> ch1;
    cout << "Enter character 2 (A,B,C) : ";
    cin >> ch2;
    cout << "Enter character 3 (A,B,C) : ";
    cin >> ch3;
    cout << endl;


    switch (ch1)
    {
        case 'A':
            ch1 = a;
            chA = 10;
            cout << "A = " << chA <<", ";

            break;
        case 'B':
            ch1 = b;
            chA = 20;
            cout << "B = " << chA <<", ";
            break;
        case 'C':
            ch1 = c;
            chA = 30;
            cout << "C = " << chA <<", ";
            break;
        default:
            cout << "\"" << ch1 << "\" is not (A,B,C)!" << endl;
            return 1;
    }

    switch (ch2)
    {
        case 'A':
            ch2 = a;
            chB = 10;
            cout << "A = " << chB <<", ";
            break;
        case 'B':
            ch2 = b;
            chB = 20;
            cout << "B = " << chB <<", ";
            break;
        case 'C':
            ch2 = c;
            chB = 30;
            cout << "C = " << chB <<", ";
            break;
        default:
            cout << "\"" << ch2 << "\" is not (A,B,C)!" << endl;
            return 1;
    }

    switch (ch3)
    {
        case 'A':
            ch3 = a;
            chC = 10;
            cout << "A = " << chC;
            break;
        case 'B':
            ch3 = b;
            chC = 20;
            cout << "B = " << chC;
            break;
        case 'C':
            ch3 = c;
            chC = 30;
            cout << "C = " << chC;
            break;
        default:
            cout << "\"" << ch3 << "\" is not (A,B,C)!" << endl;
            return 1;
    }
    cout << endl;

    result = chA + chB + chC;
    cout << ch1 << " + " << ch2 << " + " << ch3 << " = ";
    cout << chA << " + " << chB << " + " << chC << " = " << result << endl;
    

    cout << endl;
    system("pause");
    return 0;
}