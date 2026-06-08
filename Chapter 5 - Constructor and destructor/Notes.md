# Constructors in C++ (Detailed Notes)

# Introduction to Constructors

Jab hum kisi class ka object create karte hain, to aksar hume us object ke variables ko initial values deni hoti hain.

Example:

```cpp
Car c1;
```

Agar `Car` class ke andar `brand` aur `year` variables hain, to object banne ke baad hume manually values assign karni padengi:

```cpp
c1.brand = "Toyota";
c1.year = 2022;
```

Lekin agar har object ke liye repeatedly values initialize karni pad rahi hain, to code lengthy aur error-prone ho sakta hai.

Isi problem ko solve karne ke liye **Constructor** use kiya jata hai.

Constructor ek special member function hota hai jo object create hote hi automatically execute ho jata hai.

Programmer ko ise manually call nahi karna padta.

---

# Characteristics of a Constructor

Constructor ki kuch important properties:

1. Constructor ka naam class ke naam ke same hota hai.
2. Constructor ka koi return type nahi hota.
3. Constructor automatically call hota hai.
4. Constructor object ko initialize karne ke liye use hota hai.

Example:

```cpp
class Car
{
public:
    Car()
    {
        // Constructor
    }
};
```

Yahan class ka naam `Car` hai aur constructor ka naam bhi `Car` hai.

---

# Basic Constructor Example

```cpp
#include <iostream>
using namespace std;

class Car
{
public:

    // Object ka data member
    string brand;

    // Constructor
    // Jab bhi Car ka object banega
    // ye function automatically chalega
    Car()
    {
        cout << "Constructor called!" << endl;

        // brand ko default value di ja rahi hai
        brand = "Toyota";
    }

    void display()
    {
        cout << "Car brand: " << brand << endl;
    }
};

int main()
{
    // Object create hua

    // Behind the scenes:
    // Memory allocate hoti hai
    // Constructor automatically run hota hai

    Car c1;

    // Constructor pehle hi brand = Toyota kar chuka hai

    c1.display();

    return 0;
}
```

---

# Behind the Scenes

Jab program is line par pahunchta hai:

```cpp
Car c1;
```

Compiler internally kuch is sequence me kaam karta hai:

### Step 1

Memory allocate hoti hai

```text
c1
+----------------+
| brand          |
+----------------+
```

### Step 2

Constructor automatically call hota hai

```cpp
Car()
{
    brand = "Toyota";
}
```

### Step 3

Memory update hoti hai

```text
c1
+----------------+
| Toyota         |
+----------------+
```

### Step 4

display() call hota hai

```cpp
c1.display();
```

Output:

```text
Car brand: Toyota
```

Isliye constructor ka main purpose object ko initial state me ready karna hota hai.

---

# Types of Constructors

C++ me commonly 3 constructors padhe jate hain:

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor

---

# 1. Default Constructor

Default constructor wo constructor hota hai jo koi argument accept nahi karta.

Example:

```cpp
class Student
{
public:

    Student()
    {
        cout << "Default Constructor Called" << endl;
    }
};
```

Object create karte hain:

```cpp
Student s1;
```

Behind the scenes:

```text
Object Created
        ↓
Constructor Automatically Called
        ↓
Message Printed
```

Output:

```text
Default Constructor Called
```

Yahan programmer ne constructor ko manually call nahi kiya.

Sirf object create hua aur constructor automatically execute ho gaya.

---

# Why Default Constructor?

Default constructor useful hota hai jab hum sabhi objects ko same default values dena chahte hain.

Example:

```cpp
class Student
{
public:

    string name;

    Student()
    {
        name = "Unknown";
    }
};
```

Ab jitne bhi objects banenge:

```cpp
Student s1;
Student s2;
Student s3;
```

Sabka initial name:

```text
Unknown
```

hoga.

---

# 2. Parameterized Constructor

Kabhi-kabhi har object ki values different hoti hain.

