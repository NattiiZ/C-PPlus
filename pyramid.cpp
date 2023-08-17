#include <iostream>
using namespace std;

int main()
{   
    char choice;
    int num;


    cout << "Select Menu\n\n";
    cout << "1. Align left\n";
    cout << "2. Align right\n";
    cout << "3. Center\n";
    cout << "4. Exit\n\n";


    do
    {
        cout << "Enter menu : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case '1':
            cout << "Enter number : ";
            cin >> num;

            for (int i=0; i<num; i++)
            {
                for (int k=0; k <= i; k++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '2':
            cout << "Enter number : ";
            cin >> num;
            
            for (int i=0; i<num; i++)
            {
                for (int j=0; j < (num-i-1); j++)
                    cout << " ";
                
                for (int k=0; k <= i; k++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '3':
            cout << "Enter number : ";
            cin >> num;

            for (int i=0; i<num; i++)
            {
                for (int j=0; j < (num-i-1); j++)
                    cout << " ";
                
                for (int k=0; k < (2*i+1); k++)
                    cout << "*";

                cout << endl;
            }
            cout << endl;
            break;

        case '4':
            cout << "Exit ...";
            break;
        
        default:
            break;
        }
    } while (choice != '4');

    
    cout << endl;
    system("pause");
    return 0;
}
