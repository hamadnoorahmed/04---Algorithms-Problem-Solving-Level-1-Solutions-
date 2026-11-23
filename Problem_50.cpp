#include <iostream>
#include <string>

using namespace std;

string ReadPinCode()
{
    string PinCode = "";

    cout << "Enter PIN Code: ";
    cin >> PinCode;

    return PinCode;
}

bool Login()
{
    string PinCode = "";
    int Attempts = 3;

    do
    {
        PinCode = ReadPinCode();
        Attempts--;

        if (PinCode == "1234")
        {
            return true;
        }
        else
        {
            system("color 4F");
            cout << "Wrong PIN Code. You have " << Attempts << " attempt(s) left.\n\n";
        }
    } while (Attempts >= 1 && PinCode != "1234");

    return false;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour current balance is $7500.\n";
    }
    else
    {
        cout << "Your card is blocked. Please contact customer service.\n";
    }

    return 0;
}
