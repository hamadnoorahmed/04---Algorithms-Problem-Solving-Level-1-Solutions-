#include <iostream>

using namespace std;

struct stMoneyBoxContent
{
    int Pennies = 0;
    int Nickels = 0;
    int Dimes = 0;
    int Quarters = 0;
    int Dollars = 0;
};

stMoneyBoxContent ReadMoneyBoxContent()
{
    stMoneyBoxContent MoneyBox;

    cout << "Enter total Pennies: ";
    cin >> MoneyBox.Pennies;

    cout << "Enter total Nickels: ";
    cin >> MoneyBox.Nickels;

    cout << "Enter total Dimes: ";
    cin >> MoneyBox.Dimes;

    cout << "Enter total Quarters: ";
    cin >> MoneyBox.Quarters;

    cout << "Enter total Dollars: ";
    cin >> MoneyBox.Dollars;

    return MoneyBox;
}

int CalculateTotalPennies(stMoneyBoxContent MoneyBox)
{
    int TotalPennies = MoneyBox.Pennies * 1
        + MoneyBox.Nickels * 5
        + MoneyBox.Dimes * 10
        + MoneyBox.Quarters * 25
        + MoneyBox.Dollars * 100;

    return TotalPennies;
}

int main()
{
    int TotalPennies = CalculateTotalPennies(ReadMoneyBoxContent());

    cout << "\nTotal Pennies = " << TotalPennies << endl;
    cout << "Total Dollars = $" << (float)TotalPennies / 100.0f << endl;

    return 0;
}
