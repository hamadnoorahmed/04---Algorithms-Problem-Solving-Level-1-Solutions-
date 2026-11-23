#include <iostream>
#include <string>

using namespace std;

struct stTaskDuration
{
    int NumberOfDays = 0;
    int NumberOfHours = 0;
    int NumberOfMinutes = 0;
    int NumberOfSeconds = 0;
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    stTaskDuration TaskDuration;

    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 60 * 60;
    const int SecondsPerMinute = 60;

    int Remainder = 0;

    TaskDuration.NumberOfDays = TotalSeconds / SecondsPerDay;
    Remainder = TotalSeconds % SecondsPerDay;

    TaskDuration.NumberOfHours = Remainder / SecondsPerHour;
    Remainder = Remainder % SecondsPerHour;

    TaskDuration.NumberOfMinutes = Remainder / SecondsPerMinute;
    Remainder = Remainder % SecondsPerMinute;

    TaskDuration.NumberOfSeconds = Remainder;

    return TaskDuration;
}

void PrintTaskDuration(stTaskDuration TaskDuration)
{
    cout << "\nDuration (Days:Hours:Minutes:Seconds): "
        << TaskDuration.NumberOfDays << ":"
        << TaskDuration.NumberOfHours << ":"
        << TaskDuration.NumberOfMinutes << ":"
        << TaskDuration.NumberOfSeconds << endl;
}

int main()
{
    int TotalSeconds = ReadPositiveNumber("Enter the total number of seconds: ");

    PrintTaskDuration(SecondsToTaskDuration(TotalSeconds));

    return 0;
}
