#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    int real, imag;

public:
    int getReal() { return real; }
    int getImag() { return imag; }
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& b) const
    {
        Complex z(real + b.real, imag + b.imag);
        return z;
    }
    Complex operator-(const Complex& b) const
    {
        return Complex(real - b.real, imag - b.imag);
    }
    //(a + bi)(c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& b) const
    {
        Complex z(real * b.real - b.imag * imag, real * b.imag + imag * b.real);
        return z;
    }
    Complex operator/(const Complex& b) const
    {
        int x = ((real * (b.real)) + (imag * (b.imag))) / (pow(b.real, 2) + pow(b.imag, 2));
        int y = ((real * imag) - (real * (b.imag))) / (pow(b.real, 2) + pow(b.imag, 2));
        Complex z(x, y);
        return z;
    }
    Complex& operator+=(const Complex& b)
    {
        this->real += b.real;
        this->imag += b.imag;
        return *this;
    }
    Complex& operator-=(const Complex& b)
    {
        this->real -= b.real;
        this->imag -= b.imag;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Complex& z);
};

ostream& operator<<(ostream& os, const Complex& z)
{
    if (z.imag >= 0)
        os << z.real << " + " << z.imag << "i";
    else
    {
        os << z.real << " - " << z.imag << "i";
    }
    return os;
}

int main()
{
    cout << "Tao cac so phuc B(1, 2), C(3, 4), D(5, 6), E(7, 8) " << endl;
    Complex A, B(1, 2), C(3, 4), D(5, 6), E(7, 8);
    B += C;
    cout << "B += C; B = " << B << endl;
    cout << "A =  B*C + (D-E)" << endl;
    A = B * C + (D - E);
    cout << "A = " << A;
}