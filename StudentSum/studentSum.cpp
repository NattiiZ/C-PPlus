#include <iostream>
#include <iomanip>
using namespace std;

void Input(int &No_std ,int quizz[20], int Mid[20], int Final[20]);
void ViewAll(int No_std ,int quizz[20], int Mid[20], int Final[20], int sum[20]);
void ViewID(int No_std ,int quizz[20], int Mid[20], int Final[20]);
void selectionSort(int arr[], int size);


int main()
{
    char menu;
    int No_std;
    int quizz[20], Mid[20], Final[20], sum[20];


    do
    {
        cout << setfill('=') << setw(30) << "\n";
        cout << setfill(' ') << setw(12) << " " << "MENU\n";
        cout << setfill('=') << setw(30) << "\n" << endl;

        cout << "1. Input student records\n";
        cout << "2. View all students records\n";
        cout << "3. Show a student by ID\n";
        cout << "4. Sort Sum Score\n";
        cout << "5. Exit\n";
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
                ViewAll(No_std ,quizz, Mid, Final, sum);
                system("cls");
                break;

            case '3':
                system("cls");
                ViewID(No_std ,quizz, Mid, Final);
                system("cls");
                break;

            case '4':
                system("cls");
                selectionSort(sum, No_std);
                system("cls");
                break;

            case '5':
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
    system("pause");
}


void ViewAll(int No_std ,int quizz[20], int Mid[20], int Final[20], int sum[20])
{
    int total[]={0, 0, 0};

    cout << setfill('-') << setw(45) << "\n";
    cout << "StdID    Quizz    Midterm    Final       Sum";
    cout << endl << setfill('-') << setw(45) << "\n";
    for(int i=0; i<No_std; i++)
    {
        sum[i] = quizz[i]+Mid[i]+Final[i];
        cout << right << setw(3) << setfill(' ') << i+1 << right << setw(11) << setfill(' ') << quizz[i] << right << setw(10) << setfill(' ')<< Mid[i] << right << setw(10) << setfill(' ') << Final[i] << right << setw(10) << setfill(' ') << sum[i] << endl;
        total[0] += quizz[i];
        total[1] += Mid[i];
        total[2] += Final[i];
    }
    cout << setfill('-') << setw(45) << " " << endl;
    cout << "Total" << setw(9) << setfill(' ') << right << total[0] << setw(10) << setfill(' ') << right << total[1] << setw(10) << setfill(' ') << right << total[2] << endl;
    cout << setfill('-') << setw(45) << " " << endl;
    cout << endl;
    system("pause");
}


void ViewID(int No_std ,int quizz[20], int Mid[20], int Final[20])
{
    int ID;

    cout << "Input ID : ";
    cin >> ID;
    cout << endl;
    for(int i=0; i<No_std; i++)
    {
        if (ID==i+1)
        {
            cout << setfill('-') << setw(38) << "\n";
            cout << "StdID    Quizz    Midterm    Final";
            cout << endl << setfill('-') << setw(35) << "\n";
            for(int i=0; i<No_std; i++)
                cout << right << setw(3) << setfill(' ') << i+1 << right << setw(11) << setfill(' ') << quizz[i] << right << setw(10) << setfill(' ')<< Mid[i] << right << setw(10) << setfill(' ') << Final[i] << endl;
            
            cout << setfill('-') << setw(35) << "\n";
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


void selectionSort(int arr[], int size) 
{
    for (int i=0; i<size-1; i++) 
    {
        int minIndex = i;

        for (int j=i+1; j<size; j++) 
        {
            if (arr[j]>arr[minIndex]) 
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        for (int k=0; k<size; k++)
            cout << arr[k] << endl;
        
        // cout << endl;
    }
    
    system("pause");
}