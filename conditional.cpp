#include <iostream>
using namespace std;

int main()
{
	int Number;

	cout << "Enter number : ";
	cin >>  Number;
	cout << Number << " is " << ((Number % 2) == 0 ? "even " : "odd ");
	cout << "number." << endl;

	system("pause");
	return 0;
}