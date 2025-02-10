#include <iostream>
using namespace std;

int main()
{
    int num[4], num2[4];

    for(int i=0; i<4; i++)
    {
        cout << "Enter number [" << i << "] : ";
        cin >> num[i];
        num2[i] = num[i]*2;
    }
    for(int i=0; i<4; i++)
    {
        cout << "Number [" << i << "] = " << num2[i] << endl;;
    }

    cout << endl;
    system("pause");
    return 0;
}