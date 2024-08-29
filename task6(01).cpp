#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Setter for radius
    void setRadius(double r) {
        radius = r;
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Overloading the + operator
    Circle operator+(const Circle &c) {
        Circle temp;
        temp.radius = this->radius + c.radius;
        return temp;
    }
};

int main() {
    Circle c1, c2, c3;

    double radius1, radius2;

    // Taking input for c1 and c2 from the user
    cout << "Enter radius for Circle 1: ";
    cin >> radius1;
    c1.setRadius(radius1);

    cout << "Enter radius for Circle 2: ";
    cin >> radius2;
    c2.setRadius(radius2);

    // Using the overloaded + operator
    c3 = c1 + c2;

    // Getting and displaying the radius for c3
    cout << "Radius of Circle 3 (c1 + c2): " << c3.getRadius() << endl;

    return 0;
}

