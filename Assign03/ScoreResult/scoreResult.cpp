#include <iostream>
#include <string>
using namespace std;

int main()
{
    int mid, final;
    float q1, q2, q3, qTotal, total;
    string result;


    cout << "========== SCORE ==========" << endl;

    cout << "\n-- Quizzes --" << endl;
    cout << "Enter quizz 1 score (10) : ";
    cin >> q1;
    cout << "Enter quizz 2 score (10) : ";
    cin >> q2;
    cout << "Enter quizz 3 score (10) : ";
    cin >> q3;

    cout << "\n-- Mid term --" << endl;
    cout << "Enter mid-term score (40) : ";
    cin >> mid;

    cout << "\n-- Final --" << endl;
    cout << "Enter Final score (50) : ";
    cin >> final;


    qTotal = (q1 + q2 + q3)/3;
    total = qTotal + mid + final;
    result = ((total >= 50) ? "pass!" : "fail!");


    cout << "\nQuizz (Avg.) = " << qTotal << endl;
    cout << "Mid-term = " << mid << endl;
    cout << "Final = " << final << endl;
    cout << "## Total score = " << total << " point" << endl;
    cout << "## Your score is " << result << endl;

    cout << "\n==========================\n";

    system("pause");
    return 0;
}