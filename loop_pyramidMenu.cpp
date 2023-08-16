#include <iostream>
using namespace std;

int main()
{   
    char choice;
    int row;


    cout << "Select Menu\n";
    cout << "-----------------------\n";
    cout << "1. Align left\n";
    cout << "1. Align right\n";
    cout << "3. Center\n";
    cout << "4. Exit\n";
    cout << "-----------------------\n";


    do
    {
        cout << "Enter menu No. : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case '1':
            cout << "Enter number of rows : ";
            cin >> row;

            for (int i=0; i < row; i++)
            {
                for (int st=0; st <= i; st++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '2':
            cout << "Enter number of rows : ";
            cin >> row;
            
            for (int i=0; i < row; i++)
            {
                for (int sp=0; sp < (row-i-1); sp++)
                    cout << " ";
                
                for (int st=0; st <= i; st++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '3':
            cout << "Enter number of rows : ";
            cin >> row;

            for (int i=0; i<row; i++)
            {
                for (int sp=0; sp < (row-i-1); sp++)
                    cout << " ";
                
                for (int st=0; st < (2*i+1); st++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '4':
            cout << "... Exit ...";
            break;
        
        default:
            cout << "This option is invalid, try again.\n\n";
            break;
        }
    } while (choice != '4');

    
    cout << endl;
    system("pause");
    return 0;
}