#include <iostream>
using namespace std;

void CalCircle();
void CalRectangle();


int main()
{   
    char ch;

    do
    {
        cout << "***************************" << endl;
        cout << "Program Calculate of Circle" << endl;
        cout << "***************************" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose Menu : ";
        cin >> ch;
        if (ch == '1')
        {
            cout << endl;
            CalCircle();
        }
        else if (ch == '2')
        {
            cout << endl;
            CalRectangle();
        }
        else if (ch == '3')
            cout << "Exit ..."<< endl;
        else
            cout << "Wrong Menu." << endl;
            cout << endl;
        
    } while (ch != '3');
    
        


    cout << endl;
    system("pause");
    return 0;
}


void CalCircle()
{
    float Radius, Area, Circumference;

    cout << "--- Circle Menu ---" << endl;
    cout << "Input Radius : ";
    cin >> Radius;
    Area = 3.14f*(Radius*Radius);
    Circumference = 2*3.14f*Radius;
    cout << endl;
    cout << "Area of Circle : " << Area << endl;
    cout << "Circumference of Circle : " << Circumference << endl;
    cout << "Diameter of Circlr : " << (2*Radius) << endl;
    cout << endl;
}

void CalRectangle()
{
    float Width, Length, Area, Circumference;

    cout << "--- Rectangle Menu ---" << endl;
    cout << "Input Width : ";
    cin >> Width;
     cout << "Input Length : ";
    cin >> Length;
    Area = Width*Length;
    cout << endl;
    cout << "Area of Rectangle : " << Area << endl;
    cout << endl;
}