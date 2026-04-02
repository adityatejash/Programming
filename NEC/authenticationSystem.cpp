#include <iostream>
using namespace std;

struct User {
    string username;
    string password;
};

int main(){
    User user;

    cout << "Set Username: ";
    cin >> user.username;

    cout << "Set Password: ";
    cin >> user.password;

    string u, p;
    cout << "Username and Password Set!!" << endl;

    cout << "Enter Username: ";
    cin >> u;

    cout << "Enter Password: ";
    cin >> p;

    if (u == user.username && p == user.password){
        cout << "Login Successful!" << endl; 
    } else {
        cout << "Error! Wrong Username or Password!" << endl;
    }
}