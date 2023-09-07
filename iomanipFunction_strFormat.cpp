#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float total;


    cout << setfill('*') << setw(33) << " " << endl;
    cout << "Hello" << endl;
    cout << setfill('-') << setw(33) << " " << endl;
    
    total = 5.164*26.176;
    cout << fixed << setprecision(2) << total << endl;
    cout << 156.312156 << endl;


    cout << endl;
    system("pause");
    return 0;
}