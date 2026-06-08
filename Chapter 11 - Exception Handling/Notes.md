# 📘 Chapter 11: Exception Handling in C++
# 🧠 Research-Level Master Notes (Textbook + Engineering Depth)

---

# 🎯 11.1 Objectives (What this chapter teaches)

By the end of this chapter, you will understand:

✔ What runtime errors (exceptions) are  
✔ Why programs crash without handling  
✔ How C++ handles errors safely using try-catch  
✔ How throw mechanism works internally  
✔ How multiple exceptions are handled  
✔ Standard exception classes (`std::exception`)  
✔ Catch-all handler (`catch(...)`)  

---

# 💥 11.2 Introduction to Exception Handling

---

## 📌 What is an Exception?

An **exception** is an unexpected runtime event that interrupts normal program flow.

---

## 🧠 Engineering Meaning

```text
Program = sequence of instructions
Exception = sudden disruption in execution flow
```

---

## ⚠️ Example real-world analogy

```text
ATM machine:
- You request withdrawal
- But server is down
→ transaction fails unexpectedly
```

That failure = exception

---

## ❌ Without exception handling

Program:

```text
crashes immediately
```

---

## ✔ With exception handling

Program:

```text
detects error → handles it → continues safely
```

---

# 🧠 WHY EXCEPTION HANDLING EXISTS

---

## Without it:

```text
if error occurs → program terminates
```

---

## With it:

```text
error detected → controlled recovery
```

---

## Engineering benefit:

✔ Stability  
✔ Reliability  
✔ Better debugging  
✔ Separation of logic and error handling  

---

# ⚙️ 11.3 TRY–CATCH MECHANISM

---

## 📌 Core Syntax

```cpp
try
{
    // risky code
}
catch(...)
{
    // error handler
}
```

---

## 🧠 Execution model

```text
1. try block executes
2. If no error → catch ignored
3. If error → jump to catch
```

---

# 🧪 11.3.1 BASIC EXAMPLE (TEXTBOOK)

```cpp
try
{
    int num = 10;

    if (num > 5)
    {
        throw "Number is too large!";
    }

    cout << num;
}
catch (const char* msg)
{
    cout << msg;
}
```

---

## 🧠 STEP-BY-STEP EXECUTION

### Step 1:
```text
num = 10 assigned
```

### Step 2:
```text
if (num > 5) → TRUE
```

### Step 3:
```text
throw executed
```

Program flow:

```text
immediately leaves try block
```

---

### Step 4:
```text
control goes to catch(const char*)
```

---

### Step 5:
```text
message printed
```

---

# 🚨 KEY ENGINEERING INSIGHT

```text
throw = forcefully breaks normal execution flow
```

---

# ⚙️ 11.4 THROWING EXCEPTIONS

---

## 📌 Concept

```text
throw = signal an error occurred
```

---

## 🧪 Example (Age check)

```cpp
void checkAge(int age)
{
    if (age < 18)
    {
        throw "Age must be 18 or above.";
    }

    cout << "Access granted!";
}
```

---

## MAIN FUNCTION FLOW

```cpp
try
{
    checkAge(16);
}
catch(const char* msg)
{
    cout << msg;
}
```

---

## 🧠 EXECUTION FLOW

### Step 1:
```text
checkAge(16) called
```

### Step 2:
```text
age < 18 → TRUE
```

### Step 3:
```text
throw triggered
```

### Step 4:
```text
function exits immediately
```

### Step 5:
```text
catch handles error
```

---

## 🚨 IMPORTANT RULE

```text
Once throw executes → remaining function code is skipped
```

---

# ⚙️ 11.5 MULTIPLE EXCEPTIONS

---

## 📌 Concept

Different errors need different handling.

---

## 🧪 Example (Division)

```cpp
void divide(int a, int b)
{
    if (b == 0)
    {
        throw 0;
    }

    cout << a / b;
}
```

---

## MAIN

```cpp
try
{
    divide(10, 0);
}
catch(int error)
{
    cout << "Division by zero error";
}
```

---

## 🧠 EXECUTION FLOW

```text
b == 0 → true
→ throw 0
→ catch(int) activated
→ error handled
```

---

## 🔥 KEY INSIGHT

```text
Type of throw decides which catch block runs
```

---

# ⚙️ 11.6 STANDARD EXCEPTION CLASSES

---

## 📌 Library used

```cpp
#include <stdexcept>
```

---

## 🧠 Why needed?

Instead of raw strings or integers:

```text
C++ provides structured error system
```

---

## 🧪 Example

```cpp
throw invalid_argument("Negative value not allowed");
```

---

## HANDLING

```cpp
catch(const invalid_argument& e)
{
    cout << e.what();
}
```

---

## 🧠 STEP-BY-STEP

### Step 1:
```text
invalid value detected
```

### Step 2:
```text
exception object created
```

### Step 3:
```text
thrown into runtime system
```

### Step 4:
```text
catch receives object
```

### Step 5:
```text
e.what() prints message
```

---

## 🔥 ENGINEERING BENEFIT

✔ Structured errors  
✔ Reusable error types  
✔ Cleaner debugging  

---

# ⚙️ 11.7 catch(...)

---

## 📌 Concept

```text
catch(...) = catch everything
```

---

## 🧪 Example

```cpp
try
{
    throw 3.14;
}
catch(...)
{
    cout << "Exception caught";
}
```

---

## 🧠 Meaning

```text
We don't care about type
We handle ALL errors
```

---

## ⚠️ USE CASE

✔ Unknown error type  
✔ Generic safety fallback  

---

# 🧠 11.8 CORE EXECUTION MODEL (VERY IMPORTANT)

---

## FULL FLOW

```text
try block executes
        ↓
error occurs?
        ↓
YES → throw
        ↓
exit try immediately
        ↓
match catch type
        ↓
execute handler
        ↓
program continues
```

---

# 🌍 11.9 REAL ENGINEERING APPLICATIONS

---

## 🏦 Banking systems

```text
- insufficient balance
- invalid account
- network failure
```

---

## 🖥 Operating Systems

```text
- file not found
- memory error
- permission denied
```

---

## 🎮 Games

```text
- asset loading failure
- invalid state
- physics errors
```

---

## 🗄 Databases

```text
- query failure
- connection lost
```

---

# ⚠️ 11.10 COMMON MISTAKES

---

## ❌ Mistake 1

```text
thinking throw continues execution
```

✔ Wrong → it immediately exits block

---

## ❌ Mistake 2

```text
no matching catch
```

✔ Program crashes

---

## ❌ Mistake 3

```text
catch wrong type
```

✔ Will NOT execute

---

# 🧠 11.11 INTERVIEW QUESTIONS

---

## ❓ What is exception handling?

```text
Mechanism to handle runtime errors safely
```

---

## ❓ Difference between error and exception?

```text
Error → compile/runtime issue
Exception → runtime recoverable issue
```

---

## ❓ What happens if exception not caught?

```text
program terminates
```

---

## ❓ Why use std::exception?

```text
standard structured error handling system
```

---

# 📌 11.12 FINAL SUMMARY

---

## CORE IDEAS

```text
try → risky code
throw → signal error
catch → handle error
```

---

## ENGINEERING VIEW

```text
Exception handling = controlled failure management system
```

---

## FINAL LINE

```text
Good software does NOT avoid errors
it HANDLES them safely
```

---

# 🚀 END OF CHAPTER 11