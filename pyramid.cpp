#include <iostream>
using namespace std;

int main()
{   
    char choice;
    int row;

    cout << "=======================\n\n";
    cout << "Select choice\n\n";
    cout << "1. Align left\n";
    cout << "1. Align right\n";
    cout << "3. Center\n";
    cout << "4. Exit\n";
    cout << endl;

    do
    {
        cout << "Enter choice : ";
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
            break;

        case '4':
            cout << "... Exit ...";
        
        default:
            break;
        }
    } while (choice != '4');

    
    cout << endl;
    system("pause");
    return 0;
}