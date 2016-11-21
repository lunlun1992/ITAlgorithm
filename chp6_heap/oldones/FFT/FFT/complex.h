#ifndef COMPLEX_H
#define COMPLEX_H
#include "common.h"
class Complex
{
private:
	double real;
	double imag;
public:
	Complex(double r, double i);
	~Complex();
	double norm();
	Complex operator+(const Complex &rhs);
	Complex operator-(const Complex &rhs);
	Complex operator*(const Complex &lhs);
	Complex operator/(const Complex &lhs);
	friend ostream &operator<<(ostream &os, const Complex &c)
	{
		os << "(" << setprecision(10) << std::fixed << c.real << "," << setprecision(10) << std::fixed <<  c.imag << ")";
		return os;
	}
};
#endif
