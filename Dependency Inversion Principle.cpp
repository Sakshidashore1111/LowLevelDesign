#include <iostream>
using namespace std;

// =======================
// Abstract Classes
// =======================

class Keyboard {
public:
    virtual void connect() = 0;
    virtual ~Keyboard() {}
};

class Mouse {
public:
    virtual void connect() = 0;
    virtual ~Mouse() {}
};

// =======================
// Concrete Keyboard Classes
// =======================

class WiredKeyboard : public Keyboard {
public:
    void connect() override {
        cout << "Wired Keyboard Connected" << endl;
    }
};

class WirelessKeyboard : public Keyboard {
public:
    void connect() override {
        cout << "Wireless Keyboard Connected" << endl;
    }
};

// =======================
// Concrete Mouse Classes
// =======================

class WiredMouse : public Mouse {
public:
    void connect() override {
        cout << "Wired Mouse Connected" << endl;
    }
};

class WirelessMouse : public Mouse {
public:
    void connect() override {
        cout << "Wireless Mouse Connected" << endl;
    }
};

// =======================
// High-Level Module
// =======================

class MacBook {
private:
    Keyboard* keyboard;
    Mouse* mouse;

public:
    // Dependency Injection
    MacBook(Keyboard* k, Mouse* m) {
        keyboard = k;
        mouse = m;
    }

    void start() {
        keyboard->connect();
        mouse->connect();
        cout << "MacBook Started Successfully" << endl;
    }
};

int main() {

    // Choose any keyboard and mouse
    Keyboard* keyboard = new WirelessKeyboard();
    Mouse* mouse = new WiredMouse();

    // Inject dependencies
    MacBook macbook(keyboard, mouse);

    macbook.start();

    delete keyboard;
    delete mouse;

    return 0;
}
