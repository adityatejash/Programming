#include <iostream>
#include <vector>
using namespace std;

// User structure
struct User {
    string name;
    vector<string> friends;
};

int main() {
    vector<User> users;
    int choice;

    do {
        cout << endl;
        cout << "--- Social Networking System ---" << endl;
        cout << "1. Create User" << endl;
        cout << "2. Add Friend" << endl;
        cout << "3. Show Friends" << endl;
        cout << "4. Show All Users" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            User u;
            cout << "Enter user name: ";
            cin >> u.name;

            users.push_back(u);
            cout << "User created successfully!" << endl;
            break;
        }

        case 2: {
            string user1, user2;
            cout << "Enter your name: ";
            cin >> user1;
            cout << "Enter friend's name: ";
            cin >> user2;

            bool found1 = false, found2 = false;

            for (auto &u : users) {
                if (u.name == user1) {
                    u.friends.push_back(user2);
                    found1 = true;
                }
                if (u.name == user2) {
                    u.friends.push_back(user1);
                    found2 = true;
                }
            }

            if (found1 && found2) {
                cout << "Friend added successfully!" << endl;
            } else {
                cout << "User not found!" << endl;
            }
            break;
        }

        case 3: {
            string name;
            cout << "Enter user name: ";
            cin >> name;

            bool found = false;

            for (auto &u : users) {
                if (u.name == name) {
                    cout << "Friends of " << name << ": ";
                    for (auto &f : u.friends) {
                        cout << f << " ";
                    }
                    cout << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "User not found!" << endl;
            }
            break;
        }

        case 4: {
            cout << "All Users:" << endl;
            for (auto &u : users) {
                cout << u.name << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}