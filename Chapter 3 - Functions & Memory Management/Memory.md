
# 3.4 Memory Management in C++ (GATE-Level Deep Notes)

Most beginners memorize:

```cpp
int* ptr = new int;
delete ptr;
```

and think:

> "new gives memory, delete removes memory."

That's true, but it's only **5% of the story**.

For GATE, interviews, system programming, OS concepts, and advanced C++, you should understand **what happens inside RAM**, **heap**, **stack**, **CPU**, and **compiler-generated code**.

---

# Why Memory Management Exists?

A computer has limited RAM.

When a program runs, it needs memory for:

* Variables
* Functions
* Arrays
* Objects
* User input
* Temporary calculations

The OS allocates memory to the program.

The program must use it efficiently.

---

# Memory Layout of a Running C++ Program

When a C++ program starts, the Operating System creates a process.

That process gets memory divided into segments.

```text
+--------------------+
|      Stack         |
+--------------------+
|                    |
|                    |
|     Free Space     |
|                    |
|                    |
+--------------------+
|       Heap         |
+--------------------+
| Global/Static Data |
+--------------------+
|      Code/Text     |
+--------------------+
```

---

# 1. Code Segment (Text Segment)

Contains:

```cpp
int main()
{
}
```

machine instructions.

Example:

```cpp
cout<<"Hello";
```

is converted into machine code and stored here.

Characteristics:

✔ Read-only

✔ Exists throughout execution

---

# 2. Data Segment

Stores:

### Global Variables

```cpp
int x = 10;
```

### Static Variables

```cpp
static int count = 0;
```

Characteristics:

✔ Created before main()

✔ Destroyed after program ends

---

# 3. Stack Memory

Stores:

* Local variables
* Function parameters
* Return addresses

Example:

```cpp
void fun()
{
    int x = 5;
}
```

`x` goes into Stack.

---

# Internal Working of Stack

Imagine:

```cpp
int main()
{
    int a = 10;
    int b = 20;
}
```

Memory:

```text
STACK

+------+
| b=20 |
+------+
| a=10 |
+------+
```

LIFO Structure:

Last In First Out

Like a stack of plates 🍽️

---

# Stack Advantages

✔ Very fast

✔ Automatically managed

✔ No memory leaks

---

# Stack Limitations

Size is limited.

Example:

```cpp
int arr[100000000];
```

May cause:

```text
Stack Overflow
```

because stack memory is small.

---

# 4. Heap Memory

The most important topic here.

Heap is a large memory region used for:

### Dynamic Memory Allocation

Memory allocated during runtime.

---

# Why Heap?

Suppose user enters array size:

```cpp
int n;
cin >> n;
```

Compiler doesn't know `n` beforehand.

So stack allocation isn't enough.

Need runtime allocation.

Heap solves this.

---

# Real-Life Analogy

Imagine a hotel.

## Stack = Reserved Rooms

Fixed and organized.

Reception automatically manages them.

---

## Heap = Open Land

You can build as much as you need.

But YOU must manage it.

Forget to clean it?

Problems occur.

---

# Dynamic Memory Allocation

Dynamic = decided during execution.

Not during compilation.

---

# Before Dynamic Allocation

```cpp
int x;
```

Compiler allocates memory at compile time.

Size known.

---

# Dynamic Allocation

```cpp
int* ptr = new int;
```

Memory allocated while program is running.

---

# What Exactly Happens in

```cpp
int* ptr = new int;
```

Let's go step by step.

---

## Step 1

Compiler sees:

```cpp
int* ptr;
```

Creates pointer variable.

Stored in stack.

Memory:

```text
STACK

ptr = ?
```

---

## Step 2

Program executes:

```cpp
new int
```

Request sent to heap manager.

Internally something similar to:

```cpp
malloc(sizeof(int))
```

happens (simplified view).

---

## Step 3

Heap manager finds free memory.

Suppose address:

```text
5000
```

allocated.

Heap:

```text
Address 5000
+------+
| ???  |
+------+
```

---

## Step 4

Address returned.

```cpp
ptr = 5000;
```

Memory becomes:

```text
STACK
+-----------+
| ptr=5000  |
+-----------+

HEAP
Address 5000
+------+
| ???  |
+------+
```

---

# Important Observation

Pointer is in STACK.

Actual data is in HEAP.

Students often confuse this.

```cpp
int* ptr = new int;
```

creates memory in two places:

### Stack

```text
ptr
```

### Heap

```text
integer storage
```

---

# Writing Value

```cpp
*ptr = 50;
```

Means:

Go to address stored inside ptr.

Store 50 there.

---

Before:

```text
Address 5000
+------+
| ???  |
+------+
```

After:

```text
Address 5000
+------+
| 50   |
+------+
```

---

# Reading Value

```cpp
cout << *ptr;
```

Process:

### Step 1

Read ptr.

```text
5000
```

### Step 2

Go to address 5000.

### Step 3

Read value.

```text
50
```

Output:

```text
50
```

---

# Visualization

```text
STACK

ptr
 |
 |
 v

HEAP
Address 5000
+------+
|  50  |
+------+
```

---

# Dereferencing

Operator:

```cpp
*
```

called Dereference Operator.

---

## Meaning

Pointer stores address.

Dereference accesses actual data.

Example:

```cpp
ptr = 5000;
```

```cpp
*ptr
```

means:

> Go to address 5000 and access value.

---

# Internal Working of delete

Code:

```cpp
delete ptr;
```

Most students think:

> delete destroys pointer.

Wrong.

Let's see.

---

Before delete:

```text
STACK
ptr = 5000

HEAP
5000 -> 50
```

---

When delete executes:

```cpp
delete ptr;
```

