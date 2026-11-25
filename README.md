# cisp-finance-repo

A text-only C++ personal finance simulator for a CISP class.
It uses only the Gaddis textbooks:

- *Starting Out with Programming Logic and Design*, 5th Ed.
- *Starting Out with C++: From Control Structures through Objects*, 8th Ed.

No graphics and no front end. Everything runs in the console.

## Folders

| Folder | File | Status |
|---|---|---|
| `01-user-login/` | `user_login.cpp` | Empty (planned) |
| `02-dates/` | `dates.cpp` | Empty (planned) |
| `03-sp500-simulation/` | `sp500_simulation.cpp` | Done: 7% per year + risk warning |
| `04-bank-apy-simulation/` | `bank_apy_simulation.cpp` | Done: 0.5% per year |

Each folder has its own `README.md` with notes.

## Rates used

| Option | Yearly rate | Risk |
|---|---|---|
| S&P 500 | 7% (fixed guess) | High: can lose money |
| Bank savings | 0.5% | Low |
