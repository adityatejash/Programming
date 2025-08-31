// Q2. Create a class Student with private data members for name, roll number, and marks. Implement public member functions to input data, display data, and calculate grade based on marks. Instantiate multiple objects and demonstrate their usage
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks: ";
        cin >> marks;
        cin.ignore(); // Clear newline character after entering marks
    }

    void displayData() {
        cout << "\nName: " << name << "\nRoll Number: " << rollNumber << "\nMarks: " << marks << "\nGrade: " << calculateGrade() << "\n";
    }

    char calculateGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 40) return 'D';
        else return 'F';
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // Clear newline after entering n

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].inputData();
    }

    cout << "\n--- Student Details ---";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":";
        students[i].displayData();
    }

    return 0;
}
