#include <iostream>
#include <string>

class Wheel {
private:
    double radius;

public:
    Wheel() : radius(0.0) {}  // Default constructor

    Wheel(double radius) : radius(radius) {}

    double getRadius() const {
        return radius;
    }
};

class Car {
private:
    Wheel* wheels;
    std::string* brand;
    double price;

public:
    Car(Wheel* wheels, std::string* brand, double price)
        : wheels(wheels), brand(brand), price(price) {}

    ~Car() {
        delete[] wheels;
        delete brand;
    }

    void print() const {
        std::cout << "Brand: " << *brand << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Wheels: ";
        for (int i = 0; i < 4; i++) {
            std::cout << "Radius " << wheels[i].getRadius() << " ";
        }
        std::cout << std::endl;
    }
};

class Truck : public Car {
private:
    double carryingCapacity;

public:
    Truck(Wheel* wheels, std::string* brand, double price, double carryingCapacity)
        : Car(wheels, brand, price), carryingCapacity(carryingCapacity) {}

    ~Truck() {}

    void print() const {
        Car::print();
        std::cout << "Carrying Capacity: " << carryingCapacity << " tons" << std::endl;
    }
};

int main() {
    // Creating Wheel objects
    Wheel* wheels = new Wheel[4];
    wheels[0] = Wheel(16.5);
    wheels[1] = Wheel(16.5);
    wheels[2] = Wheel(16.5);
    wheels[3] = Wheel(16.5);

    // Creating brand string object
    std::string* brand = new std::string("Toyota");

    // Creating Car object
    Car car(wheels, brand, 25000.0);
    car.print();

    // Creating Truck object
    Truck truck(wheels, brand, 50000.0, 5.0);
    truck.print();

    delete[] wheels;
    delete brand;

    return 0;
}