Example:

```text
Employee 1 → Alice
Employee 2 → Bob
Employee 3 → John
```

Aise cases me Parameterized Constructor use kiya jata hai.

---

## Example

```cpp
#include <iostream>
using namespace std;

class Employee
{
public:

    string name;
    int salary;

    // Constructor parameters receive karta hai

    Employee(string empName, int empSalary)
    {
        // Received values object ke members me store kar rahe hain

        name = empName;
        salary = empSalary;
    }

    void display()
    {
        cout << "Employee: "
             << name
             << ", Salary: $"
             << salary
             << endl;
    }
};

int main()
{
    // Object create hote hi values pass ki ja rahi hain

    Employee e1("Alice",50000);

    Employee e2("Bob",60000);

    e1.display();
    e2.display();

    return 0;
}
```

---

# Connection Between Constructor Parameters and Variables

Jab ye line execute hoti hai:

```cpp
Employee e1("Alice",50000);
```

Compiler internally sochta hai:

```cpp
Employee("Alice",50000);
```

Constructor receive karta hai:

```cpp
empName = "Alice"

empSalary = 50000
```

Phir:

```cpp
name = empName;
salary = empSalary;
```

ban jata hai:

```cpp
name = "Alice";

salary = 50000;
```

Memory:

```text
e1
+----------------+
| Alice          |
| 50000          |
+----------------+
```

Isi tarah:

```cpp
Employee e2("Bob",60000);
```

Memory:

```text
e2
+----------------+
| Bob            |
| 60000          |
+----------------+
```

Har object apni alag values store karta hai.

---

# 3. Copy Constructor

Copy Constructor ek object ki exact copy banata hai.

---

## Example

```cpp
class Number
{
public:

    int value;

    // Parameterized Constructor

    Number(int v)
    {
        value = v;
    }

    // Copy Constructor

    Number(const Number &obj)
    {
        // Existing object ki value copy kar rahe hain

        value = obj.value;
    }

    void display()
    {
        cout << value << endl;
    }
};
```

---

# Understanding const Number &obj

Ye line beginners ko confusing lagti hai:

```cpp
Number(const Number &obj)
```

Meaning:

```text
obj = existing object
```

Suppose:

```cpp
Number n1(10);
```

Memory:

```text
n1
+--------+
| 10     |
+--------+
```

Ab:

```cpp
Number n2 = n1;
```

Compiler dekhta hai:

```text
Ek object se doosra object create ho raha hai
```

To Copy Constructor call hota hai.

Internally:

```cpp
Number(n1)
```

Yahan:

```cpp
obj = n1
```

Ho jata hai.

Phir ye line execute hoti hai:

```cpp
value = obj.value;
```

Matlab:

```cpp
value = n1.value;
```

Matlab:

```cpp
value = 10;
```

---

# Memory After Copy

Before copy:

```text
n1
+--------+
| 10     |
+--------+
```

After copy:

```text
n1
+--------+
| 10     |
+--------+

n2
+--------+
| 10     |
+--------+
```

Ab dono objects independent hain.

Agar:

```cpp
n2.value = 20;
```

To:

```text
n1 = 10
n2 = 20
```

Copy hone ke baad dono ki memory alag hoti hai.

---

# Summary

## Constructor

Special function jo object create hote hi automatically execute hota hai.

## Default Constructor

Arguments nahi leta.

```cpp
Student()
{
}
```

## Parameterized Constructor

Arguments leta hai.

```cpp
Employee(string n,int s)
{
}
```

## Copy Constructor

Existing object ki copy banata hai.

```cpp
Number(const Number &obj)
{
}
```

## Main Purpose

Object ko initial state me prepare karna aur required values assign karna.

Object Creation Flow:

```text
Object Created
        ↓
Memory Allocated
        ↓
Constructor Called Automatically
        ↓
Variables Initialized
        ↓
Object Ready To Use
```

