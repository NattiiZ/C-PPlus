#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Display(string name[3], int num[3][3]);
void selectionSort2D(int arr[][3], int rows, int cols, string name[3]);
string checkGrade(int score);
float checkGPA(string Grade);

int main()
{
    int score[3][3];
    string name[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name : ";
        cin >> name[i];
        for (int k = 0; k < 3; k++)
        {
            string sub;
            if (k == 0)
                sub = "Math";
            else if (k == 1)
                sub = "Science";
            else if (k == 2)
                sub = "English";

            cout << "Enter score " << sub << " : ";
            cin >> score[i][k];
        }
        cout << endl;
    }

    Display(name, score);
    cout << endl;
    system("pause");
    return 0;
}

void Display(string name[3], int score[3][3])
{
    float GPA = 0;
    string Grade;

    cout << "\nShow score\n";
    cout << setfill('-') << setw(50) << "\n";
    cout << "No.  Student     Math   Science   English     GPA\n";
    cout << setfill('-') << setw(50) << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << setfill(' ') << " " << i + 1 << "   " << left << setw(12) << name[i];
        for (int k = 0; k < 3; k++)
        {
            Grade = checkGrade(score[i][k]);
            cout << right << ((k == 2) ? setw(4) : setw(2)) << score[i][k] << "(" << Grade << ")" << ((score[i][k] == 55 || score[i][k] == 65 || score[i][k] == 75) ? "  " : "   ");

            GPA += checkGPA(Grade);
        }
        cout << fixed << setprecision(2) << "  " << GPA / 9.0 << endl;
        GPA = 0;
    }
    selectionSort2D(score, 3, 3, name);
}

void selectionSort2D(int arr[][3], int rows, int cols, string name[3])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            int minIndex = j;
            for (int k = j + 1; k < cols; k++)
            {
                if (arr[i][k] > arr[i][minIndex])
                {
                    minIndex = k;
                }
            }
            // Swap the elements
            if (minIndex != j)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[i][minIndex];
                arr[i][minIndex] = temp;
            }
        }
    }
    cout << "After Score\n";
    cout << setfill('-') << setw(50) << "\n";
    cout << "Student   1   2   3\n";
    cout << setfill('-') << setw(50) << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << setfill(' ') << " " << i + 1 << "   " << left << setw(12) << name[i];
        for (int k = 0; k < 3; k++)
        {
            cout << arr[i][k] << "\t";
        }
        cout << endl;
    }
}

string checkGrade(int score)
{
    int point[] = {0, 50, 55, 60, 65, 70, 75, 80};
    string Char[] = {"F", "D", "D+", "C", "C+", "B", "B+", "A"}, grade;

    for (int i = 0; i < 8; i++)
    {
        if (score >= point[i])
            grade = Char[i];
    }

    return grade;
}

float checkGPA(string Grade)
{
    float GPA, point[] = {0.0, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string Char[] = {"F", "D", "D+", "C", "C+", "B", "B+", "A"};

    for (int i = 0; i < 8; i++)
    {
        if (Grade == Char[i])
            GPA = point[i] * 3.0;
    }

    return GPA;
}