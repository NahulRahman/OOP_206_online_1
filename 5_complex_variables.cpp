/*
A complex variable has a real portion and an imaginary portion.
a. Write down a class that represents a complex variable (all the members will
be private)
b. Write a public setter method to set the values.
c. Write a non-member function add(...) that will take two complex Variable
objects and print their summation
d. Write a non-member function sub(...) that will take two complex Variable
objects and print their subtraction.
*/
#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imaginary;
public:
    Complex() : real(0), imaginary(0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}
    void setComplex(double r, double i) {
        real = r;
        imaginary = i;
    }
    friend void add(Complex c1, Complex c2);
    friend void sub(Complex c1, Complex c2);
};

void add(Complex c1, Complex c2) {
    double real = c1.real + c2.real;
    double imaginary = c1.imaginary + c2.imaginary;
    cout << "Sum: " << real << " + " << imaginary << "i" << endl;
}

void sub(Complex c1, Complex c2) {
    double real = c1.real - c2.real;
    double imaginary = c1.imaginary - c2.imaginary;
    cout << "Difference: " << real << " + " << imaginary << "i" << endl;
}

int main() {
    Complex c1, c2;
    c1.setComplex(3.0, 4.0);
    c2.setComplex(1.0, 2.0);
    add(c1, c2);
    sub(c1, c2);
    return 0;
}
