#include <iostream>
using namespace std;

int main()
{
    char menu;
    float balance = 0 ,amount;


    cout << "=========== ATM ===========\n";
    cout << "1) Deposit\n";
    cout << "1) Withdraw\n";
    cout << "1) Balance\n";
    cout << "4) Exit\n";
    cout << "---------------------------\n";
    
    do
    {
        cout << "Please input menu : ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
        case '1':
        {
            cout << "*** Deposit Menu ***\n";
            cout << "Balance " << balance << "$" << endl;
            cout << "Input amount : ";
            cin >> amount;
            balance += amount;
            cout << "Your balance = " << balance << "$" << endl;
            cout << endl;
            break;
        }
        case '2':
        {
            cout << "*** Withdraw Menu ***\n";
            cout << "Balance " << balance << "$" << endl;
            cout << "Input amount : ";
            cin >> amount;
            if (balance<amount)
                cout << "Your balnce no enough.\n";
            else
                balance -= amount;
                cout << "Your balance = " << balance << "$" << endl;
                cout << endl;
            break;
        }
        case '3':
        {
            cout << "*** Balance Menu ***\n";
            cout << "Your balance : " << balance << "$" << endl;
            cout << endl;
            break;
        }
        case '4':
        {
            cout << "... Exit ...\n";
            break;
        }
        default:
            cout << "Invalid menu! try again.";
            break;
        }

    } while (menu != '0');
    



    cout << endl;
    system("pause");
    return 0;
}