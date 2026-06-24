#include <iostream>
using namespace std;

// Common functionality for all vehicles
class Vehicle {
public:
    virtual void accelerate() = 0;
    virtual ~Vehicle() {}
};

// Only engine vehicles can start engines
class EngineVehicle : public Vehicle {
public:
    virtual void turnOnEngine() = 0;
};

// Motorcycle has an engine
class MotorCycle : public EngineVehicle {
private:
    bool isEngineOn;
    int speed;

public:
    MotorCycle() {
        isEngineOn = false;
        speed = 0;
    }

    void turnOnEngine() override {
        isEngineOn = true;
        cout << "Engine Started\n";
    }

    void accelerate() override {
        speed += 10;
        cout << "MotorCycle Speed: " << speed << endl;
    }
};

// Bicycle does not have an engine
class Bicycle : public Vehicle {
private:
    int speed;

public:
    Bicycle() {
        speed = 0;
    }

    void accelerate() override {
        speed += 5;
        cout << "Bicycle Speed: " << speed << endl;
    }
};

int main() {

    EngineVehicle* bike1 = new MotorCycle();

    bike1->turnOnEngine();
    bike1->accelerate();

    cout << endl;

    Vehicle* bike2 = new Bicycle();

    bike2->accelerate();

    delete bike1;
    delete bike2;

    return 0;
}
