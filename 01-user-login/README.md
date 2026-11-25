# 01 – User Login

**File:** `user_login.cpp`

- Asks for a username and PIN. The user gets **3 tries**.
- Letters in the PIN are rejected (`cin.fail()`), so they cannot crash it.
- Demo login: username `student`, PIN `1234` (named constants, class demo only).
- Uses a `bool` flag and a `while` loop (Gaddis Ch. 4, 5).

**Compile and run:**
```
g++ user_login.cpp -o login
./login
```
