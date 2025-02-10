#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Display(string name[3], int num[3][3]);


int main()
{
    int num[3][3];
    string name[3];


    for (int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name : ";
        cin >> name[i];
        for (int k = 0; k < 3; k++)
        {
            string sub;
            if (k == 0)
                sub = "Math";
            else if (k == 1)
                sub = "Science";
            else if (k == 2)
                sub = "English";

            cout << "Enter score " << sub << " : ";
            cin >> num[i][k];
        }
        cout << endl;
    }

    // cout << num << endl;
    // cout << num[0] << endl;
    // cout << num[0][1];

    Display(name, num);    

    cout << endl;
    system("pause");
    return 0;
}

void Display(string name[3], int num[3][3])
{
    cout << "Show score\n\n";
    cout << " Student     Math   Science   English\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << " " << left << setw(5) << name[i];
        for (int k = 0; k < 3; k++)
        {
            cout << right << setw(8) << setfill(' ') << num[i][k] << "  ";
        }
        cout << endl;
    }
}