// Example: Using Default Arguments
#include <iostream>
using namespace std;
void display(string name = "Guest")
{
    cout << "Hello, " << name << "!" << endl;
}
int main()
{
    display();        // Uses default argument "Guest"
    display("Alice"); // Uses passed argument "Alice"
    return 0;
}