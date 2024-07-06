#include <iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imag;

    // Constructor
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    // Addition
    ComplexNumber Sum(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Subtraction
    ComplexNumber Dif(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Multiplication
    ComplexNumber Mulp(const ComplexNumber& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return ComplexNumber(r, i);
    }

    // Division
    ComplexNumber Div(const ComplexNumber& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return ComplexNumber(r, i);
    }
};

void sum_complex(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber sumResult = z1.Sum(z2);
    cout << "Sum: " << sumResult.real << " + " << sumResult.imag << "i" << endl;
}

void dif_complex(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber difResult = z1.Dif(z2);
    cout << "Difference: " << difResult.real << " + " << difResult.imag << "i" << endl;
}

void mulp_complex(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber mulpResult = z1.Mulp(z2);
    cout << "Product: " << mulpResult.real << " + " << mulpResult.imag << "i" << endl;
}

void div_complex(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber divResult = z1.Div(z2);
    cout << "Quotient: " << divResult.real << " + " << divResult.imag << "i" << endl;
}

int main() {
    ComplexNumber z1(2, 3); // 2 + 3i
    ComplexNumber z2(1, -2); // 1 - 2i

    //Display numbers
    cout << "Number 1: " << z1.real << " + " << z1.imag << "i" << endl;

    cout << "Number 2: " << z2.real << " + " << z2.imag << "i" << endl;


    // Display results
    sum_complex(z1, z2);

    dif_complex(z1, z2);

    mulp_complex(z1, z2);

    div_complex(z1, z2);

    return 0;
}
