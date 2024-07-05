#include <iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imag;

    // Constructor
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    // Addition
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Subtraction
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Multiplication
    ComplexNumber operator*(const ComplexNumber& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return ComplexNumber(r, i);
    }

    // Division
    ComplexNumber operator/(const ComplexNumber& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return ComplexNumber(r, i);
    }
};

int main() {
    ComplexNumber z1(2, 3); // 2 + 3i
    ComplexNumber z2(1, -2); // 1 - 2i

    //Display numbers
    cout << "Number 1: " << z1.real << " + " << z1.imag << "i" << endl;

    cout << "Number 2: " << z2.real << " + " << z2.imag << "i" << endl;

    // Perform arithmetic operations
    ComplexNumber sum = z1 + z2;

    ComplexNumber diff = z1 - z2;

    ComplexNumber product = z1 * z2;

    ComplexNumber quotient = z1 / z2;

    // Display results
    cout << "Sum: " << sum.real << " + " << sum.imag << "i" << endl;

    cout << "Difference: " << diff.real << " + " << diff.imag << "i" << endl;
    
    cout << "Product: " << product.real << " + " << product.imag << "i" << endl;
    
    cout << "Quotient: " << quotient.real << " + " << quotient.imag << "i" << endl;

    return 0;
}
