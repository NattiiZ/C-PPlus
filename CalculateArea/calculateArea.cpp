#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char choice;
    float area;


    cout << "========== Calculate Area ==========\n\n";
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Right-angled Triangle" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice number : ";
    cin >> choice;

    
    if (choice == '1')
    {
        float radius;
        cout << "\nEnter radius : ";
        cin >> radius;
        area = 3.14159F * pow(radius, 2);
        cout << "Area of Circle = " << area << endl;
    }
    else if (choice == '2')
    {
        float length, width;
        cout << "\nEnter length and width : " << endl;
        cin >> length >> width;
        area = length * width;
        cout << "Area of Rectangle = " << area << endl;
    }
    else if (choice == '3')
    {
        float base, height;
        cout << "\nEnter base and height : " << endl;
        cin >> base >> height;
        area = 0.5 * (base * height);
        cout << "Area of Right-angled Triangle = " << area << endl;
    }
    else if (choice == '4')
        cout << "\n... Exit program ...\n";
    else 
    cout << "\nYou choose out of range is not process!\n";


    cout << endl;

    system("pause");
    return 0;
}