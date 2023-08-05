#include <iostream>
using namespace std;

int main()
{   
    char chr1, chr2, chr3, a = 'A', b = 'B', c = 'C';
    int chA, chB, chC , result;


    cout << "Enter character 1 (A,B,C) : ";
    cin >> chr1;
    cout << "Enter character 2 (A,B,C) : ";
    cin >> chr2;
    cout << "Enter character 3 (A,B,C) : ";
    cin >> chr3;
    cout << endl;


    switch (chr1)
    {
        case 'A':
            chr1 = a;
            chA = 10;
            cout << "A = " << chA <<", ";

            break;
        case 'B':
            chr1 = b;
            chA = 20;
            cout << "B = " << chA <<", ";
            break;
        case 'C':
            chr1 = c;
            chA = 30;
            cout << "C = " << chA <<", ";
            break;
        default:
            cout << "\"" << chr1 << "\" is not (A,B,C)!" << endl;
            return 1;
    }

    switch (chr2)
    {
        case 'A':
            chr2 = a;
            chB = 10;
            cout << "A = " << chB <<", ";
            break;
        case 'B':
            chr2 = b;
            chB = 20;
            cout << "B = " << chB <<", ";
            break;
        case 'C':
            chr2 = c;
            chB = 30;
            cout << "C = " << chB <<", ";
            break;
        default:
            cout << "\"" << chr2 << "\" is not (A,B,C)!" << endl;
            return 1;
    }

    switch (chr3)
    {
        case 'A':
            chr3 = a;
            chC = 10;
            cout << "A = " << chC;
            break;
        case 'B':
            chr3 = b;
            chC = 20;
            cout << "B = " << chC;
            break;
        case 'C':
            chr3 = c;
            chC = 30;
            cout << "C = " << chC;
            break;
        default:
            cout << "\"" << chr3 << "\" is not (A,B,C)!" << endl;
            return 1;
    }
    cout << endl;

    result = chA + chB + chC;
    cout << chr1 << " + " << chr2 << " + " << chr3 << " = ";
    cout << chA << " + " << chB << " + " << chC << " = " << result << endl;
    

    cout << endl;
    system("pause");
    return 0;
}