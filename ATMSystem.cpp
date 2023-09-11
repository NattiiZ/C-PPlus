#include <iostream>
#include <iomanip>
using namespace std;

float update_balance(int command, float amount, float balance);

int main()
{
    int command;
    float balance=10000, amount;

    do
    {
        cout << "Your balance = " << fixed << setprecision(2) << balance << endl;
        cout << "Input command (1. Withdraw, 2. Deposit) : ";
        cin >> command;
        if (command == 0)
            break;
        cout << "Input amount : ";
        cin >> amount;
        balance = update_balance(command,amount,balance);

    } while (command!=0);
    cout << "Exit with 0" << endl;


    cout << endl;
    system("pause");
    return 0;
}

float update_balance(int command, float amount, float balance)
{   
    if (command == 1)
        balance -= amount;
    else if (command == 2)
        balance += amount;

    return(balance);
}
