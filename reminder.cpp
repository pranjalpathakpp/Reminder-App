#include<bits/stdc++.h>

using namespace std;

void setReminder(int day, int month, int year, int hours, int minutes, const string &message)
{
    time_t now = time(0);
    tm *currentTime = localtime(&now);

    tm reminderTime = *currentTime;
    reminderTime.tm_mday = day;
    reminderTime.tm_mon = month - 1;
    reminderTime.tm_year = year - 1900;
    reminderTime.tm_hour = hours;
    reminderTime.tm_min = minutes;
    reminderTime.tm_sec = 0;

    time_t reminder = mktime(&reminderTime);
    double diffSeconds = difftime(reminder, now);

    if (diffSeconds <= 0)
    {
        cout << "Invalid reminder time. Please set a future time.\n";
        return;
    }

    this_thread::sleep_for(chrono::seconds(static_cast<int>(diffSeconds)));

    cout << "Reminder: " << message << endl;
}

int main()
{
    int day, month, year, hours, minutes;
    string message;

    cout << "Reminder Setting\n";
    cout << "Enter the reminder date (dd/mm/yyyy):\n";
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;

    cout << "Enter the reminder time (24-hour format):\n";
    cout << "Hours (0-23): ";
    cin >> hours;
    cout << "Minutes (0-59): ";
    cin >> minutes;

    cin.ignore();
    cout << "Enter the reminder message: ";
    getline(cin, message);

    setReminder(day, month, year, hours, minutes, message);

    return 0;
}
