#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
    int value[10], random;


    srand(time(NULL));
    for (int i=0; i<10; i++)
    {
        value[i] = 1+rand()%29;
        cout << i << setfill(' ') << setw(4) << right << value[i] << " " << setfill('*') << setw(value[i]) << "" << endl;
    }


    cout << endl;
    system("pause");
    return 0;
}
