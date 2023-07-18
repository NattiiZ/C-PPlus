#include <iostream>
using namespace std;


int main()
{
    int mAmount,
		thousand = 1000,
		fHundred = 500,
		hundred  = 100,
		fifty    = 50,
		twenty   = 20 ; 


    cout << "----------------------- ATM -----------------------\n\n";
    cout << "Enter the amount you want to withdraw : ";
    cin  >> mAmount;


	while (true)
	{
		if (mAmount < 20)
		{
			cout << "\n** Minimum 20$ **\n";
			break;
		}
		else (mAmount >= 20);
		{
			cout << "Wait . . .\n\n";


			//------Calculate------
			thousand = mAmount / thousand;
			cout << "1000$ : " << thousand << endl;
			mAmount = mAmount - (thousand*1000);

			fHundred = mAmount / fHundred;
			cout << "500$  : " << fHundred << endl;
			mAmount = mAmount - (fHundred*500);

			hundred = mAmount / hundred;
			cout << "100$  : " << hundred << endl;
			mAmount = mAmount - (hundred*100);

			fifty = mAmount / fifty;
			cout << "50$   : " << fifty << endl;
			mAmount = mAmount - (fifty*50);

			twenty = mAmount / twenty;
			cout << "20$   : " << twenty << endl;
			mAmount = mAmount - (twenty*20);


			if (mAmount < 20)
			{
				cout << "\n* Remaining " << mAmount <<"$ *\n** Minimum 20$ **\n";
				break;
			}
		}
	}

	cout << "\nThank you!";
	cout << "\n---------------------------------------------------\n\n";


    system("pause");
    return 0;
}