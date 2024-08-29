#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Overloading the stream extraction operator >>
    friend istream &operator>>(istream &input, Complex &c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imaginary;
        return input;
    }

    // Overloading the stream insertion operator <<
    friend ostream &operator<<(ostream &output, const Complex &c) {
        output << c.real << " + " << c.imaginary << "i";
        return output;
    }
};

int main() {
    Complex com1;

    // Taking input for com1
    cin >> com1;

    // Printing the Complex number
    cout << "The Complex number is: " << com1 << endl;

    return 0;
}

