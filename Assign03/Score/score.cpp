#include <iostream>
using namespace std;

int main()
{
	int score;

	cout << "Enter Your C++ score : ";
	cin >> score;

	cout << "You " << ((score >= 50) ? "pass!" : "fail!") << " with score " << score << endl;
	
	/*
	cout << "You ";
	if (score >= 50)
		cout << "pass";
	else
		cout << "fail";
	cout << " with score " << score << endl;
	*/


	system("pause");
	return 0;
}