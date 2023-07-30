#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cout << "Enter first number (A)	: ";
	cin >> A;
	cout << "Enter second number (B) : ";
	cin >> B;

	cout << "\nTesting usege operator\n";
	cout << "A != B = " << (A!=B) << endl;
	cout << "A && B = " << (A&&B) << endl;

	system("pause");
	return 0;
}