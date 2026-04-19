#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> user_pass;

    string username, password;

    // Register user
    cout << "Enter Username: ";
    cin >> username;

    cout << "Set Password: ";
    cin >> password;

    user_pass[username] = password;

    cout << "\nUser Registered Successfully!" << endl;

    int attempt = 3;
    string u, p;

    // Login system
    while (attempt--) {
        cout << "\nEnter Username: ";
        cin >> u;

        cout << "Enter Password: ";
        cin >> p;

        if (user_pass.find(u) == user_pass.end()) {
            cout << "User does not exist!" << endl;
        } else if (user_pass[u] != p) {
            cout << "Wrong Password!" << endl;
        } else {
            cout << "Login Successful!" << endl;
            return 0;
        }

        cout << "Attempts left: " << attempt << endl;
    }

    cout << "Account Locked!" << endl;
    return 0;
}