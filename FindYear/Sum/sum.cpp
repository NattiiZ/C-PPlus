#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Name;
	int yearBirth , yearNow = 2023;

	//Calculate
	cout << "Enter your name : ";
	cin  >> Name;
	cout << "Enter your year of birth : ";
	cin  >> yearBirth;

	//Output
	cout << "\nYour age = " << yearNow - yearBirth << " years old.\n\n";

	system("pause");
	return 0;
}