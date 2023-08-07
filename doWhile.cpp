#include <iostream>
using namespace std;

int main()
{
    int num = 1, value, sum = 0;
    bool flag = true;


    do
    {
        cout << "Enter value (1-20): " << num << " : ";
        cin >> value;

        if ((value > 0)&&(value <=20))
        {
            sum += value;
            num++;
        }
        else
            flag = false;
    } 
        while (flag == true);
            if(num > 1)
            {
                float Avg;
                Avg = static_cast<float>(sum)/--num;
                cout << "Average of data = " << Avg << endl;
            }
            else
                cout << "No data input!" << endl;


    cout << endl;
    system("pause");
    return 0;
}