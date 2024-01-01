#include <iostream>
#include <cmath>
class Fraction {
private:
int numerator;
int denominator;
int gcd(int a, int b) { // Greatest common divisor
return b == 0? a: gcd(b, a % b);
}
void simplify() {   // Define the simplify function
int common = gcd(std::abs(numerator), denominator);
numerator /= common;
denominator /= common;
if (denominator < 0) {
numerator = -numerator;
denominator = -denominator;
}
}
public:
// Constructors
Fraction(): numerator(0), denominator(1) {}
Fraction(int num, int den): numerator(num), denominator(den) {
simplify();
}
int getNumerator() const {
return numerator;
}
int getDenominator() const {
return denominator;
}
void setNumerator(int numer) {
numerator = numer;
simplify();
}
void setDenominator(int deno) {
if (deno != 0) {
denominator = deno;
simplify();
} 
}
// Overloaded arithmetic operators
Fraction operator+(const Fraction& second) const {
return Fraction(numerator * second.denominator + second.numerator * denominator,
denominator * second.denominator);
}
Fraction operator-(const Fraction& second) const {
return Fraction(numerator *second.denominator - second.numerator * denominator,
denominator * second.denominator);
}
Fraction operator*(const Fraction& second) const {
return Fraction(numerator * second.numerator, denominator * second.denominator);
}
Fraction operator/(const Fraction& second) const {
if (second.numerator != 0) {
return Fraction(numerator * second.denominator, denominator * second.numerator);
} else {
std::cerr << "Error: Division by zero.\n";
return Fraction(); // Return a default-constructed fraction
}
}
// Overloaded compound assignment operators
Fraction& operator+=(const Fraction& second) {
numerator = numerator * second.denominator +second.numerator * denominator;
denominator *= second.denominator;
simplify();
return *this;
}
Fraction& operator-=(const Fraction& second) {
numerator = numerator * second.denominator - second.numerator * denominator;
denominator *= second.denominator;
simplify();
return *this;
}
Fraction& operator*=(const Fraction& second) {
numerator *= second.numerator;
denominator *= second.denominator;
simplify();
return *this;
}
Fraction& operator/=(const Fraction& second) {
if (second.numerator != 0) {
numerator *= second.denominator;
denominator *= second.numerator;
simplify();
} 
return *this;
}
// Overloaded insertion and extraction operators
friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
os << fraction.numerator;
if (fraction.denominator != 1) {
os << '/' << fraction.denominator;
}
return os;
}
friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
is >> fraction.numerator;
is >> fraction.denominator;
fraction.simplify();
return is;
}
// Function to convert the fraction into double
double Double() const {
return static_cast<double>(numerator) / denominator;
}
};
int main() {
Fraction frac1(1, 2);
Fraction frac2(2, 3);
std::cout << "Fraction 1: " << frac1 << '\n';
std::cout << "Fraction 2: " << frac2 << '\n';
Fraction sum = frac1 + frac2;
std::cout << "Sum: " << sum << " (" << sum.Double() << ")" << '\n';
Fraction difference = frac1 - frac2;
std::cout << "Difference: " << difference << " (" << difference.Double() << ")" << '\n';
Fraction product = frac1 * frac2;
std::cout << "Product: " << product << " (" << product.Double() << ")" << '\n';
Fraction quotient = frac1 / frac2;
std::cout << "Quotient: " << quotient << " (" << quotient.Double() << ")" << '\n';
return 0;
}