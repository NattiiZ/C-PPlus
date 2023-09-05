#include <iostream>
#include <time.h>
using namespace std;

int checkNum(int number, int random, int result);

int main()
{
    int random, guess, result=0, count=0;

    srand(time(NULL));
    random = 1+rand()%10;


    cout << "### Welcome to guessing number game ###\n";
    cout << "Secret number has been chosen\n\n";

    do
    {
        cout << "Guess the number (1 to 10) : ";
        cin >> guess;
        result = checkNum(guess, random, result);
        count++;

    } while (result!=1);

    cout << "Congratulations!\n";
    cout << "The secret number is "<< random << endl;
    cout << "You made " << count << " guesses" << endl;

    
    cout << endl;
    system("pause");
    return 0;
}


int checkNum(int guess, int random, int result)
{
    if (guess>random)
        cout << "The secret number is higher\n\n";
    else if (guess<random)
        cout << "The secret number is lower\n\n";
    else
        result = 1;
    
    return(result);
}