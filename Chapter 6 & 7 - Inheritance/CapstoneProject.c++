#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    void displayInfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};
class Teacher :virtual public Person {
    public:
    void teach(){
        cout << "I am a teacher." << endl;
    }
};
class Researcher : virtual public Person{
    public:
    void research(){
        cout << "I do researches." << endl;
    }
};
class Professor : virtual public Person, Teacher{
    public:
    void manages_Phd_Students(){
        cout << "I manage all my Phd Students." << endl;
    }
};
int main(){
    Teacher t1;
    t1.name = "Gaurav";
    t1.age = 28;
    t1.displayInfo();
    t1.teach();
    return 0;
}