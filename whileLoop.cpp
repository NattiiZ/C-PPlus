#include <iostream>
using namespace std;

int main()
{
    int num, value, Neg=0, Pos=0, zero=0;
    

    cout << "Enter number : ";
    cin >> num;
    cout << endl;


    int i = 1;     
    while (i <= num)
    {
        cout << "Enter value " << i << " : ";
        cin >> value;
        
        if(value < 0)
            Neg++;
        else if (value > 0)
            Pos++;
        else
            zero++;
            
        i++;
    }

    cout << "\n***************\n";
    cout << "Negative  = " << Neg << " numbers\n";
    cout << "Possitive = " << Pos << " numbers\n";
    cout << "Zero      = " << zero << " numbers\n";


    cout << endl;
    system("pause");
    return 0;
}