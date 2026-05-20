#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <vector>
#include "Item.h" 
using namespace std;

class InventoryManager {
private:
    vector<Item*> inventory; 

    void clearInput();
    void sortInventory();

public:
    InventoryManager();
    ~InventoryManager();

    void loadData();
    void saveData();
    void displayAll();
    void addItem();
    void editItem();
    void searchItemById();
    void undoLastAddition();
};

#endif