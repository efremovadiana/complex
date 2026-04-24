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

    // Тест: оператор -= для double
    std::cout << "\nТест: complex -= double " << std::endl;

    complex auto_test1(10.0, 5.0);
    auto_test1 -= 3.0;

    if (auto_test1.getRe() == 7.0 && auto_test1.getIm() == 5.0) {
        std::cout << "Успех: (10+5i) -= 3.0  (7+5i)" << std::endl;
    } else {
        std::cerr << "Ошибка: Ожидали (7, 5), получили ("
                  << auto_test1.getRe() << ", " << auto_test1.getIm() << ")" << std::endl;
        return 1;
    }

    complex auto_test2(4.0, -2.0);
    auto_test2 -= (-1.0);

    if (auto_test2.getRe() == 5.0 && auto_test2.getIm() == -2.0) {
        std::cout << "Успех: (4-2i) -= (-1.0) (5-2i)" << std::endl;
    } else {
        std::cerr << "Ошибка: Ожидали (5, -2), получили ("
                  << auto_test2.getRe() << ", " << auto_test2.getIm() << ")" << std::endl;
        return 1;
    }

    return 0;
}
