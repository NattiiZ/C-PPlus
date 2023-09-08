#include <iostream>
using namespace std;;

int main()
{
	float Fh , Cs;

	cout << "*** Fahrenheit to Celsius ***\n\n";
	cout << "Enter Fahrenheit Temperature : ";
	cin >> Fh;

	Cs = (5.0/9.0) * (Fh - 32);
	cout << "\nTemperature = " << Cs << " Celsius.\n\n";

	system("pause");
	return 0;
}