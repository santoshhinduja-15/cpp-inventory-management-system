#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    float price;
    int quantity;
    int minStock;
};

#endif
