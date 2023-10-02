#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int num[3][2];

    for (int i=0; i<3; i++)
    {
        for (int k=0; k<2; k++)
        {
            cout << "Enter score ["<< i << "]["<< k << "]: ";
            cin >> num[i][k];
        }
        cout << endl;
    }

    // cout << num << endl;
    // cout << num[0] << endl;
    // cout << num[0][1];
    

    cout << "Show score\n\n";
    cout << "Student   Math   Science\n";
    for (int i=0; i<3; i++)
    {
        cout << "   " << i+1;
        for (int k=0; k<2; k++)
            cout << right << setw(9) << setfill(' ') << num[i][k];
        
        cout << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}