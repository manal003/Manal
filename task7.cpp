#include <iostream>
using namespace std;

// Base class
class Base {
private:
    int secret;

protected:
    int protect;

public:
    int access;

    // Default constructor to initialize data members
    Base() : secret(1), protect(2), access(3) {}
};

// Derived class using private inheritance
class Derived_Private : private Base {
public:
    // Function to display values of Base class members
    void show() {
        // Uncommenting the next line will cause a compile-time error
        cout << "Secret: " << secret << endl; // Error: Cannot access private member
        cout << "Protect: " << protect << endl; // Accessible due to inheritance
        cout << "Access: " << access << endl;   // Accessible due to inheritance
    }
};

// Derived class using protected inheritance
class Derived_Protected : protected Base {
public:
    // Function to display values of Base class members
    void show() {
        // Uncommenting the next line will cause a compile-time error
        cout << "Secret: " << secret << endl; // Error: Cannot access private member
        cout << "Protect: " << protect << endl; // Accessible due to inheritance
        cout << "Access: " << access << endl;   // Accessible due to inheritance
    }
};

// Derived class using public inheritance
class Derived_Public : public Base {
public:
    // Function to display values of Base class members
    void show() {
        // Uncommenting the next line will cause a compile-time error
         cout << "Secret: " << secret << endl; // Error: Cannot access private member
        cout << "Protect: " << protect << endl; // Accessible due to inheritance
        cout << "Access: " << access << endl;   // Accessible due to inheritance
    }
};

int main() {
    Derived_Private dp1;
    Derived_Protected dp2;
    Derived_Public dp3;

    cout << "Derived_Private class:" << endl;
    dp1.show();

    cout << "\nDerived_Protected class:" << endl;
    dp2.show();

    cout << "\nDerived_Public class:" << endl;
    dp3.show();

    return 0;
}

