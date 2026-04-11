#include <iostream>
#include "complex.h"
#include "clocale"

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");

    // Тест конструкторов
    complex c1;
    complex c2(3.0);
    complex c3(1.0, 2.0);
    complex c4(5.0, 3.14159/2, true);

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = " << c3 << std::endl;
    std::cout << "c4 = " << c4 << std::endl;

    // Тест методов
    std::cout << "\nМетоды для c3 = " << c3 << ":" << std::endl;
    std::cout << "  Re = " << c3.getRe() << std::endl;
    std::cout << "  Im = " << c3.getIm() << std::endl;
    std::cout << "  Conj = " << c3.conj() << std::endl;
    std::cout << "  Abs = " << c3.abs() << std::endl;
    std::cout << "  Arg = " << c3.arg() << " rad" << std::endl;

    // Тест арифметики
    complex a(2, 3);
    complex b(4, -1);

    std::cout << "\na = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    // Тест с double
    std::cout << "\na + 5 = " << (a + 5) << std::endl;
    std::cout << "2 * a = " << (2 * a) << std::endl;
    std::cout << "a / 2 = " << (a / 2) << std::endl;

    // Тест операторов присваивания
    complex c = a;
    c += b;
    std::cout << "\na += b: " << c << std::endl;

    c *= 2;
    std::cout << "c *= 2: " << c << std::endl;

    // Тест унарных операторов
    std::cout << "\n+a = " << (+a) << std::endl;
    std::cout << "-a = " << (-a) << std::endl;


    return 0;
}
