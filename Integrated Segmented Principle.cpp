#include <iostream>
using namespace std;

// Interface for Waiter
class WaiterInterface {
public:
    virtual void serveCustomers() = 0;
    virtual void takeOrder() = 0;

    virtual ~WaiterInterface() {}
};

// Interface for Chef
class ChefInterface {
public:
    virtual void cookFood() = 0;
    virtual void decideMenu() = 0;

    virtual ~ChefInterface() {}
};

// Waiter only implements waiter-related functions
class Waiter : public WaiterInterface {
public:
    void serveCustomers() override {
        cout << "Serving Customers" << endl;
    }

    void takeOrder() override {
        cout << "Taking Customer Order" << endl;
    }
};

// Chef only implements chef-related functions
class Chef : public ChefInterface {
public:
    void cookFood() override {
        cout << "Cooking Food" << endl;
    }

    void decideMenu() override {
        cout << "Deciding Today's Menu" << endl;
    }
};

int main() {

    Waiter waiter;
    Chef chef;

    waiter.takeOrder();
    waiter.serveCustomers();

    cout << endl;

    chef.decideMenu();
    chef.cookFood();

    return 0;
}
