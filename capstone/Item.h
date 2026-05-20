#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <fstream>

class Item {
protected:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Item(int id, std::string name, double price, int qty) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = qty;
    }
    
    virtual ~Item() {}

    int getId() { return id; }
    std::string getName() { return name; }

    void setPrice(double newPrice) { price = newPrice; }
    void setQuantity(int newQty) { quantity = newQty; }

    virtual void display() = 0; 
    virtual void saveToCSV(std::ofstream& file) = 0; 
};

class Electronic : public Item {
private:
    int warrantyMonths;

public:
    Electronic(int id, std::string name, double price, int qty, int warranty)
        : Item(id, name, price, qty) {
        this->warrantyMonths = warranty;
    }

    void display() {
        std::cout << "[Electronic] ID: " << id << " | Name: " << name 
                  << " | Price: $" << price << " | Qty: " << quantity 
                  << " | Warranty: " << warrantyMonths << " months\n";
    }

    void saveToCSV(std::ofstream& file) {
        file << "1," << id << "," << name << "," 
             << price << "," << quantity << "," << warrantyMonths << "\n";
    }
};

class Clothing : public Item {
private:
    std::string size;

public:
    Clothing(int id, std::string name, double price, int qty, std::string size)
        : Item(id, name, price, qty) {
        this->size = size;
    }

    void display() {
        std::cout << "[Clothing]   ID: " << id << " | Name: " << name 
                  << " | Price: $" << price << " | Qty: " << quantity 
                  << " | Size: " << size << "\n";
    }

    void saveToCSV(std::ofstream& file) {
        file << "2," << id << "," << name << "," 
             << price << "," << quantity << "," << size << "\n";
    }
};

#endif