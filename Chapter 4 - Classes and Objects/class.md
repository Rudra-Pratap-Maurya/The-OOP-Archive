=
```cpp
// iostream library include ki gayi hai.
// Is library me cout aur endl jaise objects/functions defined hote hain.
#include <iostream>

// std namespace use karne se hame std::cout ki jagah sirf cout likhna padta hai.
using namespace std;

// Car naam ki ek class banayi ja rahi hai.
// Class ek blueprint/template hoti hai.
// Is point par koi actual car create nahi hui hai.
class Car
{
    // public ka matlab:
    // Iske niche jo members hain unhe class ke bahar se access kiya ja sakta hai.
public:

    // brand naam ka string variable.
    // Har object ke paas apni alag copy hogi.
    string brand;

    // year naam ka integer variable.
    // Har object ke paas apni alag copy hogi.
    int year;

    // display() naam ka member function.
    // Ye function object ki information print karega.
    void display()
    {
        // Jab ye function chalega to current object ke
        // brand aur year ki values print hongi.

        cout << "Car: " << brand
             << ", Year: " << year
             << endl;
    }
};

// Program execution yahan se start hoti hai.
int main()
{
    // Car class ka object create kiya ja raha hai.
    // Behind the scenes:
    // Memory me ek block reserve hota hai jisme
    // brand aur year store honge.

    Car car1;

    // Object ke brand member me "Toyota" store kiya ja raha hai.
    // Dot operator (.) object ke members access karne ke liye use hota hai.
    car1.brand = "Toyota";

    // Object ke year member me 2022 store kiya ja raha hai.
    car1.year = 2022;

    // display() function call kiya ja raha hai.
    // Behind the scenes:
    // Compiler internally isse kuch is tarah samajhta hai:
    // car1.display(&car1)
    //
    // Yani function ko pata hota hai ki kis object par
    // kaam karna hai. Iske liye hidden pointer "this"
    // use hota hai.

    car1.display();

    // Function ke andar:
    // brand actually this->brand hota hai.
    // year actually this->year hota hai.
    //
    // Is case me:
    // this->brand = "Toyota"
    // this->year = 2022
    //
    // Output:
    // Car: Toyota, Year: 2022

    // Program successfully khatam.
    return 0;
}
```

## Behind the Scenes (Memory View)

Jab ye line execute hoti hai:

```cpp
Car car1;
```

Memory me kuch aisa banta hai:

```text
car1
+------------------+
| brand = ""       |
| year  = garbage  |
+------------------+
```

Values assign karne ke baad:

```cpp
car1.brand = "Toyota";
car1.year = 2022;
```

Memory:

```text
car1
+------------------+
| brand = Toyota   |
| year  = 2022     |
+------------------+
```

---

## Behind the Scenes of display()

Jab tum likhte ho:

```cpp
car1.display();
```

Compiler internally kuch conceptually aisa sochta hai:

```cpp
display(&car1);
```

Aur function ke andar hidden pointer:

```cpp
this
```

`this` pointer current object ka address rakhta hai.

Isliye:

```cpp
brand
```

actually hota hai:

```cpp
this->brand
```

Aur:

```cpp
year
```

actually hota hai:

```cpp
this->year
```

---

## Real Life Analogy 🚗

```cpp
class Car
```

Blueprint:

```text
Car
 ├─ brand
 ├─ year
 └─ display()
```

Object:

```cpp
Car car1;
```

Real car:

```text
car1
 ├─ Toyota
 ├─ 2022
 └─ display()
```

Aur agar doosra object banao:

```cpp
Car car2;
car2.brand = "Honda";
car2.year = 2020;
```

To memory me:

```text
car1 -> Toyota, 2022
car2 -> Honda, 2020
```

Dono same blueprint (Car class) se bane hain, lekin data alag-alag store karte hain. Yahi Object-Oriented Programming (OOP) ka basic idea hai. 🚀
