#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char Ch = 'a';
    cout << char(toupper(Ch)) << endl;


    srand(time(NULL));  // *** Requirement for rand() ***
    for (int i=1; i<=20; i++)
        cout << 1000+rand()%8999 << endl;   // 1+rand()%10 --- random 1-10


    cout << endl;
    system("pause");
    return 0;
}