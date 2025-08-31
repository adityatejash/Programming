// Q8. Design a class hierarchy where Person is the base class, Employee inherits from Person, and Manager inherits from Employee. Demonstrate data members and member functions at each level.
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    void setPersonDetails (){
        cout << "-----Enter person Details-----" << endl;
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }
    void showPersonDetails (){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Employee : public Person {
public:
    string empID;
    string department;
    void setEmployeeDetails (){
        cout << "-----Enter Employee Details-----" << endl;
        cout << "Enter Employee ID: ";
        getline(cin,empID);
        cout << "Enter Department: ";
        getline(cin, department);
    }
    void showEmployeeDetails(){
        cout << "Employee ID: " << empID << endl;
        cout << "Department: " << department << endl;
    }
};
class Manager : public Employee {
public:
    int teamMembers;
    void setManagerDetails (){
        cout << "-----Enter Manager Details-----" << endl;
        cout << "Enter no. of team memners: ";
        cin >> teamMembers;
        cin.ignore();
    }
    void showManagerDetails(){
        cout << "Team Members: " << teamMembers << endl;
    }
};
int main(){
    Manager m;
    m.setPersonDetails();
    m.setEmployeeDetails();
    m.setManagerDetails();
    cout << "-----Details-----" << endl;
    m.showPersonDetails();
    m.showEmployeeDetails();
    m.showManagerDetails();
    return 0;
}