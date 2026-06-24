#include <iostream>
#include <stdexcept>
using namespace std;

// Interface equivalent in C++
class Bike {
public:
    virtual void turnOnEngine() = 0;
    virtual void accelerate() = 0;

    virtual ~Bike() {}
};

// MotorCycle implements Bike
class MotorCycle : public Bike {
private:
    bool isEngineOn;
    int speed;

public:
    MotorCycle() {
        isEngineOn = false;
        speed = 0;
    }

    void turnOnEngine() override {
        // Turn on the engine
        isEngineOn = true;
    }

    void accelerate() override {
        // Increase the speed
        speed = speed + 10;
    }
};

// Bicycle implements Bike
class Bicycle : public Bike {
public:
    void turnOnEngine() override {
        throw runtime_error("There is no engine");
    }

    void accelerate() override {
        // Increase speed by pedaling
        cout << "Bicycle is accelerating" << endl;
    }
};

int main() {
    Bike* bike1 = new MotorCycle();

    bike1->turnOnEngine();
    bike1->accelerate();

    Bike* bike2 = new Bicycle();

    try {
        bike2->turnOnEngine();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    delete bike1;
    delete bike2;

    return 0;
}
