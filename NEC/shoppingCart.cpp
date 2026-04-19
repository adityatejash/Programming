#include <iostream>
#include <vector>
using namespace std;

struct product {
    string name;
    double price;
};

struct cart {
    string name;
    int quantity;
    double price;
};

int main() {
    vector<product> products = {
        {"Laptop", 50000},
        {"Phone", 20000},
        {"Mouse", 600},
        {"Headphones", 2000}
    };

    vector<cart> mycart;

    int choice;

    do {
        cout << endl;
        cout << "--- Shopping Cart ---" << endl;
        cout << "1. Available Products" << endl;
        cout << "2. Add to Cart" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << endl << "Available Products:" << endl;
            for (int i = 0; i < products.size(); i++) {
                cout << i + 1 << ". " << products[i].name
                     << " - Rs " << products[i].price << endl;
            }
            break;
        }

        case 2: {
            int i, q;
            cout << "Enter Product Number: ";
            cin >> i;

            if (i < 1 || i > products.size()) {
                cout << "Invalid!!" << endl;
                break;
            }

            cout << "Enter Quantity: ";
            cin >> q;

            cart item;
            item.name = products[i - 1].name;
            item.price = products[i - 1].price;
            item.quantity = q;

            mycart.push_back(item);

            cout << "Item added to cart!" << endl;
            break;
        }

        case 3: {
            double total = 0;
            cout << endl << "Your Cart:" << endl;

            for (auto &item : mycart) {
                double cost = item.price * item.quantity;
                cout << item.name << " x " << item.quantity
                     << " = Rs " << cost << endl;
                total += cost;
            }

            cout << "Total = Rs " << total << endl;
            break;
        }

        case 4: {
            double total = 0;

            for (auto &item : mycart) {
                total += item.price * item.quantity;
            }

            cout << endl << "Total Amount = Rs " << total << endl;
            cout << "Checkout Successful!" << endl;

            mycart.clear();
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