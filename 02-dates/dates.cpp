// File:    dates.cpp
// Project: cisp-finance-repo (CISP Personal Finance Simulator)
// Purpose: Asks for a start date and today's date, checks that both are
//          real calendar dates (leap years included), and shows how much
//          time has passed.
// Book:    Gaddis, Starting Out with C++ 8e (Ch. 4 decisions, Ch. 5 loops,
//          Ch. 6 functions, Ch. 11 structs) — no date libraries.

#include <iostream>
using namespace std;

// A date grouped into one structure (Ch. 11)
struct Date
{
    int month;
    int day;
    int year;
};

// Function prototypes (Ch. 6)
bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getNumber(const char prompt[], int minVal, int maxVal);
Date getValidDate(const char title[]);
int dateToDays(Date d);
void displayElapsedTime(Date start, Date end);

int main()
{
    Date startDate = getValidDate("Enter the START date:");
    Date endDate = getValidDate("Enter TODAY's date:");

    displayElapsedTime(startDate, endDate);
    return 0;
}

// Leap year: divisible by 4, except century years not divisible by 400.
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Days in a month; February depends on the leap year (Ch. 4).
int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    return 31;
}

// Reads a whole number between minVal and maxVal; rejects letters (Ch. 5).
int getNumber(const char prompt[], int minVal, int maxVal)
{
    int value;
    cout << prompt;
    cin >> value;
    while (cin.fail() || value < minVal || value > maxVal)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: enter a number from " << minVal << " to "
             << maxVal << ": ";
        cin >> value;
    }
    return value;
}

// Asks for month, then year, then day, so the day limit is always right.
Date getValidDate(const char title[])
{
    Date d;
    cout << "\n" << title << endl;
    d.month = getNumber("  Month (1-12): ", 1, 12);
    d.year = getNumber("  Year (1900-2100): ", 1900, 2100);
    d.day = getNumber("  Day: ", 1, getDaysInMonth(d.month, d.year));
    return d;
}

// Counts days from Jan 1, 1900 to the date, using loops (Ch. 5).
int dateToDays(Date d)
{
    int total = 0;
    for (int y = 1900; y < d.year; y++)
    {
        if (isLeapYear(y))
            total += 366;
        else
            total += 365;
    }
    for (int m = 1; m < d.month; m++)
    {
        total += getDaysInMonth(m, d.year);
    }
    total += d.day;
    return total;
}

// Shows years, months, and days between two dates, plus total days.
void displayElapsedTime(Date start, Date end)
{
    int totalDays = dateToDays(end) - dateToDays(start);

    cout << "\nStart date: " << start.month << "/" << start.day
         << "/" << start.year << endl;
    cout << "Today:      " << end.month << "/" << end.day
         << "/" << end.year << endl;

    if (totalDays < 0)
    {
        cout << "Error: today's date is before the start date.\n";
        return;
    }

    int years = end.year - start.year;
    int months = end.month - start.month;
    int days = end.day - start.day;

    // Borrow one month's worth of days, using the START month's length,
    // so a long month like January never leaves a negative day (Ch. 4)
    if (days < 0)
    {
        days += getDaysInMonth(start.month, start.year);
        months--;
    }
    // Borrow 12 months from the years
    if (months < 0)
    {
        months += 12;
        years--;
    }

    cout << "Time passed: " << years << " year(s), " << months
         << " month(s), " << days << " day(s)\n";
    cout << "Total days:  " << totalDays << endl;
}
