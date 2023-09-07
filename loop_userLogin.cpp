#include <iostream>
#include <string>
using namespace std;

int main()
{
    char menu, choice;
    string userR, passR, userL, passL;


    cout << "=========== User Accout ===========\n";
    cout << "1) Register\n";
    cout << "2) Login\n";
    cout << "Q) Exit\n";
    cout << "---------------------------\n";
    
    do
    {
        cout << "\nEnter menu : ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
            case '1':
            {
                cout << "****** Register ******\n";
                cout << "Input your Username : ";
                cin >> userR;
                cout << "Input your Password : ";
                cin >> passR;
                break;
            }
            case '2':
            {
                do
                {
                    cout << "****** Login ******\n";
                    cout << "Enter Username : ";
                    cin >> userL;
                    cout << "Enter Password : ";
                    cin >> passL;

                    if ((userL == userR) && (passL == passR))
                        cout << "Login success.\n";
                    else
                    {
                        cout << "Login fail.\n\n";
                        cout << "1) Try again.\n2) Main menu\nSelect choice : ";
                        cin >> choice;
                        cout << endl;

                        if (choice == '2')
                        {
                            cout << "=========== User Accout ===========\n";
                            cout << "1) Register\n";
                            cout << "2) Login\n";
                            cout << "Q) Exit\n";
                            cout << "---------------------------\n";
                            break;
                        }
                    }    
                } while ((userL != userR) || (passL != passR));
                break;
            }
            case 'Q':
            {
                cout << "... Exit ...\n";
                break;
            }
            default:
                cout << "Invalid menu! try again.\n";
                break;
        }

    } while (menu != 'Q');
    

    cout << endl;
    system("pause");
    return 0;
}