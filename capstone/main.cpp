#include <iostream>
#include <string>
#include "InventoryManager.h"

using namespace std;

bool login() {
    string username, password;
    int attempts = 3;

    cout << "======================================\n";
    cout << "  INVENTORY MANAGEMENT SYSTEM LOGIN\n";
    cout << "======================================\n";

    while (attempts > 0) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "admin123") {
            cout << "\n[Success] Welcome, admin!\n";
            return true;
        } else {
            attempts--;
            cout << "[Error] Invalid. Attempts left: " << attempts << "\n\n";
        }
    }
    return false;
}

int main() {
    if (!login()) return 0; 

    InventoryManager manager; 
    int choice = 0;

    while (choice != 6) {
        cout << "\n========= MAIN MENU =========\n";
        cout << "1. Add New Item\n";
        cout << "2. Edit Existing Item\n";
        cout << "3. Search Item by ID (Binary Search)\n";
        cout << "4. View All Inventory\n";
        cout << "5. Undo Last Addition\n";
        cout << "6. Save and Exit\n";
        cout << "=============================\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addItem(); break;
            case 2: manager.editItem(); break;
            case 3: manager.searchItemById(); break;
            case 4: manager.displayAll(); break;
            case 5: manager.undoLastAddition(); break;
            case 6: cout << "Initiating shutdown...\n"; break;
            default:
                cout << "Invalid option.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
        }
    }

    return 0;
}