---
# Destructors in C++ (Detailed Notes)

# Introduction to Destructors

Ab tak humne Constructor padha tha.

Constructor ka kaam tha:

```text
Object Create Hua
        ↓
Constructor Chala
        ↓
Object Initialize Hua
```

Lekin ek question aata hai:

> Jab object ka kaam khatam ho jaye to uski memory ka kya hoga?

Is problem ko handle karne ke liye C++ me **Destructor** use hota hai.

Destructor ek special member function hota hai jo object destroy hone se just pehle automatically execute hota hai.

Programmer ko ise manually call karne ki zarurat nahi hoti.

---

# Real Life Analogy

Socho tum ek room rent par lete ho.

### Entering Room

Jab tum room me enter karte ho:

```text
Room Open
      ↓
Lights ON
      ↓
Fan ON
      ↓
Setup Complete
```

Ye Constructor jaisa hai.

---

### Leaving Room

Jab tum room chhodte ho:

```text
Lights OFF
      ↓
Fan OFF
      ↓
Room Close
```

Ye Destructor jaisa hai.

Destructor cleanup ka kaam karta hai.

---

# What is a Destructor?

Destructor ek special function hai jo object destroy hone par automatically execute hota hai.

Characteristics:

1. Destructor ka naam class ke naam jaisa hota hai.
2. Naam ke aage `~` (tilde) lagta hai.
3. Koi return type nahi hota.
4. Koi parameters nahi hote.
5. Automatically call hota hai.
6. Cleanup ke liye use hota hai.

---

# Syntax

Suppose class ka naam hai:

```cpp
class Test
{
};
```

To destructor hoga:

```cpp
~Test()
{
}
```

Notice:

```cpp
~Test()
```

Ye constructor nahi hai.

Ye destructor hai.

`~` symbol hi destructor ko identify karta hai.

---

# Constructor vs Destructor

| Constructor                       | Destructor                         |
| --------------------------------- | ---------------------------------- |
| Object create hone par chalta hai | Object destroy hone par chalta hai |
| Initialization karta hai          | Cleanup karta hai                  |
| ClassName()                       | ~ClassName()                       |
| Object start hone par             | Object end hone par                |

Example:

```cpp
Test()
{
    cout << "Constructor";
}

~Test()
{
    cout << "Destructor";
}
```

---

# Basic Destructor Example

```cpp
#include <iostream>
using namespace std;

class Test
{
public:

    // Constructor

    Test()
    {
        cout << "Constructor called!" << endl;
    }

    // Destructor

    ~Test()
    {
        cout << "Destructor called!" << endl;
    }
};

int main()
{
    // Object create hua

    Test t1;

    return 0;
}
```

---

# Code Explanation Line by Line

### Class Definition

```cpp
class Test
{
```

Compiler ko bataya ja raha hai:

> Ek class hai jiska naam Test hai.

---

### Constructor

```cpp
Test()
{
    cout << "Constructor called!" << endl;
}
```

Jab bhi Test ka object banega:

```cpp
Test t1;
```

Ye constructor automatically execute hoga.

Output:

```text
Constructor called!
```

---

### Destructor

```cpp
~Test()
{
    cout << "Destructor called!" << endl;
}
```

Jab object destroy hoga:

```cpp
t1
```

to ye destructor automatically chalega.

Output:

```text
Destructor called!
```

---

# Behind The Scenes

Sabse important line:

```cpp
Test t1;
```

Compiler internally kuch is sequence me kaam karta hai.

---

## Step 1: Memory Allocate

```cpp
Test t1;
```

Memory:

```text
t1
+-----------+
| Object    |
+-----------+
```

---

## Step 2: Constructor Call

Compiler automatically:

```cpp
Test()
```

execute karta hai.

Output:

```text
Constructor called!
```

Ab object ready hai.

---

## Step 3: Program Runs

Ab object use ho sakta hai.

