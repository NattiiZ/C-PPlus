#include <iostream>
#include <string>
using namespace std;

int main()
{
    char menu;
    float salary, sale, comm, total;


    cout << "=========== Menu ===========\n";
    cout << "1) Input salary\n";
    cout << "2) Input sale\n";
    cout << "3) Report\n";
    cout << "4) Exit\n";
    cout << "---------------------------\n";
    
    do
    {
        cout << "Select menu : ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
            case '1':
            {
                cout << "Input salary : ";
                cin >> salary;
                cout << endl;
                break;
            }
            case '2':
            {
                cout << "Input sale : ";
                cin >> sale;
                
                if (sale>20000)
                    comm = 0.15;
                else if (sale>10000)
                    comm = 0.1;
                else if (sale<=10000)
                    comm = 0.05;

                cout << endl;
                break;
            }
            case '3':
            {
                comm = sale*comm;
                total = salary + comm;

                cout << "***** Report *****\n";
                cout << "Salary\t\t= " << salary << endl;;
                cout << "Sale\t\t= "<< sale << endl;
                cout << "Commission\t= " << comm << endl;
                cout << "Total\t\t= " << total << endl;
                cout << endl;
                break;
            }
            case '4':
            {
                cout << "... Exit ...\n";
                break;
            }
            default:
                cout << "Invalid menu! try again.\n";
                break;
        }

    } while (menu != '4');
    

    cout << endl;
    system("pause");
    return 0;
}