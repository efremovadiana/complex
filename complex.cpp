#include "complex.h"
#include <cmath>

complex::complex() : re(0), im(0) {}

complex::complex(double re_) : re(re_), im(0) {}

complex::complex(double re_, double im_) : re(re_), im(im_) {}

// Конструктор по модулю и аргументу (полярные координаты)

complex::complex(double r, double phi, bool polar)
{
    if (polar)
    {
        re = r * cos(phi);
        im = r * sin(phi);
    }
    else
    {
        re = r;
        im = phi;
    }
}


complex complex::conj() const
{
    return complex(re, -im);
}

double complex::abs() const
{
    return sqrt(re * re + im * im);
}

double complex::arg() const
{
    return atan2(im, re);
}

// Операции присваивания (complex)

complex& complex::operator += (const complex& other)
{
    re += other.re;
    im += other.im;
    return *this;
}

complex& complex::operator -= (const complex& other)
{
    re -= other.re;
    im -= other.im;
    return *this;
}

complex& complex::operator *= (const complex& other)
{

    double new_re = re * other.re - im * other.im;
    double new_im = re * other.im + im * other.re;
    re = new_re;
    im = new_im;
    return *this;
}

complex& complex::operator /= (const complex& other)
{

    double denom = other.re * other.re + other.im * other.im;
    double new_re = (re * other.re + im * other.im) / denom;
    double new_im = (im * other.re - re * other.im) / denom;
    re = new_re;
    im = new_im;
    return *this;
}

// Операции присваивания (double)

complex& complex::operator += (double val)
{
    re += val;
    return *this;
}

complex& complex::operator -= (double val)
{
    re -= val;
    return *this;
}

complex& complex::operator *= (double val)
{
    re *= val;
    im *= val;
    return *this;
}

complex& complex::operator /= (double val)
{
    re /= val;
    im /= val;
    return *this;
}

// Унарные операторы

complex complex::operator + () const
{
    return *this;
}

complex complex::operator - () const
{
    return complex(-re, -im);
}

// Бинарные операторы (complex-complex)

complex operator + (const complex& a, const complex& b)
{
    return complex(a.getRe() + b.getRe(), a.getIm() + b.getIm());
}

complex operator - (const complex& a, const complex& b)
{
    return complex(a.getRe() - b.getRe(), a.getIm() - b.getIm());
}

complex operator * (const complex& a, const complex& b)
{
    return complex(
        a.getRe() * b.getRe() - a.getIm() * b.getIm(),
        a.getRe() * b.getIm() + a.getIm() * b.getRe()
    );
}

complex operator / (const complex& a, const complex& b)
{
    double denom = b.getRe() * b.getRe() + b.getIm() * b.getIm();
    return complex(
        (a.getRe() * b.getRe() + a.getIm() * b.getIm()) / denom,
        (a.getIm() * b.getRe() - a.getRe() * b.getIm()) / denom
    );
}

// Операторы с double

complex operator + (const complex& a, double b)
{
    return complex(a.getRe() + b, a.getIm());
}

complex operator + (double a, const complex& b)
{
    return complex(a + b.getRe(), b.getIm());
}

complex operator - (const complex& a, double b)
{
    return complex(a.getRe() - b, a.getIm());
}

complex operator - (double a, const complex& b)
{
    return complex(a - b.getRe(), -b.getIm());
}

complex operator * (const complex& a, double b)
{
    return complex(a.getRe() * b, a.getIm() * b);
}

complex operator * (double a, const complex& b)
{
    return complex(a * b.getRe(), a * b.getIm());
}

complex operator / (const complex& a, double b)
{
    return complex(a.getRe() / b, a.getIm() / b);
}

complex operator / (double a, const complex& b)
{
    double denom = b.getRe() * b.getRe() + b.getIm() * b.getIm();
    return complex(
        (a * b.getRe()) / denom,
        (-a * b.getIm()) / denom
    );
}

// Ввод/вывод

std::ostream& operator << (std::ostream& os, const complex& c)
{
    double re = c.getRe();
    double im = c.getIm();

    os << re;
    if (im >= 0)
        os << " + " << im << "i";
    else
        os << " - " << -im << "i";
    return os;
}

std::istream& operator >> (std::istream& is, complex& c)
{
    double re, im;
    is >> re >> im;
    c = complex(re, im);
    return is;
}
