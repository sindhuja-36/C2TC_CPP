
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, result;
    int choice;

    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Compare\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = c1 + c2;
                cout << "Addition: " << result << endl;
                break;
            case 2:
                result = c1 - c2;
                cout << "Subtraction: " << result << endl;
                break;
            case 3:
                result = c1 * c2;
                cout << "Multiplication: " << result << endl;
                break;
            case 4:
                if (c1 == c2)
                    cout << "Both complex numbers are equal.\n";
                else
                    cout << "Complex numbers are not equal.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
