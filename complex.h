#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

class complex
{
public:

    complex();
    complex(double re);
    complex(double re, double im);
    complex(double r, double phi, bool polar);


    double getRe() const { return re; }
    double getIm() const { return im; }


    complex conj() const;
    double abs() const;
    double arg() const;


    complex& operator += (const complex& other);
    complex& operator -= (const complex& other);
    complex& operator *= (const complex& other);
    complex& operator /= (const complex& other);

    complex& operator += (double val);
    complex& operator -= (double val);
    complex& operator *= (double val);
    complex& operator /= (double val);


    complex operator + () const;
    complex operator - () const;

private:
    double re;
    double im;
};


complex operator + (const complex& a, const complex& b);
complex operator - (const complex& a, const complex& b);
complex operator * (const complex& a, const complex& b);
complex operator / (const complex& a, const complex& b);


complex operator + (const complex& a, double b);
complex operator + (double a, const complex& b);
complex operator - (const complex& a, double b);
complex operator - (double a, const complex& b);
complex operator * (const complex& a, double b);
complex operator * (double a, const complex& b);
complex operator / (const complex& a, double b);
complex operator / (double a, const complex& b);


std::ostream& operator << (std::ostream& os, const complex& c);
std::istream& operator >> (std::istream& is, complex& c);

#endif // COMPLEX_H_INCLUDED
