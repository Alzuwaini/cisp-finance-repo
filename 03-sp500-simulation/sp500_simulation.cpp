// File:    sp500_simulation.cpp
// Project: cisp-finance-repo (CISP Personal Finance Simulator)
// Purpose: Shows how money could grow in the S&P 500 at a fixed 7% per year,
//          after showing the user a warning about stock market risk.
// Book:    Gaddis, Starting Out with C++ 8e (Ch. 2-6: constants, input
//          validation, loops, functions) — no pow(), no classes.

#include <iostream>
#include <iomanip>
using namespace std;

// Named constant (Ch. 2)
const double SP500_RATE = 0.07;   // 7% fixed yearly return (assumption only)

// Function prototypes (Ch. 6)
void showWarning();
double getPositive(const char prompt[]);
int getYears();
void simulateSP500(double start, int years);

int main()
{
    double startAmount;
    int years;
    char answer;

    showWarning();

    cout << "Do you understand the risk and want to continue? (Y/N): ";
    cin >> answer;
    if (answer != 'Y' && answer != 'y')
    {
        cout << "Simulation cancelled. Your money stays safe.\n";
        return 0;
    }

    startAmount = getPositive("Enter the amount to invest: $");
    years = getYears();

    simulateSP500(startAmount, years);
    return 0;
}

// Prints the stock market risk warning box.
void showWarning()
{
    cout << "**************************************************\n";
    cout << "*                 !!! WARNING !!!                *\n";
    cout << "*  The S&P 500 is a STOCK investment.            *\n";
    cout << "*  - Its value goes UP and DOWN every year.      *\n";
    cout << "*  - You CAN lose money, even a large amount.    *\n";
    cout << "*  - 7% is an average guess, NOT a promise.      *\n";
    cout << "*  - Past results do not predict the future.     *\n";
    cout << "*  This program is a class project, not advice.  *\n";
    cout << "**************************************************\n\n";
}

// Input validation loop (Ch. 5): keeps asking until the value is > 0.
double getPositive(const char prompt[])
{
    double value;
    cout << prompt;
    cin >> value;
    while (value <= 0)
    {
        cout << "Error: amount must be greater than 0. Try again: $";
        cin >> value;
    }
    return value;
}

// Input validation for years (1 to 50).
int getYears()
{
    int years;
    cout << "Enter number of years (1-50): ";
    cin >> years;
    while (years < 1 || years > 50)
    {
        cout << "Error: enter a number from 1 to 50: ";
        cin >> years;
    }
    return years;
}

// Compounds once per year with a for loop instead of pow() (Ch. 5).
void simulateSP500(double start, int years)
{
    double balance = start;
    double gain;

    cout << fixed << showpoint << setprecision(2);
    cout << "\nS&P 500 Simulation at 7% per year\n";
    cout << "Year      Gain           Balance\n";
    cout << "----------------------------------\n";

    for (int year = 1; year <= years; year++)
    {
        gain = balance * SP500_RATE;
        balance = balance + gain;
        cout << setw(4) << year
             << setw(12) << gain
             << setw(16) << balance << endl;
    }

    cout << "----------------------------------\n";
    cout << "Starting amount: $" << start << endl;
    cout << "Ending balance:  $" << balance << endl;
    cout << "Total growth:    $" << (balance - start) << endl;
    cout << "\nReminder: real stock returns change every year. "
         << "You could end with less.\n";
}
