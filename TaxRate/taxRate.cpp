#include <iostream>
#include <string>
using namespace std;

int main()
{
    string productName;
    char member;
    float price, total, Tax, taxRate = 0.07f, discount;


    // Input
    cout << "Enter product name : ";
    cin >> productName;
    cout << "Enter price of product : ";
    cin >> price;
    cout << "Are you member? (Y/N) : ";
    cin >> member;


    // Calculate
    Tax =  price * taxRate;
    total = price + Tax;
    discount = ((member == 'Y') ? (total*0.05) : 0);
    total -= discount;


    // Output
    cout << endl;
    cout << "Price of " << productName << " = " << price << endl;
    cout << "Tax (7%) of = " << productName << " = " << Tax << endl;
    cout << "* Discount = " << discount << " *\n";
    cout << "Total price of " << productName << " = " << total << "$\n";
    cout << endl;


    system("pause");
    return 0;
}