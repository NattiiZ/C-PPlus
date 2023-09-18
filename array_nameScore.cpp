#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int score[4], total=0, maxScore=0, minScore;
    string name[4];

     for(int i=0; i<4; i++)
    {
        cout << "Enter Name [" << i+1 << "] : ";
        cin >> name[i];
        cout << "Enter Score [" << i+1 << "] : ";
        cin >> score[i];
        total += score[i];
        cout << endl;
    }

    cout << "-" << setfill('-') << setw(22) << " " << endl;
    cout << " Name\t\tScore" << endl;
    cout << "-" << setfill('-') << setw(22) << " " << endl;
    
    minScore = score[0];
    for(int i=0; i<4; i++)
    {
        if (score[i]>maxScore)
            maxScore = score[i];
        
        if (score[i]<minScore)
            minScore=score[i];

        cout << " " << name[i] << "\t\t  " << score[i] << endl;
    }
    
    cout << "-" << setfill('-') << setw(22) << " " << endl;
    cout << "Max Score = " << maxScore << endl;
    cout << "Min Score = " << minScore << endl;
    cout << "Total Score = " << total << endl;
    cout << "Average Score = " << float(total)/4 << endl;


    cout << endl;
    system("pause");
    return 0;
}