Heap manager marks memory free.

```text
HEAP
5000 -> AVAILABLE
```

---

Pointer still exists!

```text
STACK
ptr = 5000
```

still remains.

---

# Dangerous Situation: Dangling Pointer

After delete:

```cpp
delete ptr;
```

pointer still contains old address.

```text
ptr = 5000
```

But memory no longer belongs to you.

This is called:

# Dangling Pointer

---

Example

```cpp
delete ptr;

cout << *ptr;
```

Undefined Behavior.

Possible outcomes:

* Garbage value
* Crash
* Works sometimes
* Security issue

Anything can happen.

---

# Good Practice

After delete:

```cpp
delete ptr;
ptr = nullptr;
```

Now:

```text
ptr = NULL
```

Safe.

---

# Memory Leak

One of the most important GATE/interview topics.

---

Example

```cpp
int* ptr = new int;

ptr = nullptr;
```

What happened?

Original heap memory lost.

Address forgotten.

Cannot free it anymore.

Memory remains occupied.

---

This is called:

# Memory Leak

---

Visualization

Before:

```text
ptr ---> Heap Memory
```

After:

```text
ptr = nullptr
```

Heap block still exists.

But no way to reach it.

Lost forever until program ends.

---

# Correct Version

```cpp
delete ptr;
ptr = nullptr;
```

---

# Dynamic Array Allocation

Single Variable:

```cpp
int* ptr = new int;
```

Array:

```cpp
int* arr = new int[5];
```

Memory:

```text
Heap

+----+
|arr0|
+----+
|arr1|
+----+
|arr2|
+----+
|arr3|
+----+
|arr4|
+----+
```

---

Accessing

```cpp
arr[0]
arr[1]
arr[2]
```

works normally.

---

# Releasing Dynamic Array

Wrong:

```cpp
delete arr;
```

Correct:

```cpp
delete[] arr;
```

Reason:

Heap manager must know multiple elements exist.

---

# new vs malloc()

| new                  | malloc()      |
| -------------------- | ------------- |
| C++                  | C             |
| Type safe            | Not type safe |
| Calls constructor    | Doesn't       |
| Returns correct type | Returns void* |
| Uses delete          | Uses free     |

---

Example

```cpp
int* ptr = new int;
```

Equivalent C code:

```cpp
int* ptr = (int*)malloc(sizeof(int));
```

---

# Time Complexity View

Stack Allocation

```cpp
int x;
```

Very fast.

Usually O(1).

---

Heap Allocation

```cpp
new int;
```

Slower.

Why?

Heap manager must:

1. Search free block
2. Reserve block
3. Update metadata
4. Return address

Extra work involved.

---

# GATE-Level Comparison

| Feature     | Stack          | Heap         |
| ----------- | -------------- | ------------ |
| Allocation  | Automatic      | Manual       |
| Speed       | Faster         | Slower       |
| Size        | Small          | Large        |
| Managed By  | Compiler       | Programmer   |
| Lifetime    | Function scope | Until delete |
| Memory Leak | Impossible     | Possible     |
| Overflow    | Stack Overflow | Rare         |

---

# Complete Program Walkthrough

```cpp
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int;

    *ptr = 50;

    cout << *ptr << endl;

    delete ptr;

    ptr = nullptr;

    return 0;
}
```

### Memory Timeline

### After Declaration

```text
STACK
ptr = ?
```

---

### After new

```text
STACK
ptr = 5000

HEAP
5000 -> ?
```

---

### After Assignment

```text
STACK
ptr = 5000

HEAP
5000 -> 50
```

---

### After Output

```text
Prints 50
```

---

### After delete

```text
STACK
ptr = 5000

HEAP
free
```

---

### After nullptr

```text
STACK
ptr = nullptr

HEAP
free
```

---

# Exam-Oriented One-Liners

✅ `new` allocates memory from Heap.

✅ `delete` releases Heap memory.

✅ Pointer variable usually resides in Stack.

✅ Actual dynamically allocated data resides in Heap.

✅ Accessing memory after delete causes Dangling Pointer.

✅ Losing reference to allocated memory causes Memory Leak.

✅ Arrays allocated using `new[]` must be released using `delete[]`.

✅ Stack memory is automatically managed.

✅ Heap memory is manually managed.

---

# GATE/Interview MCQs

### 1. Where is dynamically allocated memory stored?

A) Code Segment
B) Stack
C) Heap
D) Data Segment

✅ Answer: C

---

### 2. In `int* ptr = new int;`, where is `ptr` stored?

A) Heap
B) Stack
C) ROM
D) Cache

✅ Answer: B

---

### 3. What does `delete ptr;` do?

A) Deletes pointer variable

B) Frees Heap memory pointed by ptr

C) Deletes Stack

D) Deletes program

✅ Answer: B

---

### 4. Accessing memory after `delete` creates:

A) Null Pointer

B) Wild Pointer

C) Dangling Pointer

D) Smart Pointer

✅ Answer: C

---

### 5. Which causes memory leak?

```cpp
int* p = new int;
p = nullptr;
```

A) No leak

B) Compile error

C) Memory leak

D) Stack overflow

✅ Answer: C

---

### 6. Which is correct for dynamic arrays?

A) `delete arr;`

B) `delete[] arr;`

C) `free(arr);`

D) Both A and C

✅ Answer: B

---

### 7. Which memory is automatically reclaimed when a function returns?

A) Heap

B) Stack

C) ROM

D) Cache

✅ Answer: B

This level of understanding is typically enough not just for university exams, but also for GATE questions on **memory organization, pointers, heap vs stack, dynamic allocation, memory leaks, and runtime behavior**. 🚀
