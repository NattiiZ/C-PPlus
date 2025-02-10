#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	float salary , sale , percent , coms;

	cout << "/// REVENUE CALCULATOR ///\n\n";

	cout << "Enter Name   : ";
	cin >> name;

	cout << "Enter Salary : ";
	cin >> salary;

	cout << "Enter Sale   : ";
	cin >> sale;

	cout << "Enter Commission Percent : ";
	cin >> percent;


	coms = (sale*(percent/100));

	cout << "\n\n-------- OUTPUT --------\n";
	cout << "\nYour name : " << name <<endl;
	cout << "Total Revenue " << salary + coms << " Bath.";
	cout << "\n\n------------------------\n";


	system("pause");
	return 0;
}