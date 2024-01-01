#include <iostream>
class Vector {
private:
    double* elements;
    size_t size;
public:
    // Constructors
    Vector() : elements(nullptr), size(0) {}
    Vector(const double* elems, size_t s) : size(s) {
        elements = new double[size];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = elems[i];
        }
    }
    // Destructor
    ~Vector() {
        delete[] elements;
    }
    Vector(const Vector& other) : size(other.size) {
        elements = new double[size];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new double[size];
            for (size_t i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    // Getters and Setters
    const double* getElements() const {
        return elements;
    }
    size_t getSize() const {
        return size;
    }
    // Overloaded operators
    Vector& operator+=(const Vector& other) {
        size_t minSize = std::min(size, other.size);
        for (size_t i = 0; i < minSize; ++i) {
            elements[i] += other.elements[i];
        }
        return *this;
    }
    Vector& operator-=(const Vector& other) {
        size_t minSize = std::min(size, other.size);
        for (size_t i = 0; i < minSize; ++i) {
            elements[i] -= other.elements[i];
        }
        return *this;
    }
    Vector& operator*=(double scalar) {
        for (size_t i = 0; i < size; ++i) {
            elements[i] *= scalar;
        }
        return *this;
    }
    // Scalar product 
    double operator*(const Vector& other) const {
        double result = 0.0;
        size_t minSize = std::min(size, other.size);
        for (size_t i = 0; i < minSize; ++i) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }
    // Overloading the << operator
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
        os << "(";
        for (size_t i = 0; i < vector.size; ++i) {
            os << vector.elements[i];
            if (i < vector.size - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
    // Overloading the >> operator
    friend std::istream& operator>>(std::istream& is, Vector& vector) {
        char ch;
        double element;
        is >> ch; // Read the opening parenthesis
        delete[] vector.elements;
        vector.size = 0;
        vector.elements = nullptr;
        while (is >> element) {
            double* newElements = new double[vector.size + 1];
            for (size_t i = 0; i < vector.size; ++i) {
                newElements[i] = vector.elements[i];
            }
            newElements[vector.size++] = element;
            delete[] vector.elements;
            vector.elements = newElements;
            is >> ch; // Read the comma or closing parenthesis
            if (ch == ')') {
                break;
            }
        }
        return is;
    }
};
// Overloaded operators for arithmetic operations
Vector operator+(const Vector& a, const Vector& b) {
    Vector result = a;
    result += b;
    return result;
}
Vector operator-(const Vector& a, const Vector& b) {
    Vector result = a;
    result -= b;
    return result;
}
Vector operator*(const Vector& vector, double scalar) {
    Vector result = vector;
    result *= scalar;
    return result;
}
Vector operator*(double scalar, const Vector& vector) {
    return vector * scalar;
}
int main() {
    
    double array1[] = {1.0, 2.0, 3.0};
    double array2[] = {4.0, 5.0, 6.0};
    Vector vector1(array1, 3);
    Vector vector2(array2, 3);
    std::cout<<"vector1 "<<vector1<<"  ||  ";
    std::cout<<"vector2 "<<vector2<<'\n';
    // Addition
    Vector addition =vector1 + vector2;
    std::cout << "Addition: " << addition << '\n';
    // Subtraction
    Vector subtraction= vector1 - vector2;
    std::cout << "Subtraction: " << subtraction << '\n';
    // Multiplication with a number
    Vector multipliedbynumber1 = vector1 *2.0;
    std::cout << "Vector1 multiplied by number 2 : " <<  multipliedbynumber1  << '\n';
    Vector multipliedbynumber2 = vector2 *2.0;
    std::cout << "Vector2 multiplied by number 2 : " <<  multipliedbynumber2  << '\n';
    // Scalar produc
    double scalarProduct = vector1 * vector2;
    std::cout << "Scalar Product: " << scalarProduct << '\n';
    return 0;
}
