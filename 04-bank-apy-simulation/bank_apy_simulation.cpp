// File:    bank_apy_simulation.cpp
// Project: cisp-finance-repo (CISP Personal Finance Simulator)
// Purpose: Shows how money grows in a bank savings account at 0.5% per year.
// Book:    Gaddis, Starting Out with C++ 8e (Ch. 2-6: constants, input
//          validation, loops, functions) — no pow(), no classes.

#include <iostream>
#include <iomanip>
using namespace std;

// Named constant (Ch. 2)
const double BANK_RATE = 0.005;   // 0.5% yearly bank interest rate

// Function prototypes (Ch. 6)
double getPositive(const char prompt[]);
int getYears();
void simulateBank(double start, int years);

int main()
{
    double startAmount;
    int years;

    cout << "Bank Savings Simulation (0.5% per year)\n";
    cout << "Bank savings are low risk but grow slowly.\n\n";

    startAmount = getPositive("Enter the amount to deposit: $");
    years = getYears();

    simulateBank(startAmount, years);
    return 0;
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
void simulateBank(double start, int years)
{
    double balance = start;
    double interest;

    cout << fixed << showpoint << setprecision(2);
    cout << "\nBank Simulation at 0.5% per year\n";
    cout << "Year   Interest         Balance\n";
    cout << "----------------------------------\n";

    for (int year = 1; year <= years; year++)
    {
        interest = balance * BANK_RATE;
        balance = balance + interest;
        cout << setw(4) << year
             << setw(12) << interest
             << setw(16) << balance << endl;
    }

    cout << "----------------------------------\n";
    cout << "Starting amount: $" << start << endl;
    cout << "Ending balance:  $" << balance << endl;
    cout << "Total interest:  $" << (balance - start) << endl;
}
