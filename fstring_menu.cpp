#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int Menu();
void AddStudent(string FN);
void DisplayStudent(string FN);
string CheckGrade(int score);


int main()
{
    const string Filename = "student.dat";
    ifstream InFile;
    ofstream OutFile;
    int c;

    do
    {
        system("cls"); // call external command
        c = Menu();
        switch (c)
        {
            case 1:
                AddStudent(Filename);
                break;
            case 2:
                DisplayStudent(Filename);
                break;
        }
    } while (c != 0);
    cout << "Exit program." << endl;
    

    cout << endl;
    system("pause");
    return 0;
}


int Menu()
{
    string line(25, '=');
    int Choose;

    cout << "Program Add-Display Student Data\n";
    cout << line << endl;
    cout << ": Main Menu :\n";
    cout << line << endl;
    cout << ": 0 - Exit :\n";
    cout << ": 1 - Add Student :\n";
    cout << ": 2 - Display Student :\n";
    cout << line << endl;
    cout << " Enter choose : ";
    cin >> Choose;

    return (Choose);
}


void AddStudent(string FN)
{
    // open file for write and append
    ofstream OutFile(FN.c_str(), ios_base::out | ios_base::app);
    if (OutFile.is_open())
    {
        string Id, Name;
        int score;

        cout << "\n Add Student \n";
        cout << "Enter id : ";
        cin >> Id;
        cout << "Enter name : ";
        cin >> Name;
        cout << "Enter Score : ";
        cin >> score;

        // write data to file student.dat
        OutFile << Id << " " << Name << " " << score << endl;
        OutFile.close();
       
        char Wait;
        cin.get(Wait);
        cout << "\nSaved already ,Press Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}


void DisplayStudent(string FN)
{
    ifstream InFile(FN.c_str(), ios_base::in); // open file for read
    if (InFile.is_open())
    {
        string Id, Name;
        int score;
        string line(32, '=');
        int n = 0;
        cout << "\nList Student\n";
        cout << line << endl;
        cout << " No.  Id  Name     Score  Grade\n";
        cout << line << endl;
       
        // read data from file student.dat
        InFile >> Id >> Name >> score;
        while (!InFile.eof())
        {
            n = n + 1;
            cout << right << setw(3) << n << " : ";
            cout << left << setw(2) << Id;
            cout << "  " << left << setw(8) << Name;
            cout << " " << right << setw(4) << score;
            cout << "     " << left << setw(2) << CheckGrade(score);
            cout << endl;
            InFile >> Id >> Name >> score;
        }
        InFile.close();
        
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}


string CheckGrade(int score)
{
    string grade[] = {"A", "B+", "B", "C+", "C", "D+", "D", "F"}, result;
    int point[] = {80, 75, 70, 65, 60, 55, 50, 0};

    for (int i=0; i<8; i++)
    {
        if (score==point[i])
            result = grade[i];
    }

    return result;
}
