#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
    int value[10];


    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        value[i] = 1+rand()%30;
        cout << i << setfill(' ') << setw(5) << right << value[i] << "  " << setfill('*') << setw(value[i]) << "" << endl;
    }


    cout << endl;
    system("pause");
    return 0;
}
