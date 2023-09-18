#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;

string checkResult(int score);

int main()
{
    int score[4], total=0, maxScore=0, minScore;
    string name[4], result[4];

    for(int i=0; i<4; i++)
    {
        cout << "Enter Name [" << i+1 << "] : ";
        cin >> name[i];
        cout << "Enter Score [" << i+1 << "] : ";
        cin >> score[i];
        total += score[i];
        result[i] = checkResult(score[i]);
        cout << endl;
    }

    cout << "-" << setfill('-') << setw(31) << " " << endl;
    cout << " Name\t\tScore\tResult" << endl;
    cout << "-" << setfill('-') << setw(31) << " " << endl;
    
    minScore = score[0];
    for(int i=0; i<4; i++)
    {
        if (score[i]>maxScore)
            maxScore = score[i];
        
        if (score[i]<minScore)
            minScore=score[i];
        
        cout << " " << name[i] << "\t\t  " << score[i] << "\t  " << result[i]<< endl;
    }
    
    cout << "-" << setfill('-') << setw(31) << " " << endl;
    cout << "Max Score = " << maxScore << endl;
    cout << "Min Score = " << minScore << endl;
    cout << "Total Score = " << total << endl;
    cout << "Average Score = " << float(total)/4 << endl;


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