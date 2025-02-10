#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Name;
	int Age;
	string Sex;

	cout << "Enter your name : ";
	cin	 >> Name;
	cout << "Enter your age : ";
	cin  >> Age;
	cout << "Enter your sex : ";
	cin  >> Sex;

	cout << "\nHello " << Name << ".\n";
	cout << "You have " << Age << " years old .\n";
	cout << "You're " << Sex << ".\n";
	cout <<  "You're beginer developer.\n\n";

	system("pause");
	return 0;
}