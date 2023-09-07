#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int main()
{
    int random;
    float total=0, score, Max=0;


    srand(time(NULL));
    random = 1+rand()%10;
    cout << "Random number of student (1-10) : " << random << endl;
    for (int i=1; i<=random; i++)
    {
        cout << "Input score " << i << " : ";
        cin >> score;
        if (score > Max)
            Max = score;
        total += score;
    }
    cout << setfill('-') << setw(35) << " " << endl;

    cout << fixed << setprecision(2) << endl;
    cout << "Max score\t= " << Max << endl;
    cout << "Sum score\t= " << total << endl;
    cout << "Avg. score\t= " << total/random << endl;

    cout << setfill('-') << setw(35) << " " << endl;


    cout << endl;
    system("pause");
    return 0;
}
