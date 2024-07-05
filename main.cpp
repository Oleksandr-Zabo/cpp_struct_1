#include <iostream>
using namespace std;

// Function to calculate the greatest common divisor (GCD)
int my_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Fraction {
private:
    int _numerator;
    int _denominator;

public:
    Fraction() {
        _numerator = 0;
        _denominator = 1;
    }

    Fraction(int numerator) : Fraction() {
        setNumerator(numerator);
    }

    Fraction(int numerator, int denominator) : Fraction(numerator) {
        setDenominator(denominator);
    }

    // Getters
    int getNumerator() { return _numerator; }
    int getDenominator() { return _denominator; }

    // Setters
    void setNumerator(int numerator) {
        _numerator = numerator;
    }

    void setDenominator(int denominator) {
        if (denominator != 0) {
            _denominator = denominator;
        }
        else {
            cout << "Incorrect denominator (0)" << endl;
        }

        reduce();
    }

    // Function to reduce fraction
    void reduce() {
        int gcdValue = my_gcd(_numerator, _denominator);
        _numerator /= gcdValue;
        _denominator /= gcdValue;
        if (_denominator < 0) {
            _numerator = -_numerator;
            _denominator = -_denominator;
        }
    }

    // Function to transform incorrect fraction to mixed form 
    // and print result
    void toMixed() const {
        int whole = _numerator / _denominator;
        int remainder = abs(_numerator % _denominator);
        if (whole != 0) {
            cout << whole << " ";
        }
        if (remainder != 0) {
            cout << remainder << "/" << _denominator;
        }
        if (whole == 0 && remainder == 0) {
            cout << "0";
        }
        cout << endl << endl;
    }

    // Function to calculate the difference of two fractions
    Fraction Dif(Fraction otherFraction) {
        int n = getNumerator() * otherFraction.getDenominator() - otherFraction.getNumerator() * getDenominator();
        int d = getDenominator() * otherFraction.getDenominator();
        return Fraction(n / my_gcd(n, d), d / my_gcd(n, d));
    }

    // Function to calculate the sum of two fractions
    Fraction Sum(Fraction otherFraction) {
        int n = getNumerator() * otherFraction.getDenominator() + otherFraction.getNumerator() * getDenominator();
        int d = getDenominator() * otherFraction.getDenominator();
        return Fraction(n / my_gcd(n, d), d / my_gcd(n, d));
    }

    // Function to calculate the multiplication of two fractions
    Fraction Mulp(Fraction otherFraction) {
        int n = getNumerator() * otherFraction.getNumerator();
        int d = getDenominator() * otherFraction.getDenominator();
        return Fraction(n / my_gcd(n, d), d / my_gcd(n, d));
    }

    // Function to calculate the division of two fractions
    Fraction Div(Fraction otherFraction) {
        int n = getNumerator() * otherFraction.getDenominator();
        int d = getDenominator() * otherFraction.getNumerator();
        return Fraction(n / my_gcd(n, d), d / my_gcd(n, d));
    }
};

void print_fraction(Fraction frac) {

    frac.toMixed();// Display the fraction as a mixed fraction
}

void sum_fractions(Fraction frac1, Fraction frac2) {
    
    Fraction sumResult = frac1.Sum(frac2);

    cout << "Sum: ";
    sumResult.toMixed(); // Display the result as a mixed fraction
}

void dif_fractions(Fraction frac1, Fraction frac2) {

    Fraction difResult = frac1.Dif(frac2);

    cout << "Difference: ";
    difResult.toMixed(); // Display the result as a mixed fraction
}

void mulp_fractions(Fraction frac1, Fraction frac2) {

    Fraction mulpResult = frac1.Mulp(frac2);

    cout << "Multiplication: ";
    mulpResult.toMixed(); // Display the result as a mixed fraction
}

void div_fractions(Fraction frac1, Fraction frac2) {

    Fraction divResult = frac1.Div(frac2);

    cout << "Division: ";
    divResult.toMixed(); // Display the result as a mixed fraction
}



int main() {
    Fraction frac1(4, 5);
    Fraction frac2(2, 5);

    cout << "Frac 1: ";
    print_fraction(frac1);

    cout << "Frac 2: ";
    print_fraction(frac2);

    sum_fractions(frac1, frac2);

    dif_fractions(frac1, frac2);

    mulp_fractions(frac1, frac2);

    div_fractions(frac1, frac2);
    return 0;
}
