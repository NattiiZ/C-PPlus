#include <iostream>
#include <iomanip>
using namespace std;

void Input(int &No_std ,int quizz[20], int Mid[20], int Final[20]);
void ViewAll(int No_std ,int quizz[20], int Mid[20], int Final[20]);
void ViewID(int No_std ,int quizz[20], int Mid[20], int Final[20]);


int main()
{
    char menu;
    int No_std;
    int quizz[20], Mid[20], Final[20];


    do
    {
        cout << setfill('=') << setw(30) << "\n";
        cout << setfill(' ') << setw(13) << " " << "MENU\n";
        cout << setfill('=') << setw(30) << "\n" << endl;

        cout << "1. Input student records\n";
        cout << "2. View all students records\n";
        cout << "3. Show a student by ID\n";
        cout << "4. Exit\n";
        cout << endl << setfill('-') << setw(30) << "\n";
        cout << "Choose menu : ";
        cin >> menu;

        switch (menu)
        {
            case '1':
                system("cls");
                Input(No_std ,quizz, Mid, Final);
                system("cls");
                break;

            case '2':
                system("cls");
                ViewAll(No_std ,quizz, Mid, Final);
                system("cls");
                break;

            case '3':
                system("cls");
                ViewID(No_std ,quizz, Mid, Final);
                system("cls");
                break;

            case '4':
                cout << "\nExit ...\n";
                break;
            
            default:
                cout << "Invalid menu, please choose again.\n";
                break;
        }
        
    } while (menu!='4');
    
    
    cout << endl;
    system("pause");
    return 0;
}

// --------------------- Functions --------------------- //


void Input(int &No_std ,int quizz[20], int Mid[20], int Final[20])
{   
    cout << "Enter Number of Student : ";
    cin >> No_std;
    cout << endl;

    for(int i=0; i<No_std; i++)
    {
        cout << "Student " << i+1 << endl;
        cout << " Input Quizz : ";
        cin >> quizz[i];
        cout << " Input Midterm : ";
        cin >> Mid[i];
        cout << " Input Final : ";
        cin >> Final[i];
        cout << endl;
    }
    cout << endl;
    system("pause");
}


void ViewAll(int No_std ,int quizz[20], int Mid[20], int Final[20])
{
    cout << setfill('-') << setw(38) << "\n";
    cout << "Student    Quizz    Midterm     Final";
    cout << endl << setfill('-') << setw(38) << "\n";
    for(int i=0; i<No_std; i++)
    {
        cout << right << setw(4) << setfill(' ') << i+1 << right << setw(11) << setfill(' ') << quizz[i] << right << setw(10) << setfill(' ')<< Mid[i] << right << setw(11) << setfill(' ') << Final[i] << endl;
    }
    cout << setfill('-') << setw(38) << "\n";
    system("pause");
}


void ViewID(int No_std ,int quizz[20], int Mid[20], int Final[20])
{
    int ID;

    cout << "Input ID : ";
    cin >> ID;
    for(int i=0; i<No_std; i++)
    {
        if (ID==i+1)
        {
            cout << setfill('-') << setw(38) << "\n";
            cout << "Student    Quizz    Midterm     Final";
            cout << endl << setfill('-') << setw(38) << "\n";
            for(int i=0; i<No_std; i++)
            {
                cout << right << setw(4) << setfill(' ') << i+1 << right << setw(11) << setfill(' ') << quizz[i] << right << setw(10) << setfill(' ')<< Mid[i] << right << setw(11) << setfill(' ') << Final[i] << endl;
            }
            cout << setfill('-') << setw(38) << "\n";
            cout << endl;
            system("pause");
            break;
        }
        else
        {
            cout << "\nYour ID is not found\n\n";
            system("pause");
            break;
        }
        system("pause");
    }
}
