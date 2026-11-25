# cisp-finance-repo

A text-only C++ personal finance simulator for a CISP class.
It uses only the Gaddis textbooks:

- *Starting Out with Programming Logic and Design*, 5th Ed.
- *Starting Out with C++: From Control Structures through Objects*, 8th Ed.

No graphics and no front end. Everything runs in the console.

## Folders

See **`PLAN.md`** for the full plan, flowchart, and what the user enters and sees.

| Folder | Files | Status |
|---|---|---|
| `01-user-login/` | `user_login.cpp` | Done: username + PIN, 3 tries |
| `02-dates/` | `dates.cpp` | Done: leap years + time passed (moves into 07) |
| `03-sp500-simulation/` | `sp500_simulation.cpp` | Done: 7% per year + risk warning |
| `04-bank-apy-simulation/` | `bank_apy_simulation.cpp` | Done: 0.5% per year |
| `05-finance-types/` | `FinanceTypes.h` | Empty |
| `06-main-controller/` | `main.cpp` | Empty |
| `07-input-date-utils/` | `InputDateUtils.h`, `InputDateUtils.cpp` | Empty |
| `08-budget-manager/` | `BudgetManager.h`, `BudgetManager.cpp` | Empty |
| `09-investment-sim/` | `InvestmentSim.h`, `InvestmentSim.cpp` | Empty |
| `10-file-manager/` | `FileManager.h`, `FileManager.cpp`, `expenses.csv`, `finance_report.txt` | Empty |

Folders 05–10 follow the file layout from the Gemini project chat.
Each folder has its own `README.md` with notes.

## Rates used

| Option | Yearly rate | Risk |
|---|---|---|
| S&P 500 | 7% (fixed guess) | High: can lose money |
| Bank savings | 0.5% | Low |
