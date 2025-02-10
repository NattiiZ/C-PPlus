#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float height , weight;

	cout << "BMI CALCULATOR\n\n";
	cout << "Enter your height (cm) : ";
	cin >> height;
	cout << "Enter your weight (kg) : ";
	cin >> weight;

	height = height / 100;
	cout << "\nYour BMI = " << weight / pow(height, 2) << "\n\n";

	system("pause");
	return 0;
}