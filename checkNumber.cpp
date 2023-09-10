#include <iostream>
#include <time.h>
using namespace std;

void checkNum(int number, int random);

int main()
{
    int random, guess, count=0;

    srand(time(NULL));
    random = 1+rand()%10;


    cout << "### Welcome to guessing number game ###\n";
    cout << "Secret number has been chosen\n\n";

    do
    {
        cout << "Guess the number (1 to 10) : ";
        cin >> guess;
        checkNum(guess, random);
        count++;

    } while (guess!=random);

    cout << "Congratulations!\n";
    cout << "The secret number is "<< random << endl;
    cout << "You made " << count << " guesses" << endl;

    
    cout << endl;
    system("pause");
    return 0;
}


void checkNum(int guess, int random)
{
    if (guess>random)
        cout << "The secret number is higher\n\n";
    else if (guess<random)
        cout << "The secret number is lower\n\n";
}
