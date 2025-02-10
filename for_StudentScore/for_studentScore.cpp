#include <iostream>
using namespace std;

int main()
{
    int number, score, total = 0;


    cout << "Enter number of student : ";
    cin >> number;

    for(int i = 1; i <= number; i++)
    {
        cout << "Enter score " << i << " : ";
        cin >> score;
        total = total + score;
    }
    cout << endl;
    cout << "Total score = " << total << endl;
    cout << "Avg score = " << float(total)/number << endl;

    cout << endl;
    system("pause");
    return 0;
}