// Wap using array within a class for processing a shopping list
#include <iostream>
#include <string>
using namespace std;

class shopping_list {
    int s_no;
    string list;
    int quantity;

public:
    void set_data(int num) {
        s_no = num;
        cout << "Enter Item Name: ";
        getline(cin, list);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore();
    }

    void display() {
        cout << s_no << ". " << list << " [" << quantity <<"]" << endl;
    }
};

int main() {
    int x;
    cout << "Enter number of elements: ";
    cin >> x;
    cin.ignore();

    shopping_list *sl = new shopping_list[x];

    for (int i = 0; i < x; i++) {
        cout << "Item Number " << i + 1 << ":- " << endl;
        sl[i].set_data(i + 1);
    }

    cout << "\nShopping List:\n";
    for (int i = 0; i < x; i++) {
        sl[i].display();
    }

    delete[] sl;
    return 0;
}
