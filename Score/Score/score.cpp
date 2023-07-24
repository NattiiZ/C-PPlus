#include <iostream>
using namespace std;;

int main()
{
	int score;

	cout << "Enter Your C++ score : ";
	cin >> score;

	cout << "Your " << ((score >= 50) ? "pass!" : "fail!") << " with score " << score << endl;

	system("pause");
	return 0;
}