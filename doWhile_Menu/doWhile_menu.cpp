#include <iostream>
using namespace std;

int main()
{
    char menu;
    int amount, result;

    cout << "========== MENU ==========\n\n";
    cout << "Press 1 : Enter amount\n";
    cout << "Press 2 : Interest 7%\n";
    cout << "Press 3 : Interest 5%\n";
    cout << "Press 0 : Exit\n";
    cout << "--------------------------\n";

    do
    {
        cout << "Enter menu : ";
        cin >> menu;

        if(menu == '1')
            {
                cout << "Enter amount : ";
                cin >> amount;
                cout << endl;
            }
            else if(menu == '2')
            {
                cout << "Enter amount : ";
                cin >> amount;
                result = amount * 0.07;
                cout << "7% of " << amount << " = " << amount + result << endl;
                cout << endl;
            }
            else if(menu == '3')
            {
                cout << "Enter amount : ";
                cin >> amount;
                result = amount * 0.05;
                cout << "5% of " << amount << " = " << amount + result << endl;
                cout << endl;
            }
            else
                cout << "Invalid menu! Please choose again." << endl;
    } 
        while (menu != '0');
            

    cout << endl;
    system("pause");
    return 0;
}