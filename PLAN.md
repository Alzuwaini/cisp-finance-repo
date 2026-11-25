# Project Plan – CISP Personal Finance Simulator

Text-only C++ program. Gaddis books only:
*Programming Logic and Design* 5e and *Starting Out with C++* 8e (up to Ch. 15).
Built from the design worked out in the Gemini project chat.

---

## 1. What the user enters and what they see

| Step | User enters | Program shows (output) |
|---|---|---|
| 1. Login | Username and PIN (3 tries) | `Welcome, <name>` or `Too many tries. Goodbye.` |
| 2. Dates | Start date and today's date (month, day, year) | Time passed: years, months, days, and total days |
| 3. Income | Monthly income in dollars | (nothing yet) |
| 4. Expenses | For each one: what it was for, where it was paid, category, amount, date. Type `DONE` to stop | Running count of expenses entered |
| 5. Budget check | Nothing | `SURPLUS $x`, `BREAK-EVEN $0.00`, or `DEFICIT -$x` |
| 6. Optional spending (only if surplus) | `Y`/`N`, then an amount up to the surplus | Money left after spending |
| 7. Split | Nothing | 70% to invest, 30% kept as cash reserve |
| 8. Summary | Nothing | Expenses sorted high to low, plus each month's total, top item ("on what" / "where"), and top category |
| 9. Menu | A number 1–6 | See menu below |

**Menu**

| Choice | User enters | Output |
|---|---|---|
| 1. Bank savings | Number of years (1–50) | Year-by-year table at **0.5%** per year |
| 2. S&P 500 | `Y` after the risk warning, then years (1–50) | **Risk warning box**, then a year-by-year table at **7%** per year |
| 3. Compare both | Years (1–50) | Bank table and S&P 500 table, same years |
| 4. Search expense | A category name | Matching expenses, or `Not found` |
| 5. Save | Nothing | Writes `expenses.csv` (data) and `finance_report.txt` (report) |
| 6. Exit | Nothing | `Goodbye` |

Every number entry is checked: letters, negatives, and out-of-range values
show an error and ask again (`cin.fail()`, `cin.clear()`, `cin.ignore()`).

---

## 2. Main flowchart (Gaddis symbols)

`( )` start/end · `/ /` input/output · `[ ]` process · `[| |]` call a function · `< >` decision

```
( Start )
    |
[| login() |] --- 3 wrong PINs ---> / "Goodbye" / --> ( End )
    |
[| getValidDate() x2 |] --> [| displayElapsedTime() |]
    |
[| collectCashFlow() |]   income + expenses until DONE
    |
[ surplus = income - totalExpenses ]
    |
< surplus < 0 ? > --True--> / "DEFICIT" / ----------------+
    | False                                                |
< surplus == 0 ? > --True--> / "BREAK-EVEN" / ------------+
    | False                                                |
[| processDiscretionarySpend() |]                          |
    |                                                      |
[| calculateIdealAllocation() |]  70% invest / 30% cash    |
    |                                                      |
[| displayBudgetSummary() |] <-----------------------------+
[| displayAllMonthsSummary() |]
    |
< invest > 0 ? > --False--> / "Nothing to invest" / --+
    | True                                             |
[| runInvestmentMenu() |]  loop until 6                |
    |                                                  |
( End ) <----------------------------------------------+
```

**Menu loop (do-while + switch)**

```
( runInvestmentMenu )
    |
+-> / Show menu 1-6 /
|   / Input choice /
|   < choice >
|    1: [| simulateBankFixed() |]
|    2: / Risk warning / -> < Y ? > -> [| simulateSP500() |]
|    3: [| simulateBankFixed() |] then [| simulateSP500() |]
|    4: [| searchExpenseByCategory() |]
|    5: [| saveExpensesToCSV() |] and [| saveReportToFile() |]
|    6: exit
|   < choice != 6 ? >
+------True---+
    | False
( Return )
```

More detailed flowcharts for each function (collectCashFlow, simulateSP500,
displayElapsedTime, displayMonthlySummary) are in the Gemini project chat.

---

## 3. Steps (3 weeks, Gaddis 9-step process)

| # | Days | Step | Folder | Done when |
|---|---|---|---|---|
| 1 | 1–3 | Write down inputs/outputs (table above) and sketch screens | `PLAN.md` | ✅ this file |
| 2 | 4–6 | Hierarchy chart, flowcharts, pseudocode | `PLAN.md` | Every function has a box |
| 3 | 7–8 | Constants and structs | `05-finance-types` | `FinanceTypes.h` compiles |
| 4 | 8–10 | Input checks, login, dates | `01`, `02`, `07` | Bad input never crashes; leap years work |
| 5 | 11–13 | Income, expenses, sort, search, monthly summary | `08-budget-manager` | Totals match a hand trace |
| 6 | 14–15 | Bank and S&P 500 engines | `03`, `04` → `09` | ✅ standalone versions done |
| 7 | 16–17 | Save/load files | `10-file-manager` | CSV reloads correctly |
| 8 | 18 | Connect everything in `main.cpp` | `06-main-controller` | Full run works start to finish |
| 9 | 19–21 | Hand-trace tables, test cases, external docs | all | Output matches hand traces |

**Build command (when all files have code):**
```
g++ -std=c++11 -I05-finance-types -I07-input-date-utils -I08-budget-manager \
    -I09-investment-sim -I10-file-manager \
    06-main-controller/main.cpp 07-input-date-utils/InputDateUtils.cpp \
    08-budget-manager/BudgetManager.cpp 09-investment-sim/InvestmentSim.cpp \
    10-file-manager/FileManager.cpp -o finance_app
```

---

## 4. Rates and rules

| Constant | Value | Note |
|---|---|---|
| `SP500_RATE` | 0.07 | 7% per year, fixed guess. Warning shown first |
| `BANK_RATE` | 0.005 | 0.5% per year, compounded once a year |
| `INVEST_RATIO` | 0.70 | 70% of what is left goes to investing |
| `MAX_EXPENSES` | 100 | Array size limit |
| `MAX_YEARS` | 50 | Longest projection |

Note: earlier Gemini drafts used 4.5% bank and 8.5% + 1.5% dividends for the S&P 500.
This plan uses the 7% and 0.5% rates chosen for this repo.

## 5. Open questions for the professor
- Is a login with a PIN OK, or should it be skipped?
- One `main.cpp` file, or multiple files (as laid out here)?
- Should the S&P 500 show dividends and growth separately, or one 7% rate?
