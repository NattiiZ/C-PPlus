#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;


int GetRightElection();
void RandomElection(int election[7][6], int people);
void ReportElection(int election[7][6], float people);


int main()
{
    char choice;
    int election[7][6], people;
    string line_Eq(45, '=');


    for (int i=0; i<7; i++)
    {
        for (int j=0; j<6; j++)
            election[i][j] = 0;
    }


    do
    {
        cout << line_Eq << endl;
        cout << setw(13) << "" << "Election Main Menu\n";
        cout << line_Eq << endl << endl;

        cout << "1. Input Number of Right Election (1000-5000)\n";
        cout << "2. Random Result Election\n";
        cout << "3. Report Election\n";
        cout << "4. Exit\n";

        cout << "\nEnter choice : ";
        cin >> choice;


        switch (choice)
        {
            case '1':
                people = GetRightElection();
                break;

            case '2':
                RandomElection(election, people);
                break;

            case '3':
                system("cls");
                ReportElection(election, people);
                break;

            case '4':
                cout << "\nExit Program . . .\n";
                break;

            default:
                cout << "\ninvalid choice, try again.\n";
                break;
        }

        cout << endl;
        system("pause");
        system("cls");
    } while (choice!=4);
    


    cout << endl;
    system("pause");
    return 0;
}


// #############################################################################


int GetRightElection()
{
    int people;


    cout << "\nInput Number of Right Election (1000-5000) : ";
    cin >> people;

    if (people>5000)
        people = 5000;
    else if (people<1000)
        people = 1000;
        
    cout << "Number of right election Now to " << people << endl;
    
    return (people);
}

// -----------------------------------------------------------------------------

void RandomElection(int election[7][6], int people)
{
    int vote;

    srand(time(NULL));


    for (int i=0; i<7; i++)
    {
        for (int k=0; k<people; k++)
        {
            vote = rand()%5;
            election[i][vote]++;
            election[i][5]++;
        }
    }

    cout << "\nStart to random";
    for (int i=0; i<3; i++)
    {
        Sleep(300);
        cout << " .";
    }
    Sleep(1000);
    cout << "\nNow finish random\n";
}

// -----------------------------------------------------------------------------

void ReportElection(int election[7][6], float people)
{
    string line_Eq(111, '-');


    cout << "Election Result\n\n";
    cout << line_Eq << endl;
    cout << "| District | No Vote |   %   | No. 1 |   %   | No. 2 |   %   | No. 3 |   %   | No. 4 |   %   | Total |   %    |\n";
    cout << line_Eq << endl;

    for (int i=0; i<7; i++)
    {
        cout << "|" << setw(5) << right << i+1 << setw(6) << "|";

        for (int k=0; k<6; k++)
        {
            cout << setw(((k>0)?6:7)) << right << election[i][k] << setw(((k>0)?2:3)) << "|";
            cout << ((k<5)?"":" ") << setw(6) << right << fixed << setprecision(2) << (election[i][k]*100.0)/people << " |";
        }
        cout << endl;
    }

    cout << line_Eq << endl;
}