#include <iostream>
#include <string>

using namespace std;

enum enSelectedSum { SumAll = 0, SumOdd = 1, SumEven = 2 };
enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber(string Message)
{
    int Number = 0;

    cout << Message;
    cin >> Number;

    return Number;
}

int ValidateNumberInRange(int Number, int From, int To)
{
    while (Number < From || Number > To)
    {
        cout << "Invalid option. Please enter a number between " << From << " and " << To << ": ";
        cin >> Number;
    }

    return Number;
}

enSelectedSum ReadSelectedSum()
{
    int SelectedOption = 0;

    cout << "Select the sum type (0 = All, 1 = Odd, 2 = Even): ";
    cin >> SelectedOption;

    SelectedOption = ValidateNumberInRange(SelectedOption, 0, 2);

    return (enSelectedSum)SelectedOption;
}

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

int CalculateSum(int Number, enSelectedSum Option)
{
    int Sum = 0;

    switch (Option)
    {
    case enSelectedSum::SumAll:
        for (int Counter = 1; Counter <= Number; Counter++)
        {
            Sum += Counter;
        }
        return Sum;

    case enSelectedSum::SumOdd:
        for (int Counter = 1; Counter <= Number; Counter++)
        {
            if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
                Sum += Counter;
        }
        return Sum;

    case enSelectedSum::SumEven:
        for (int Counter = 1; Counter <= Number; Counter++)
        {
            if (CheckOddOrEven(Counter) == enOddOrEven::Even)
                Sum += Counter;
        }
        return Sum;

    default:
        return 0;
    }
}

void PrintResult(int Sum)
{
    cout << "\nThe total sum is: " << Sum << endl;
}

int main()
{
    int Number = ReadNumber("Enter a number to calculate its sum: ");
    enSelectedSum SelectedOption = ReadSelectedSum();

    PrintResult(CalculateSum(Number, SelectedOption));

    return 0;
}
