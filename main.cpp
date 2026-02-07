#include <iostream>
#include "Inventory.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n==== Inventory Management System ====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Update Product\n";
        cout << "4. Sell Product\n";
        cout << "5. Delete Product\n";
        cout << "6. View Low Stock Products\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: sellProduct(); break;
            case 5: deleteProduct(); break;
            case 6: checkLowStock(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
