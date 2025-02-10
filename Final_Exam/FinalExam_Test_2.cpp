#include <iostream>
#include <iomanip>

using namespace std;


float CalComm(float sale);
void DisplayComm(float com);
void DisplayComm(float comarr[], int saleperson);


int main()
{
    char choice;
    int saleperson=0;
    float totalComm=0.0, personalComm=0.0;


    do
    {
        cout << "Would you like to see a saleperon's commission (Y/N) : ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
            case 'Y':
            {
                cout << "\nEnter number of saleperson : ";
                cin >> saleperson;

                float *allComm = new float[saleperson];
                system("cls");

                for (int i=0; i< saleperson; i++)
                {
                    float sale, comm;

                    cout << "Enter the total sales of saleperson " << i+1 << " : ";
                    cin >> sale;

                    personalComm = CalComm(sale);
                    allComm[i] = personalComm;
                    totalComm += personalComm,
                    DisplayComm(personalComm);
                }
                DisplayComm(allComm, saleperson);

                break;
            }

            case 'N':
            {   
                string line_St(30, '*'), line_li(30, '-');

                if (saleperson==0)
                {
                    cout << endl << line_li << endl;
                    cout << "There are " << saleperson << " saleperson.\n";
                    cout << line_li << endl;
                }
                cout << endl;
                cout << line_St << endl;
                cout << "Total commission is " << fixed << setprecision(2) << totalComm << endl;
                cout << line_St << endl;

                break;
            }

            default:
            {
                cout << "\nPlease Enter 'Y' or 'N'\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

    } while (choice!='N');
    


    cout << endl;
    system("pause");
    return 0;
}


// ============================================================


float CalComm(float sale)
{
    float Comm, result, SaleTable[]={30000.0, 22000.0, 12000.0, 5000.0}, CommTable[]={15, 10, 7, 3};


    if (sale>=5000.0)
    {
        for (int i=0; i<4; i++)
        {
            if (sale>SaleTable[i])
            {
                Comm = CommTable[i]/100;
                break;
            }
        }
    }
    else
        Comm = 0.0;

    result = sale*Comm;


    return (result);
}

// -------------------------------------------------------------

void DisplayComm(float com)
{
    cout << "The commission for this saleperson is " << fixed << setprecision(2) << com << endl << endl;
}

// -------------------------------------------------------------

void DisplayComm(float comarr[], int saleperson)
{
    string line_li(50, '-');


    cout << line_li << endl;
    cout << "There are " << saleperson << " saleperson.\n\n";
    for (int i=0; i<saleperson; i++)
    {
        cout << "The commission for saleperson " << i+1 << " = " << comarr[i] << endl;
    }
    cout << line_li << endl << endl;
}

