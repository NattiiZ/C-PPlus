#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    int num[2][3];


    cout << "Enter Array 2D 2x3\n";
    for (int i=0; i<2; i++)
    {
        for (int k=0; k<3; k++)
        {
            cin >> num[i][k];
        }
    }


    cout << "\nTranspose Array 2D 3x2\n";
    for (int i=0; i<3; i++)
    {
        for (int k=0; k<2; k++)
        {
            cout << num[k][i] << " ";
        }
        cout << endl;
    }


    cout << endl;
    system("pause");
    return 0;
}
