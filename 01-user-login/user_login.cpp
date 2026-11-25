// File:    user_login.cpp
// Project: cisp-finance-repo (CISP Personal Finance Simulator)
// Purpose: Asks for a username and PIN. The user gets 3 tries.
// Book:    Gaddis, Starting Out with C++ 8e (Ch. 2-6: constants, string,
//          if/else, while loops, bool flags, functions) — no classes.
// Note:    The username and PIN are fixed constants for a class demo only.
//          A real program would never store a PIN in the code.

#include <iostream>
#include <string>
using namespace std;

// Named constants (Ch. 2)
const string USERNAME = "student";
const int PIN = 1234;
const int MAX_TRIES = 3;

// Function prototypes (Ch. 6)
int getPin();
bool login();

int main()
{
    if (login())
    {
        cout << "\nWelcome, " << USERNAME << "! You are logged in.\n";
    }
    else
    {
        cout << "\nToo many tries. Goodbye.\n";
    }
    return 0;
}

// Gives the user MAX_TRIES chances to enter the right name and PIN.
// Returns true on success, false after too many wrong tries (Ch. 4, 5).
bool login()
{
    string name;
    int pin;
    int tries = 0;
    bool loggedIn = false;   // flag (Ch. 4)

    cout << "=== Login ===\n";
    while (!loggedIn && tries < MAX_TRIES)
    {
        cout << "Username: ";
        cin >> name;
        pin = getPin();
        tries++;

        if (name == USERNAME && pin == PIN)
        {
            loggedIn = true;
        }
        else if (tries < MAX_TRIES)
        {
            cout << "Wrong username or PIN. Tries left: "
                 << (MAX_TRIES - tries) << endl;
        }
    }
    return loggedIn;
}

// Reads a PIN; letters are rejected with cin.fail() (Ch. 3, 5).
int getPin()
{
    int pin;
    cout << "PIN: ";
    cin >> pin;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: PIN must be numbers only. PIN: ";
        cin >> pin;
    }
    return pin;
}
