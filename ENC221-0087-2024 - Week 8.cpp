
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Square class
class Square {
private:
    double side;

public:
    // Constructor
    Square(double side) : side(side) {}

    // Method to get side length
    double getSide() const { return side; }

    // Method to calculate area
    double getArea() const { return side * side; }

    // Display square information
    virtual void displayInfo() const {
        cout << "Square - Side: " << side << endl;
        cout << "Area: " << getArea() << endl;
    }
    
    // Virtual destructor
    virtual ~Square() {}
};

// Cube class extends Square
class Cube : public Square {
public:
    // Constructor
    Cube(double side) : Square(side) {}

    // Method to calculate volume
    double getVolume() const {
        double side = getSide();
        return pow(side, 3);
    }

    // Method to calculate surface area
    double getSurfaceArea() const {
        return 6 * getArea();
    }

    // Override display to show cube information
    void displayInfo() const override {
        cout << "Cube - Side: " << getSide() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Volume: " << getVolume() << endl;
    }
};

// Test the classes
int main() {
    cout << "=== Shape Inheritance Test ===" << endl << endl;

    // Create Square object
    Square square(5.0);
    cout << "Square Test:" << endl;
    square.displayInfo();

    cout << endl << string(40, '=') << endl << endl;

    // Create Cube objects
    Cube cube1(4.0);
    cout << "Cube Test:" << endl;
    cube1.displayInfo();

    cout << endl << string(40, '=') << endl << endl;

    Cube cube2(10.0);
    cout << "Large Cube Test:" << endl;
    cube2.displayInfo();

    return 0;
}