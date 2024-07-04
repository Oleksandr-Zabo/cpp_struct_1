#include <iostream>
#include <stdexcept> // для std::invalid_argument

// Реалізація функції gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Fraction {
    int numerator;
    int denominator;

    // Конструктор
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    // Функція для скорочення дробу
    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) { // Знак дробу завжди в чисельнику
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Функція для переведення неправильного дробу в простий
    void toMixed() const {
        int whole = numerator / denominator;
        int remainder = abs(numerator % denominator);
        if (whole != 0) {
            std::cout << whole << " ";
        }
        if (remainder != 0) {
            std::cout << remainder << "/" << denominator;
        }
        if (whole == 0 && remainder == 0) {
            std::cout << "0";
        }
        std::cout << std::endl;
    }
};

// Операції додавання, віднімання, множення та ділення
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Fraction(lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);
}

// Перевантаження оператора виводу
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

int main() {
    try {
        Fraction frac1(3, 4);
        Fraction frac2(2, 5);

        std::cout << "frac1: " << frac1 << std::endl;
        std::cout << "frac2: " << frac2 << std::endl;

        Fraction sum = frac1 + frac2;
        Fraction diff = frac1 - frac2;
        Fraction prod = frac1 * frac2;
        Fraction quot = frac1 / frac2;

        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Difference: " << diff << std::endl;
        std::cout << "Product: " << prod << std::endl;
        std::cout << "Quotient: " << quot << std::endl;

        std::cout << "Mixed form of sum: ";
        sum.toMixed();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