```text
t1 exists in memory
```

---

## Step 4: main() Ends

Program is line tak pahunchta hai:

```cpp
return 0;
```

Matlab:

```text
main() function finished
```

Ab `t1` ki zarurat nahi hai.

---

## Step 5: Destructor Call

Compiler automatically:

```cpp
~Test()
```

call karta hai.

Output:

```text
Destructor called!
```

---

## Step 6: Memory Released

Object ki memory free kar di jati hai.

```text
Before:

t1
+-----------+
| Object    |
+-----------+

After:

Memory Released
```

---

# Complete Execution Flow

Program:

```cpp
Test t1;
```

Internally:

```text
Object Created
        ↓
Memory Allocated
        ↓
Constructor Called
        ↓
Object Used
        ↓
main() Ends
        ↓
Destructor Called
        ↓
Memory Released
```

---

# Scope Kya Hota Hai?

Book me likha hai:

> Destructor runs when object goes out of scope.

Scope ka matlab hai:

> Program ka wo area jahan object accessible hai.

Example:

```cpp
int main()
{
    Test t1;

} // Scope Ends Here
```

Object:

```cpp
t1
```

sirf main() ke andar exist karta hai.

Jaise hi:

```cpp
}
```

aata hai,

scope khatam ho jata hai.

Compiler destructor call kar deta hai.

---

# Example of Scope

```cpp
#include <iostream>
using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Created" << endl;
    }

    ~Test()
    {
        cout << "Destroyed" << endl;
    }
};

int main()
{
    {
        Test t1;

        cout << "Inside Block" << endl;

    } // Destructor runs here

    cout << "Outside Block" << endl;
}
```

Output:

```text
Created
Inside Block
Destroyed
Outside Block
```

---

# Why Destructor is Important?

Simple examples me destructor sirf message print karta hai.

Real projects me destructor important resources release karta hai.

Example:

* Dynamic memory
* Files
* Database connections
* Network connections
* Buffers

Suppose:

```cpp
File Open
```

Constructor me hua.

Program khatam hone se pehle:

```cpp
File Close
```

Destructor karega.

Isi liye destructor cleanup manager ke tarah kaam karta hai.

---

# Constructor and Destructor Together

Example:

```cpp
class Test
{
public:

    Test()
    {
        cout << "Object Born" << endl;
    }

    ~Test()
    {
        cout << "Object Died" << endl;
    }
};
```

Execution:

```cpp
Test t1;
```

Flow:

```text
Object Born
       ↓
Object Used
       ↓
Object Died
```

Bilkul insaan ki life cycle jaisa:

```text
Birth
  ↓
Life
  ↓
Death
```

Constructor = Birth

Destructor = Death

---

# Memory Visualization

Object creation:

```cpp
Test t1;
```

Memory:

```text
+-----------+
| t1 Object |
+-----------+
```

Constructor runs:

```text
Object Ready
```

---

Program end:

```text
Destructor Runs
```

Memory:

```text
+-----------+
| Released  |
+-----------+
```

Object ab exist nahi karta.

---

# Important Exam Points

### Constructor

Object create hone par automatically chalta hai.

```cpp
Test()
{
}
```

---

### Destructor

Object destroy hone par automatically chalta hai.

```cpp
~Test()
{
}
```

---

### Destructor Rules

✔ Same name as class

✔ Tilde (~) use hota hai

✔ No parameters

✔ No return type

✔ Automatically called

✔ Cleanup ke liye use hota hai

---

# Summary

Destructor ek special member function hai jo object ke destroy hone se pehle automatically execute hota hai.

Execution Flow:

```text
Object Created
        ↓
Constructor Called
        ↓
Object Used
        ↓
Scope Ends
        ↓
Destructor Called
        ↓
Memory Released
```

Constructor object ko initialize karta hai, jabki Destructor object ki cleanup aur memory release process ko handle karta hai.
