#include <iostream>
#include <string>
using namespace std;

class Bakery {
private:
    static const int MAX_ITEMS = 5;
    int welcomeno;
    string displayfood;
    float displayrate;
    string food[MAX_ITEMS + 1] = {"", "Cookies", "Coffee", "Brownies", "Hot Pudding", "Pandecoco"};
    float rate[MAX_ITEMS + 1] = {0, 2.00, 4.50, 3.00, 3.00, 1.50};
    float stock[MAX_ITEMS + 1] = {0, 8, 50, 40, 34, 30};
    int Choice, Quantity, ItemIndex;

public:
    void welcome();
    int welcomereturn();
    void itemlist();
    void setitemlist();
    void adminpanel();
    void exit();
    void displayMenu();
};

void Bakery::welcome() {
    cout << "\n\t\t\t\t\t\tWelcome to JK Bakery's\n";
    cout << " >> 1. Bakery Item List\n";
    cout << " >> 2. Admin Panel\n";
    cout << " >> 3. Exit\n";
    cout << " Select: ";
    cin >> welcomeno;
}

int Bakery::welcomereturn() {
    return welcomeno;
}

void Bakery::itemlist() {
    cout << "\n |  Item No.  |   Item Name    |  Price    | In Stock |\n";
    cout << " ------------------------------------------------------\n";
    for (int i = 1; i <= MAX_ITEMS; i++) {
        cout << " |     " << i << "      |     " << food[i] << "    |    " << rate[i] << "   |    " << stock[i] << "    |\n";
        cout << " ------------------------------------------------------\n";
    }
    cout << " Place Your Order: ";
    cin >> Choice;
    cout << " Enter Item Quantity: ";
    cin >> Quantity;
}

void Bakery::setitemlist() {
    if (Choice >= 1 && Choice <= MAX_ITEMS) {
        ItemIndex = Choice;
        displayfood = food[ItemIndex];
        if (Quantity <= stock[ItemIndex] && Quantity > 0) {
            displayrate = rate[ItemIndex];
            stock[ItemIndex] -= Quantity; // Deduct ordered quantity from stock
            cout << "\n Choice item: " << displayfood << " Quantity: " << Quantity << " Total Cost: " << displayrate * Quantity << "\n";
            cout << " Remaining Stock: " << stock[ItemIndex] << "\n";
        } else {
            cout << " Insufficient stock for " << displayfood << ". Available: " << stock[ItemIndex] << "\n";
        }
    } else {
        cout << " Invalid choice. Please select a valid item number.\n";
    }
}

void Bakery::adminpanel() {
    cout << "\n Welcome to JK Bakery's Admin Panel\n";
    // Add admin functionality here
}

void Bakery::exit() {
    cout << "\n Thank You For Using Our System.\n";
}

void Bakery::displayMenu() {
    do {
        welcome();
        switch (welcomereturn()) {
            case 1:
                itemlist();
                setitemlist();
                break;
            case 2:
                adminpanel();
                break;
            case 3:
                exit();
                break;
            default:
                cout << " Invalid selection. Please try again.\n";
        }
    } while (welcomereturn() != 3);
}

int main() {
    Bakery b;
    b.displayMenu();
    return 0;
}


