// Example: Allocating and Releasing Memory Dynamically
#include <iostream>
using namespace std;
int main()
{
    int *ptr = new int; // Dynamically allocate memory
    *ptr = 50;
    cout << "Value: " << *ptr << endl;
    delete ptr; // Free allocated memory
    cout << "Value after delete : " << *ptr << endl;
    return 0;
}