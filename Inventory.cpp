#include <iostream>
#include <fstream>
#include <cstdio>
#include "Inventory.h"
#include "FileHandler.h"

using namespace std;

const char* FILE_NAME = "inventory.txt";

void addProduct() {
    ensureFileExists(FILE_NAME);

    Product p, temp;
    bool found = false;

    cout << "Enter ID: ";
    cin >> p.id;
    cout << "Enter Name: ";
    cin >> p.name;
    cout << "Enter Price: ";
    cin >> p.price;
    cout << "Enter Quantity: ";
    cin >> p.quantity;
    cout << "Enter Minimum Stock Level: ";
    cin >> p.minStock;

    ifstream fin(FILE_NAME);
    ofstream fout("temp.txt");

    while (fin >> temp.id >> temp.name >> temp.price >> temp.quantity >> temp.minStock) {
        if (temp.id == p.id) {
            temp.quantity += p.quantity;
            found = true;
        }
        fout << temp.id << " " << temp.name << " " << temp.price << " "
             << temp.quantity << " " << temp.minStock << endl;
    }

    if (!found) {
        fout << p.id << " " << p.name << " " << p.price << " "
             << p.quantity << " " << p.minStock << endl;
    }

    fin.close();
    fout.close();

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    cout << "Product added/updated successfully.\n";
}

void viewProducts() {
    ensureFileExists(FILE_NAME);

    Product p;
    ifstream fin(FILE_NAME);

    cout << "\nID Name Price Qty Min Status\n";

    while (fin >> p.id >> p.name >> p.price >> p.quantity >> p.minStock) {
        cout << p.id << " " << p.name << " " << p.price << " "
             << p.quantity << " " << p.minStock;

        if (p.quantity <= p.minStock)
            cout << " LOW-STOCK";

        cout << endl;
    }

    fin.close();
}

void updateProduct() {
    ensureFileExists(FILE_NAME);

    int id;
    bool found = false;
    Product p;

    cout << "Enter Product ID to update: ";
    cin >> id;

    ifstream fin(FILE_NAME);
    ofstream fout("temp.txt");

    while (fin >> p.id >> p.name >> p.price >> p.quantity >> p.minStock) {
        if (p.id == id) {
            found = true;
            cout << "Enter New Price: ";
            cin >> p.price;
            cout << "Enter New Quantity: ";
            cin >> p.quantity;
            cout << "Enter New Min Stock: ";
            cin >> p.minStock;
        }
        fout << p.id << " " << p.name << " " << p.price << " "
             << p.quantity << " " << p.minStock << endl;
    }

    fin.close();
    fout.close();

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        cout << "Product updated successfully.\n";
    else
        cout << "Product not found.\n";
}

void sellProduct() {
    ensureFileExists(FILE_NAME);

    int id, qty;
    bool found = false;
    Product p;

    cout << "Enter Product ID: ";
    cin >> id;
    cout << "Enter Quantity to Sell: ";
    cin >> qty;

    ifstream fin(FILE_NAME);
    ofstream fout("temp.txt");

    while (fin >> p.id >> p.name >> p.price >> p.quantity >> p.minStock) {
        if (p.id == id) {
            found = true;
            if (p.quantity >= qty) {
                p.quantity -= qty;
                cout << "Product sold successfully.\n";
                if (p.quantity <= p.minStock)
                    cout << "Warning: Low Stock!\n";
            } else {
                cout << "Insufficient stock.\n";
            }
        }
        fout << p.id << " " << p.name << " " << p.price << " "
             << p.quantity << " " << p.minStock << endl;
    }

    fin.close();
    fout.close();

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found)
        cout << "Product not found.\n";
}

void deleteProduct() {
    ensureFileExists(FILE_NAME);

    int id;
    bool found = false;
    Product p;

    cout << "Enter Product ID to delete: ";
    cin >> id;

    ifstream fin(FILE_NAME);
    ofstream fout("temp.txt");

    while (fin >> p.id >> p.name >> p.price >> p.quantity >> p.minStock) {
        if (p.id == id) {
            found = true;
            continue;
        }
        fout << p.id << " " << p.name << " " << p.price << " "
             << p.quantity << " " << p.minStock << endl;
    }

    fin.close();
    fout.close();

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        cout << "Product deleted successfully.\n";
    else
        cout << "Product not found.\n";
}

void checkLowStock() {
    ensureFileExists(FILE_NAME);

    Product p;
    bool any = false;
    ifstream fin(FILE_NAME);

    cout << "\nLow Stock Products:\n";

    while (fin >> p.id >> p.name >> p.price >> p.quantity >> p.minStock) {
        if (p.quantity <= p.minStock) {
            any = true;
            cout << p.id << " " << p.name << " Qty:" << p.quantity << endl;
        }
    }

    if (!any)
        cout << "No low stock items.\n";

    fin.close();
}
