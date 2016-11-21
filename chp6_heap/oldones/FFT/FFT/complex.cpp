#include "complex.h"

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex::~Complex()
{

}
Complex Complex::operator+(const Complex &rhs)
{
	return Complex(rhs.real + real, imag + rhs.imag);
}
Complex Complex::operator-(const Complex &rhs)
{
	return Complex(real - rhs.real, imag - rhs.imag);
}
Complex Complex::operator*(const Complex &rhs)
{
	double r = rhs.real * real - rhs.imag * imag;
	double i = rhs.real * imag + rhs.imag * real;
	return Complex(r, i);
}

double Complex::norm()
{
	return sqrt(real * real + imag * imag);
}
