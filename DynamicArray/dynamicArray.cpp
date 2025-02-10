#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    // string name[10];

    cout << "Enter number of student : ";
    cin >> num;
    string *name = new string[num];
    int *score = new int[num];

    for (int i=0; i<num; i++)
    {
        cout << "Enter name : ";
        cin >> name[i];
        cout << "Enter score : ";
        cin >> score[i];
    }
    
    cout << endl;
    system("pause");
    return 0;
}