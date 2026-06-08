#include <iostream>
using namespace std;
class Car
{
public: 
    string brand; // Object ka data member
    Car() // Constructor
    // Jab bhi Car ka object banega
    // ye function automatically chalega
    {
        cout << "Constructor called!" << endl; // brand ko default value di ja rahi hai
        brand = "Toyota";
    }
    void display() { cout << "Car brand: " << brand << endl; }
};
int main()
{           // Object create hua
            // Behind the scenes:
            // Memory allocate hoti hai
            // Constructor automatically run hota hai
    Car c1; // Constructor pehle hi brand = Toyota kar chuka hai
    c1.display();
    return 0;
}