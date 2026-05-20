#include "InventoryManager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


InventoryManager::InventoryManager() {
    loadData();
}

InventoryManager::~InventoryManager() {
    saveData();
    for (int i = 0; i < inventory.size(); i++) {
        delete inventory[i]; 
    }
    inventory.clear();
}

// Private Helpers
void InventoryManager::clearInput() {
    cin.clear();
    cin.ignore(1000, '\n'); 
}

void InventoryManager::sortInventory() {
    int n = inventory.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (inventory[j]->getId() > inventory[j + 1]->getId()) {
                Item* temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
}

// Public Methods
void InventoryManager::loadData() {
    ifstream file("inventory.csv");
    if (!file.is_open()) {
        cout << "[System] No CSV file found. Starting fresh.\n";
        return;
    }

    int type, id, qty, warranty;
    double price;
    string name, size;
    char comma;

    while (file >> type >> comma >> id >> comma) {
        getline(file, name, ','); 
        file >> price >> comma >> qty >> comma;

        if (type == 1) {
            file >> warranty;
            inventory.push_back(new Electronic(id, name, price, qty, warranty));
        } else if (type == 2) {
            getline(file, size); 
            inventory.push_back(new Clothing(id, name, price, qty, size));
        }
    }
    file.close();
    cout << "[System] Data loaded from inventory.csv\n";
}

void InventoryManager::saveData() {
    ofstream file("inventory.csv");
    for (int i = 0; i < inventory.size(); i++) {
        inventory[i]->saveToCSV(file); 
    }
    file.close();
    cout << "[System] Data safely saved to inventory.csv\n";
}

void InventoryManager::displayAll() {
    cout << "\n--- Current Inventory ---\n";
    if (inventory.size() == 0) {
        cout << "Inventory is empty.\n";
        return;
    }
    for (int i = 0; i < inventory.size(); i++) {
        inventory[i]->display(); 
    }
    cout << "-------------------------\n";
}

void InventoryManager::addItem() {
    int type, id, qty, warranty;
    double price;
    string name, size;

    cout << "\n--- Add New Item ---\nSelect Type (1 for Electronic, 2 for Clothing): ";
    cin >> type;

    cout << "Enter ID: ";
    cin >> id;
    clearInput();

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Price: $";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> qty;

    switch (type) {
        case 1:
            cout << "Enter Warranty (Months): ";
            cin >> warranty;
            inventory.push_back(new Electronic(id, name, price, qty, warranty));
            break;
        case 2:
            clearInput();
            cout << "Enter Size (S/M/L/XL): ";
            getline(cin, size);
            inventory.push_back(new Clothing(id, name, price, qty, size));
            break;
        default:
            cout << "Invalid type.\n";
            return;
    }
    cout << "\n[Success] Item added to inventory!\n";
}

void InventoryManager::editItem() {
    int targetId;
    cout << "\n--- Edit Item ---\nEnter Item ID to edit: ";
    cin >> targetId;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i]->getId() == targetId) {
            int choice;
            cout << "\nItem Found:\n";
            inventory[i]->display();
            
            cout << "\nUpdate: \n1. Price \n2. Quantity\nChoice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    double newPrice;
                    cout << "Enter new price: $";
                    cin >> newPrice;
                    inventory[i]->setPrice(newPrice);
                    cout << "Price updated.\n";
                    break;
                case 2:
                    int newQty;
                    cout << "Enter new quantity: ";
                    cin >> newQty;
                    inventory[i]->setQuantity(newQty);
                    cout << "Quantity updated.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            return;
        }
    }
    cout << "[Error] Item not found.\n";
}

void InventoryManager::searchItemById() {
    int targetId;
    cout << "\n--- Search Inventory ---\nEnter Item ID: ";
    cin >> targetId;

    sortInventory(); 

    int left = 0, right = inventory.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (inventory[mid]->getId() == targetId) {
            cout << "\n[Found via Binary Search] ->\n";
            inventory[mid]->display();
            found = true;
            break;
        } else if (inventory[mid]->getId() < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) cout << "\n[Error] Item not found.\n";
}

void InventoryManager::undoLastAddition() {
    if (inventory.size() == 0) {
        cout << "\n[Error] Nothing to undo.\n";
        return;
    }
    Item* lastItem = inventory[inventory.size() - 1];
    cout << "\n[Undo] Removed: " << lastItem->getName() << "\n";
    inventory.pop_back(); 
    delete lastItem;     
}