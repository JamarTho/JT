/***********************************************************************************
* Jamar Thomas Jr                                                                  *
* CMPS 2143 - Program 1                                                            *
* Dr. Griffin                                                                      *      
* This program will read in from a file of fractions and perform arithmetic        *
* operations on them. Along with overloading the operators, so that they may be    * 
*  used multiple ways.                                                             *  
************************************************************************************/
  
#include <iostream>
#include <stdexcept>
#include <numeric>

//Class that defines the fraction and its arithmaetic operations.
class Fraction {
private:
    int numerator;
    int denominator;

    // Function to calculate Least Common Denominator (LCD)
    int lcd(int a, int b) {
        return (a * b) / lcd(a, b);
    }

public:
    // Constructor
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        // Normalize fraction (e.g., -1/2 instead of 1/-2)
        if (den < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Overloaded addition operator
    Fraction operator+(const Fraction& other) {
        int lcmDenom = lcd(denominator, other.denominator);
        int newNumerator = (numerator * (lcmDenom / denominator)) +
                           (other.numerator * (lcmDenom / other.denominator));
        return Fraction(newNumerator, lcmDenom);
    }

    // Overloaded subtraction operator
    Fraction operator-(const Fraction& other) {
        int lcmDenom = lcd(denominator, other.denominator);
        int newNumerator = (numerator * (lcmDenom / denominator)) -
                           (other.numerator * (lcmDenom / other.denominator));
        return Fraction(newNumerator, lcmDenom);
    }

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Overloaded division operator
    Fraction operator/(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded equality operator (==)
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    // Overload output operator (<<) for printing fractions
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

int main() 
{
        Fraction frac1(1, 2);
        Fraction frac2(3, 4);

        Fraction sum = frac1 + frac2;
        std::cout << frac1 << " + " << frac2 << " = " << sum << std::endl;

        Fraction diff = frac1 - frac2;
        std::cout << frac1 << " - " << frac2 << " = " << diff << std::endl;

        Fraction prod = frac1 * frac2;
        std::cout << frac1 << " * " << frac2 << " = " << prod << std::endl;

        Fraction quot = frac1 / frac2;
        std::cout << frac1 << " / " << frac2 << " = " << quot << std::endl;

        std::cout << "Are they equal? " << (frac1 == frac2 ? "Yes" : "No") << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
};




