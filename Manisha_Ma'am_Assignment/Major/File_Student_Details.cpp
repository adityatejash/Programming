// Q6. Write a program to create a file, write student details into it, and then read the data back from the file. Use file streams (fstream) and demonstrate opening, closing, and reading/writing data.
#include <iostream>
#include <fstream>
using namespace std;
struct Student {
    string name;
    int age;
    Student (string name, int age){
        this->name = name;
        this->age = age;
    }
};
int main(){
    Student s1("ABC DEF", 15);
    Student s2("PQR XYZ",18);

    ofstream fout;
    fout.open("text.txt");
    fout << s1.name << endl;
    fout << s1.age << endl;
    fout << s2.name << endl;
    fout << s2.age << endl;
    fout.close();

    ifstream fin;
    fin.open("text.txt");
    string line;
    while (getline(fin,line)){
        cout << line << endl;
    }
    fin.close();
    return 0;
}