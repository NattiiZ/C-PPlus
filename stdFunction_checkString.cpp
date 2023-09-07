#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num=0, alpha=0, special=0;
    char message[20];
    

    cout << "Enter string : ";
    cin >> message;

    cout << "Count of string = " << strlen(message) << endl;
    for (int i=strlen(message)-1; i<strlen(message); i--)
    {
        cout << i << " = " << message[i] << endl;
        if (isdigit(message[i]))
            num++;
        else if (isalpha(message[i]))
            alpha++;
        else
            special++;
    }
    cout << endl;
    
    cout << "Numberic = " << num << endl;
    cout << "Alphabic = " << alpha << endl;
    cout << "Special = " << special << endl;

    cout << endl;
    system("pause");
    return 0;
}