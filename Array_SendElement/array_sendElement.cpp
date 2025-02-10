#include <iostream>
#include <iomanip>

using namespace std;

string checkResult(int score);
void Show(string name[10], int score[10], int No_std, int total, string result[10]);

int main()
{
    int score[10], total=0, No_std;
    string name[10], result[10];
    
    cout << "Enter Number of Student : ";
    cin >> No_std;
    cout << endl;
    
    for(int i=0; i<No_std; i++)
    {
        cout << "Enter Name [" << i+1 << "] : ";
        cin >> name[i];
        cout << "Enter Score [" << i+1 << "] : ";
        cin >> score[i];
        total += score[i];
        result[i] = checkResult(score[i]);
        cout << endl;
    }
    Show(name, score, No_std, total, result);

    
    cout << endl;
    system("pause");
    return 0;
}


string checkResult(int score)
{
    string result="";

    if (score>=50)
        result = "Pass";
    else
        result = "Fail";
    
    return(result);
}


void Show(string name[10], int score[10], int No_std, int total, string result[10])
{
    int maxScore=0, minScore;

    cout << "-" << setfill('-') << setw(31) << " " << endl;
    cout << " Name\t\tScore\tResult" << endl;
    cout << "-" << setfill('-') << setw(31) << " " << endl;
    
    minScore = score[0];
    for(int i=0; i<No_std; i++)
    {
        if (score[i]>maxScore)
            maxScore = score[i];
        
        if (score[i]<minScore)
            minScore=score[i];
        
        cout << " " << setw(15) << setfill(' ') << left << name[i] << setw(5) << setfill(' ') << right << score[i] << setw(9) << setfill(' ') << right << result[i]<< endl;
    }
    
    cout << "-" << setfill('-') << setw(31) << " " << endl;
    cout << "Max Score = " << maxScore << endl;
    cout << "Min Score = " << minScore << endl;
    cout << "Total Score = " << total << endl;
    cout << "Average Score = " << float(total)/4 << endl;
}