#include <iostream>
using namespace std;

int main()
{
    char sex;
	int age;
	float height , weight, bmi;


	cout << "========== BMI CALCULATOR ==========\n\n";
    cout << "Enter Your age : ";
    cin >> age;
    cout << "Enter Your sex (M/F): ";
    cin >> sex;
	cout << "Enter your height (cm) : ";
	cin >> height;
	cout << "Enter your weight (kg) : ";
	cin >> weight;


	height /= 100;
	bmi = weight / (height*height);


    cout << "\nYour age = " << age << endl;
    cout << "Your Sex = ";
    if (sex == 'M')
        cout << "Male";
    else if (sex == 'F')
        cout << "Female";
    else 
        cout << "NULL";


	cout << "\nYour BMI = " << bmi;
	
	if (bmi < 18.5)
		cout << " (Underweight)";
	else if (bmi >= 18.5) 
		cout << " (Normal)";
	else if (bmi >= 25)
        cout << " (Overweight)";
	else
        cout << " (Obesity)";


	system("pause");
	return 0;
}