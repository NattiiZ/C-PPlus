#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void DisplayMenu();
float Area(const float Radius);
float Area(const float Length, const float Widht);
float Area(const double Length, const double Widht);
float Area(const float Width1, const float Width2, const float Height);


int main()
{
    char Choice;
    bool loop = true;
    do {
        DisplayMenu();
        cin >> Choice;
        
        if (Choice == '1')
        {
            float Radius;
            cout << "\nEnter radius : ";
            cin >> Radius;
            cout << "Area of Circle = " << fixed;
            cout << setprecision(2) << Area(Radius) << endl;
        }
        else if (Choice == '2') 
        {
            float Length, Widht;
            cout << "Enter length : ";
            cin >> Length;
            cout << "Enter width : ";
            cin  >> Widht;
            cout << "Area of Rectangle = " << fixed;
            cout << setprecision(2) << Area(Length, Widht);
            cout << endl;
        }
        else if (Choice == '3')
        {
            double Length, Widht;
            cout << "Enter length : ";
            cin >> Length;
            cout << "Enter width : ";
            cin  >> Widht;
            cout << "Area of Triangle = " << fixed;
            cout << setprecision(2) << Area(Length, Widht);
            cout << endl;
        }
        else if (Choice == '4') 
        {
            float Widht1, Widht2, Height;
            cout << "Enter width 1 : ";
            cin >> Widht1;
            cout << "Enter width 2 : ";
            cin  >> Widht2;
            cout << "Enter height : ";
            cin  >> Height;
            cout << "Area of Rectangle = " << fixed;
            cout << setprecision(2) << Area(Widht1, Widht2, Height);
            cout << endl;
        }
        else if (Choice == '5') 
            loop = false;
        else 
        {
            cout << "\nYou choose out of range is ";
            cout << "not process.\n";
        }
    } while (loop);
    cout << "\n . . . Exit Program . . .\n";
    
    cout << endl;
    system("pause");
    return(0);
}

float Area(const float Radius)
{
    return(3.14159F * Radius * Radius);
}

float Area(const float Length, const float Widht)
{
    return(Length * Widht);
}

float Area(const double Length, const double Widht)
{
    return((Length * Widht)*0.5);
}

float Area(const float Width1, const float Width2, const float Height)
{
    return((Width1 + Width2)* 0.5 * Height);
}

void DisplayMenu()
{
    cout << endl;
    cout << "Program Calculate Area " << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;
    cout << "4. Trapezoid" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choose number : ";
}